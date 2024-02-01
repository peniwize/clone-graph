# Start of "solution.py".

from collections import deque
import inspect
import time
from typing import List
from typing import Optional
from typing import Set

"""
    Given a reference of a node in a connected undirected graph.

    Return a deep copy (clone) of the graph.

    Each node in the graph contains a value (int) and a 
    list (List[Node]) of its neighbors.

    class Node {
        public int val;
        public List<Node> neighbors;
    }

    Test case format:

    For simplicity, each node's value is the same as the 
    node's index (1-indexed). For example, the first node with val == 1, 
    the second node with val == 2, and so on. The graph is represented in 
    the test case using an adjacency list.

    An adjacency list is a collection of unordered lists used to represent 
    a finite graph. Each list describes the set of neighbors of a node in 
    the graph.

    The given node will always be the first node with val = 1. You must return 
    the copy of the given node as a reference to the cloned graph.

    Constraints:

        * The number of nodes in the graph is in the range [0, 100].
        * 1 <= Node.val <= 100
        * Node.val is unique for each node.
        * There are no repeated edges and no self-loops in the graph.
        * The Graph is connected and all nodes can be visited starting from the given node.
"""

class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

"""
    Depth first search recursive solution.

    Time = O(V + E)
           V = number of nodes in the graph (length of adjacency list).
           E = number of edges in the graph (sum(adjacency sub-list lengths)).

    Space = O(V)
            V occurs when the graph is a straight line (each vertex connects
            to the next with none skipped).  Recursion will occur as many 
            times as there are vertices.
"""
class Solution1_DFS:
    def __init__(self):
        self.nodes = {}

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if None == node: return node
        if node.val in self.nodes: return self.nodes[node.val]
        newNode = Node(node.val)
        self.nodes[newNode.val] = newNode
        for neighbor in node.neighbors:
            newNode.neighbors.append(self.cloneGraph(neighbor))
        return newNode

"""
    Breadth first search solution.

    Time = O(V + E)
           V = number of nodes in the graph (length of adjacency list).
           E = number of edges in the graph (sum(adjacency sub-list lengths)).

    Space = O(V)
            V occurs when the graph is complete (all verticies connect to all
            other verticies).
"""
class Solution1_BFS:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if None == node: return node
        
        que = deque()
        visited = {}

        clonedRootNode = Node(node.val)
        visited[clonedRootNode.val] = clonedRootNode

        que.append((clonedRootNode, node))
        while 0 < len(que):
            clonedNode, originalNode = que.popleft()
            for neighbor in originalNode.neighbors:
                if neighbor.val not in visited:
                    neighborClone = Node(neighbor.val)
                    visited[neighborClone.val] = neighborClone
                    que.append((neighborClone, neighbor))
                    clonedNode.neighbors.append(neighborClone)
                else:
                    clonedNode.neighbors.append(visited[neighbor.val])

        return clonedRootNode

def toGraph(adjList: []):
    if 0 == len(adjList): return None
    nodes = {}
    for nodeVal in range(1, len(adjList) + 1):
        if nodeVal not in nodes:
            nodes[nodeVal] = Node(nodeVal)
        for neighbor in adjList[nodeVal - 1]:
            if neighbor not in nodes:
                nodes[neighbor] = Node(neighbor)
            nodes[nodeVal].neighbors.append(nodes[neighbor])
    return nodes[1]

def toAdjacencyList(graphRootNode: Node) -> []:
    adjList = []
    if graphRootNode:
        nodes = {}
        que = deque()
        que.append(graphRootNode)
        nodes[graphRootNode.val] = []
        while 0 < len(que):
            for _ in range(len(que)):
                node = que.popleft()
                for neighbor in node.neighbors:
                    nodes[node.val].append(neighbor.val)
                    if neighbor.val not in nodes:
                        que.append(neighbor)
                        nodes[neighbor.val] = []
        nodeKeys = list(nodes.keys())
        nodeKeys.sort()
        for key in nodeKeys:
            adjNodes = nodes[key]
            adjNodes.sort()
            adjList.append(adjNodes)
    return adjList

def graphsAreEquivalent(graph1: Optional['Node'], graph2: Optional['Node']) -> bool:
    adjList1 = toAdjacencyList(graph1)
    adjList2 = toAdjacencyList(graph2)
    result = adjList1 == adjList2
    return result

def test1(solution):
    adjList = [
        [2,4],
        [1,3],
        [2,4],
        [1,3]
    ]
    startTime = time.time()
    graph = toGraph(adjList)
    result = solution.cloneGraph(graph)
    endTime = time.time()
    print("{}:{}({:.6f} sec) result = {}".format(inspect.currentframe().f_code.co_name, type(solution), endTime - startTime, result))
    assert(graphsAreEquivalent(graph, result))

def test2(solution):
    adjList = [
        [],
    ]
    startTime = time.time()
    graph = toGraph(adjList)
    result = solution.cloneGraph(graph)
    endTime = time.time()
    print("{}:{}({:.6f} sec) result = {}".format(inspect.currentframe().f_code.co_name, type(solution), endTime - startTime, result))
    assert(graphsAreEquivalent(graph, result))

def test3(solution):
    adjList = [
    ]
    startTime = time.time()
    graph = toGraph(adjList)
    result = solution.cloneGraph(graph)
    endTime = time.time()
    print("{}:{}({:.6f} sec) result = {}".format(inspect.currentframe().f_code.co_name, type(solution), endTime - startTime, result))
    assert(graphsAreEquivalent(graph, result))

if "__main__" == __name__:
    test1(Solution1_DFS())
    test1(Solution1_BFS())

    test2(Solution1_DFS())
    test2(Solution1_BFS())

    test3(Solution1_DFS())
    test3(Solution1_BFS())

# End of "solution.py".
