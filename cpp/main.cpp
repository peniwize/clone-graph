/*!
    \file "main.cpp"

    Author: Matt Ervin <matt@impsoftware.org>
    Formatting: 4 spaces/tab (spaces only; no tabs), 120 columns.
    Doc-tool: Doxygen (http://www.doxygen.com/)

    https://leetcode.com/problems/clone-graph/
*/

//!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/main.md
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) { return nullptr; }

        unordered_map<int, Node*> clones{};
        deque<tuple<Node*, Node*>> que{};
        
        auto cloneGraphRoot = new Node{node->val};
        clones.insert(make_pair(cloneGraphRoot->val, cloneGraphRoot));

        que.emplace_back(make_tuple(node, cloneGraphRoot));
        while (!que.empty()) {
            auto [node, clone] = que.front();
            que.pop_front();
            for (auto* neighbor : node->neighbors) {
                auto findIter = clones.find(neighbor->val);
                auto const neighborCloneExists = clones.end() != findIter;
                if (neighborCloneExists) {
                    // Add existing neighbor clone to clone.
                    Node* neighborClone = findIter->second;
                    clone->neighbors.push_back(std::move(neighborClone));
                } else {
                    // Clone node neighbor and add neighbor clone to clone's neighbors.
                    auto neighborClone = new Node{neighbor->val};
                    clones.insert(make_pair(neighborClone->val, neighborClone));
                    clone->neighbors.push_back(std::move(neighborClone));

                    // Visit neighbor's neighbors.
                    que.emplace_back(make_tuple(neighbor, neighborClone));
                }
            }
        }

        return cloneGraphRoot;
    }
};

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

namespace doctest {
    const char* testName() noexcept { return doctest::detail::g_cs->currentTest->m_name; }
} // namespace doctest {

static Node* createGraphFromEdgeList(vector<vector<int>> const& edgeList)
{
    Node* root{};

    // For each edge in the edge list:
    unordered_map<int, Node*> nodes{};
    int edgeListIdx = 1;
    for (auto const& edge : edgeList)
    {
        // Create or fetch edge node.
        Node* node{};
        auto nodesIter = nodes.find(edgeListIdx);
        bool const nodeExists = nodes.end() != nodesIter;
        if (nodeExists)
        {
            // Fetch existing node.
            node = nodesIter->second;
        }
        else
        {
            // Create a new node.
            node = new Node{edgeListIdx};
            nodes.insert(make_pair(node->val, node));
        }
        ++edgeListIdx;

        if (!root) { root = node; }

        // For each vertex in the edge:
        for (auto const vertex : edge)
        {
            Node* neighbor{};

            // Create or fetch vertex node.
            auto nodesIter = nodes.find(vertex);
            bool const neighborExists = nodes.end() != nodesIter;
            if (neighborExists)
            {
                // Fetch existing node.
                neighbor = nodesIter->second;
            }
            else
            {
                // Create new node.
                neighbor = new Node{vertex};
                nodes.insert(make_pair(neighbor->val, neighbor));
            }

            node->neighbors.push_back(neighbor);
        }
    }
    
    return root;
}

static void deleteGraph(Node* graph)
{
    if (graph)
    {
        unordered_map<int, unique_ptr<Node>> nodes{};
        deque<Node*> que{};
        nodes.insert(make_pair(graph->val, graph));
        que.emplace_back(std::move(graph));
        while (!que.empty())
        {
            Node* node = que.front();
            que.pop_front();
            for (auto* neighbor : node->neighbors)
            {
                bool const unvisited = nodes.end() == nodes.find(neighbor->val);
                if (unvisited)
                {
                    nodes.insert(make_pair(neighbor->val, neighbor));
                    que.push_back(neighbor);
                }
            }
        }
    }
}

static vector<vector<int>> toEdgeList(Node const* graph)
{
    vector<vector<int>> result{};

    if (graph)
    {
        map<int, vector<int>> edgeList{};

        unordered_map<int, Node const*> nodes{};
        deque<Node const*> que{};
        que.emplace_back(graph);
        nodes.insert(make_pair(graph->val, graph));
        while (!que.empty())
        {
            auto* node = que.front();
            que.pop_front();

            vector<int>* vertices{};
            auto edgeListIter = edgeList.find(node->val);
            if (edgeList.end() == edgeListIter)
            {
                edgeList.insert(make_pair(node->val, vector<int>{}));
                vertices = &edgeList[node->val];
            }
            else
            {
                vertices = &edgeListIter->second;
            }

            for (auto const* neighbor : node->neighbors)
            {
                vertices->push_back(neighbor->val);

                bool const unvisited = nodes.end() == nodes.find(neighbor->val);
                if (unvisited)
                {
                    que.push_back(neighbor);
                    nodes.insert(make_pair(neighbor->val, neighbor));
                }
            }
        }

        // Create result from edge list.
        int firstEdge = 1;
        for (auto& edge : edgeList)
        {
            int fillCount = edge.first - firstEdge;
            fill_n(result.end(), fillCount, vector<int>{});
            firstEdge = edge.first + 1;

            result.emplace_back(std::move(edge.second));
        }

        // Sort edges (to make future comparisons easier).
        for (auto& vertices : result)
        {
            sort(vertices.begin(), vertices.end());
        }
    }
    
    return result;
}

static bool graphsAreEquivalent(Node const* graph1, Node const* graph2)
{
    auto edgeList1 = toEdgeList(graph1);
    auto edgeList2 = toEdgeList(graph2);
    return edgeList1 == edgeList2;
}

TEST_CASE("Case 1")
{
    cerr << doctest::testName() << '\n';
    auto edgeList = vector<vector<int>>{
        {2,4},
        {1,3},
        {2,4},
        {1,3}
    };
    auto* graph = createGraphFromEdgeList(edgeList);
    auto solution = Solution{};
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result = solution.cloneGraph(graph);
        CHECK(graphsAreEquivalent(graph, result));
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    deleteGraph(graph);
    cerr << "\n";
}

TEST_CASE("Case 2")
{
    cerr << doctest::testName() << '\n';
    auto edgeList = vector<vector<int>>{
        {},
    };
    auto* graph = createGraphFromEdgeList(edgeList);
    auto solution = Solution{};
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result = solution.cloneGraph(graph);
        CHECK(graphsAreEquivalent(graph, result));
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    deleteGraph(graph);
    cerr << "\n";
}

TEST_CASE("Case 3")
{
    cerr << doctest::testName() << '\n';
    auto edgeList = vector<vector<int>>{
    };
    auto* graph = createGraphFromEdgeList(edgeList);
    auto solution = Solution{};
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result = solution.cloneGraph(graph);
        CHECK(graphsAreEquivalent(graph, result));
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    deleteGraph(graph);
    cerr << "\n";
}

/*
    End of "main.cpp"
*/
