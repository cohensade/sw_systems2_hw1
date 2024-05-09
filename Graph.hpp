#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<vector<int>> edge; // Edge weights

public:
    Graph(int vertices);
    void loadGraph(const vector<vector<int>>& adjacencyMatrix);
    void printGraph() const;
    int getNumVertices() const;
    vector<int>getAdjacencyList(int vertex) const;
    void addEdge(int src, int dest, int weight);
    int getEdgeWeight(int src, int dest) const;

};

#endif /* GRAPH_HPP */