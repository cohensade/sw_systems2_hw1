#include "Graph.hpp"

Graph::Graph(int vertices) : V(vertices), adj(V, vector<int>())
{

}

void Graph::loadGraph(const vector<vector<int>>& adjacencyMatrix)
{
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (adjacencyMatrix[i][j]) {
                adj[i].push_back(j);
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

void Graph::addEdge(int src, int dest, int weight) {
    adj[src].push_back(dest);
    edge[src].push_back(weight); // Update edge weight
}

int Graph::getEdgeWeight(int src, int dest) const {
    return edge[src][dest];
}

