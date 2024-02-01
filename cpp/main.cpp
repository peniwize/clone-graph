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
        
//
//!\todo TODO: >>> Under Construction <<<
//
return nullptr;

    }
};

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

namespace doctest {
    const char* testName() noexcept { return doctest::detail::g_cs->currentTest->m_name; }
} // namespace doctest {

static Node* makeGraph(vector<vector<int>> const& edgeList)
{

//
//!\todo TODO: >>> Under Construction <<<
//
return nullptr;

}

static void deleteGraph(Node* graph)
{

//
//!\todo TODO: >>> Under Construction <<<
//

}

static bool graphsAreEquivalent(Node const* graph1, Node const* graph2)
{

//
//!\todo TODO: >>> Under Construction <<<
//
return false;

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
    auto* graph = makeGraph(edgeList);
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
    auto* graph = makeGraph(edgeList);
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
    auto* graph = makeGraph(edgeList);
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
