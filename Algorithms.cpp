#include "Algorithms.hpp"
#include <limits>
#include <stack>


bool Algorithms::isConnected(const Graph& graph) {
    int numVertices = graph.getNumVertices();
    std::vector<bool> visited(numVertices, false);

    // Perform DFS starting from vertex 0
    DFS(graph, 0, visited);

    // Check if all vertices were visited
    for (int v = 0; v < numVertices; ++v) {
        if (!visited[v]) {
            // If any vertex was not visited, return false
            return false;
        }
    }

    return true;
}

int Algorithms::shortestPath(const Graph& graph, int start, int end) 
{
    int numVertices = graph.getNumVertices();

    // Initialize distances from start vertex to all other vertices
    std::vector<int> distance(numVertices, std::numeric_limits<int>::max());
    distance[start] = 0;

    // Relax edges repeatedly
    for (int i = 0; i < numVertices - 1; ++i) 
    {
        for (int u = 0; u < numVertices; ++u) 
        {
            const auto& adjList = graph.getAdjacencyList(u); // Get adjacency list of vertex u
            for (int v : adjList) {
                int weight = graph.getEdgeWeight(u, v); // Get edge weight from graph
                if (distance[u] != std::numeric_limits<int>::max() && distance[u] + weight < distance[v]) 
                {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < numVertices; ++u) 
    {
        const auto& adjList = graph.getAdjacencyList(u); // Get adjacency list of vertex u
        for (int v : adjList) {
            int weight = graph.getEdgeWeight(u, v); // Get edge weight from graph
            if (distance[u] != std::numeric_limits<int>::max() && distance[u] + weight < distance[v]) 
            {
                // Negative cycle found
                std::cerr << "Graph contains negative cycle\n";
                return -1; // Return -1 to indicate negative cycle
            }
        }
    }

    // Return shortest distance from start to end vertex
    return distance[end];
}



bool Algorithms::isContainsCycle(const Graph& graph) 
{
    // Implementation of isContainsCycle algorithm
}

bool Algorithms::isBipartite(const Graph& graph) 
{
    // Implementation of isBipartite algorithm
}

bool Algorithms::negativeCycle(const Graph& graph)
{
    // Implementation of negativeCycle algorithm
}

void Algorithms::DFS(const Graph& graph, int vertex, std::vector<bool>& visited) {
    // Mark the current vertex as visited
    visited[vertex] = true;

    // Iterate through all adjacent vertices
    for (int adj : graph.getAdjacencyList(vertex)) {
        if (!visited[adj]) {
            // If the adjacent vertex is not visited, perform DFS on it
            DFS(graph, adj, visited);
        }
    }
}

// Graph Algorithms::transpose(const Graph& graph) 
// {
//     int numVertices = graph.getNumVertices();
//     Graph transposedGraph(numVertices);

//     for (int i = 0; i < numVertices; ++i) 
//     {
//         for (int j : graph.getAdjacencyList(i)) 
//         {
//             int weight = graph.getEdgeWeight(i, j); // Get the edge weight
//             transposedGraph.addEdge(j, i, weight); // Reverse the edge direction with the same weight
//         }
//     }

//     return transposedGraph;
// }

