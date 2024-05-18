// Graph.hpp
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

namespace ariel
{
    class Graph {
    private:
        vector<vector<int>> adjacencyMatrix; // Adjacency matrix

    public:
        Graph();
        void loadGraph(const vector<vector<int>>& adjacencyMatrix);
        void printGraph() const;
        int getNumVertices() const;
        const vector<vector<int>>& getgraph() const;
        int getEdgeWeight(int src, int dest) const;
       
    };
}

#endif /* GRAPH_HPP */