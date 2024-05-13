#include <iostream>
#include <vector>
#include <limits>
#include <climits> 
#include <algorithm>
#include <queue>
#include "Graph.hpp"
#include "Algorithms.hpp"

namespace ariel 
{
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

int Algorithms::shortestPath(const Graph& graph, int start, int end) {
    std::vector<int> pathVertices = BellmanFordAlgo(graph, start, end);

    if (pathVertices.empty()) {
        // No path exists
        std::cerr << "No path exists from vertex " << start << " to vertex " << end << std::endl;
        return -1;
    } else {
        // Print the path
        std::cout << "Shortest path from vertex " << start << " to vertex " << end << ": ";
        for (int vertex : pathVertices) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
        return graph.getEdgeWeight(pathVertices[pathVertices.size()-2], end); // Or whatever value you want to return on success
    }
}

bool Algorithms::isContainsCycle(const Graph& graph) {
    int numVertices = graph.getNumVertices();
    std::vector<bool> visited(numVertices, false);

    // Perform DFS on each unvisited vertex
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            std::vector<int> cyclePath;
            if (dfsCycleHelper(graph, i, -1, visited, cyclePath)) {
                // If DFS returns true, a cycle is found
                std::cout << "Cycle found: ";
                for (int vertex : cyclePath) {
                    std::cout << vertex << " ";
                }
                std::cout << std::endl;
                return true;
            }
        }
    }

    return false; // No cycle found
}

bool Algorithms::isBipartite(const Graph& graph) {
    int numVertices = graph.getNumVertices();
    std::vector<int> colors(numVertices, -1); // -1 indicates uncolored, 0 for one color, 1 for the other
    std::queue<int> q;

    // Start from vertex 0
    int startVertex = 0;
    colors[startVertex] = 0; // Color the source vertex with RED
    q.push(startVertex);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        std::vector<int> adjList = graph.getAdjacencyList(vertex);
        for (size_t j = 0; j < adjList.size(); ++j) {
            int adj = adjList[j];
            
            // If the adjacent vertex is not colored, color it with the opposite color
            if (colors[adj] == -1) {
                colors[adj] = 1 - colors[vertex]; // Assign the opposite color
                q.push(adj);
            }
            // If the adjacent vertex is already colored and has the same color as the current vertex,
            // then the graph is not bipartite
            else if (colors[adj] == colors[vertex]) {
                return false;
            }
            // If the adjacent vertex is already colored with the opposite color, do nothing
        }
    }

    return true; // If no conflicts were found, the graph is bipartite
}


bool Algorithms::negativeCycle(const Graph &graph) 
{
    int numVertices = graph.getNumVertices();
    std::vector<int> distances(numVertices, std::numeric_limits<int>::max()); // Distance array
    std::vector<int> pi(numVertices, -1); // Predecessor array

    // Initialize distances
    distances[0] = 0; // Assume source vertex (e.g., vertex 0)

    // Relax edges repeatedly (V-1 times)
    for (int i = 0; i < numVertices - 1; ++i) {
        for (int u = 0; u < numVertices; ++u) {
            for (int v : graph.getAdjacencyList(u)) {
                int weight = graph.getEdgeWeight(u, v);
                if (distances[u] != std::numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    pi[v] = u;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < numVertices; ++u) {
        for (int v : graph.getAdjacencyList(u)) {
            int weight = graph.getEdgeWeight(u, v);
            if (distances[u] != std::numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                // Negative cycle detected
                std::cerr << "Graph contains a negative cycle." << std::endl;

                // Extract the cycle vertices
                std::vector<int> cycleVertices;
                int currentVertex = v;
                while (currentVertex != -1 && currentVertex != u) 
                {
                    cycleVertices.push_back(currentVertex);
                    currentVertex = pi[currentVertex];
                }
                cycleVertices.push_back(u); // Add the starting vertex
                std::reverse(cycleVertices.begin(), cycleVertices.end()); // Reverse the path vertices

                // Print the cycle
                std::cout << "Negative cycle vertices: ";
                for (int vertex : cycleVertices) 
                {
                    std::cout << vertex << " ";
                }
                std::cout << std::endl;

                return true;
            }
        }
    }

    return false; // No negative cycle found
}

void Algorithms::DFS(const Graph& graph, int vertex, std::vector<bool>& visited) 
{
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

bool Algorithms::dfsCycleHelper(const Graph& graph, int vertex, int parent, std::vector<bool>& visited, std::vector<int>& cyclePath) {
    visited[vertex] = true; // Mark the current vertex as visited

    // Iterate through all adjacent vertices
    for (int adj : graph.getAdjacencyList(vertex)) {
        if (!visited[adj]) {
            // If the adjacent vertex is not visited, recursively call DFS
            cyclePath.push_back(vertex);
            if (dfsCycleHelper(graph, adj, vertex, visited, cyclePath)) {
                return true; // If DFS returns true, a cycle is found
            }
            cyclePath.pop_back();
        } else if (adj != parent) {
            // If the adjacent vertex is visited and not the parent, a cycle is found
            cyclePath.push_back(vertex);
            cyclePath.push_back(adj);
            return true;
        }
    }

    return false; // No cycle found
}

std::vector<int> Algorithms::BellmanFordAlgo(const Graph& graph, int source, int dest) 
{
    std::vector<int> pathVertices;
    int numVertices = graph.getNumVertices();
    std::vector<int> distances(numVertices, std::numeric_limits<int>::max()); // Distance array
    std::vector<int> pi(numVertices, -1); // Predecessor array

    // Initialize distances
    distances[source] = 0;

    // Relax edges repeatedly (V-1 times)
    for (int i = 0; i < numVertices - 1; ++i) {
        for (int u = 0; u < numVertices; ++u) {
            for (int v : graph.getAdjacencyList(u)) {
                int weight = graph.getEdgeWeight(u, v);
                if (distances[u] != std::numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    pi[v] = u;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < numVertices; ++u) {
        for (int v : graph.getAdjacencyList(u)) {
            int weight = graph.getEdgeWeight(u, v);
            if (distances[u] != std::numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                // Indicates a negative cycle
                std::cerr << "Graph contains a negative cycle." << std::endl;
                return {}; // Return an empty vector to indicate failure
            }
        }
    }

    // Reconstruct the shortest path from source to dest
    int currentVertex = dest;
    while (currentVertex != -1 && currentVertex != source) {
        pathVertices.push_back(currentVertex);
        currentVertex = pi[currentVertex];
    }
    if (currentVertex == -1) {
        // No path exists from source to dest
        return {};
    }

    pathVertices.push_back(source); // Add the source vertex
    std::reverse(pathVertices.begin(), pathVertices.end()); // Reverse the path vertices
    //std::cout << "The length of the shortest path from source to dest is: " << graph.getEdgeWeight(pi[dest], dest) << std::endl;
    return pathVertices;
}
}


