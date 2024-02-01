# Start of "solution.py".

from collections import deque
import inspect
import time
from typing import List
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

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

    Time = O(?)

    Space = O(?)
"""
from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        #
        # TODO: >>> Under Construction <<<
        #
        return node

def graphsAreEquivalent(graph1: Optional['Node'], graph2: Optional['Node']) -> bool:
    #
    # TODO: >>> Under Construction <<<
    #
    return False

def test1(solution):
    grid = [
        [2,4],
        [1,3],
        [2,4],
        [1,3]
    ]
    startTime = time.time()
    result = solution.cloneGraph(grid)
    endTime = time.time()
    print("{}:{}({:.6f} sec) result = {}".format(inspect.currentframe().f_code.co_name, type(solution), endTime - startTime, result))
    assert(graphsAreEquivalent(grid, result))

def test2(solution):
    grid = [
        [],
    ]
    startTime = time.time()
    result = solution.cloneGraph(grid)
    endTime = time.time()
    print("{}:{}({:.6f} sec) result = {}".format(inspect.currentframe().f_code.co_name, type(solution), endTime - startTime, result))
    assert(graphsAreEquivalent(grid, result))

def test3(solution):
    grid = [
    ]
    startTime = time.time()
    result = solution.cloneGraph(grid)
    endTime = time.time()
    print("{}:{}({:.6f} sec) result = {}".format(inspect.currentframe().f_code.co_name, type(solution), endTime - startTime, result))
    assert(graphsAreEquivalent(grid, result))

if "__main__" == __name__:
    test1(Solution())
    test2(Solution())
    test3(Solution())

# End of "solution.py".
