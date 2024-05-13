#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <limits>

namespace ariel
{
Graph::Graph(int vertices) : V(vertices), adj(V, vector<int>()), edge(V, vector<int>(V, 0)) 
{

}

void Graph::loadGraph(const vector<vector<int>>& adjacencyMatrix)
{
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (adjacencyMatrix[i][j]) {
                adj[i].push_back(j);
                edge[i][j] = adjacencyMatrix[i][j]; 
            }
        }
    }
}

void Graph::printGraph() const 
{
    for (int i = 0; i < V; ++i) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int Graph::getNumVertices() const 
{
    return V;
}

vector<int> Graph::getAdjacencyList(int vertex) const 
{
    return adj[vertex];
}

int Graph::getEdgeWeight(int src, int dest) const 
{
    // Check if there is an edge from src to dest
    if (edge[src][dest] != 0) 
    {
        return edge[src][dest]; // Return the weight of the edge
    } else 
    {
        return std::numeric_limits<int>::max(); // Return infinity if there is no edge
    }
}
}




