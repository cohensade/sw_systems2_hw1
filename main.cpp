#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>

int main() {
    // Create a graph
    ariel::Graph graph;

    // Define the adjacency matrix
    std::vector<std::vector<int>> adjacencyMatrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    // Load the graph with the adjacency matrix
    graph.loadGraph(adjacencyMatrix);

    // Print the graph
    std::cout << "Graph:" << std::endl;
    graph.printGraph();

    // Test algorithms
    std::cout << "Is connected: " << ariel::Algorithms::isConnected(graph) << std::endl;
    std::cout << "Is bipartite: " << ariel::Algorithms::isBipartite(graph) << std::endl;
    std::cout << "Contains cycle: " << ariel::Algorithms::isContainsCycle(graph) << std::endl;
    std::cout << "Has negative cycle: " << ariel::Algorithms::negativeCycle(graph) << std::endl;

    // Find shortest path
    int start = 0;
    int end = 0;
    int shortestPathLength = ariel::Algorithms::shortestPath(graph, start, end);
    if (shortestPathLength != -1) {
        std::cout << "Shortest path length from vertex " << start << " to vertex " << end << ": " << shortestPathLength << std::endl;
    }

    return 0;
}
