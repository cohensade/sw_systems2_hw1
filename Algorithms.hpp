 // bool isConnected(); // Check if the graph is connected
   // int shortestPath(int start, int end); // Find the shortest path between start and end
    //bool isContainsCycle(); // Check if there is a cycle in the graph
   // bool isBipartite(); // Check if the graph is bipartite
   // bool negativeCycle(); // Check if there is a negative cycle in the graph

   #ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp" // Include the graph class header file

class Algorithms {
private:
    static void DFS(const Graph& graph, int vertex, std::vector<bool>& visited);
    static std::vector<int>BellmanFordAlgo(const Graph& graph, int source, int dest);
    static bool dfsCycleHelper(const Graph& graph, int vertex, int parent, std::vector<bool>& visited, std::vector<int>& cyclepath);
    //static bool isContainsCycleHelper(const Graph& graph, int vertex, int parent, std::vector<bool>& visited);

public:
    static bool isConnected(const Graph& graph);
    static int shortestPath(const Graph& graph, int start, int end);
    static bool isContainsCycle(const Graph& graph);
    static bool isBipartite(const Graph& graph);
    static bool negativeCycle(const Graph& graph);

    
  
};

#endif /* ALGORITHMS_HPP */
