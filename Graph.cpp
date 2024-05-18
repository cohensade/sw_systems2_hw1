#include "Graph.hpp"
#include <iostream>

namespace ariel
{
    Graph::Graph() 
    {

    }

    void Graph::loadGraph(const vector<vector<int>>& adjMatrix)
    {
        adjacencyMatrix = adjMatrix;
    }

    void Graph::printGraph() const
    {
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            cout << "Adjacency list of vertex " << i << ": ";
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j)
            {
                if (adjacencyMatrix[i][j] != 0) // Only print non-zero edges cause if edge = 0 there is no edge
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }

    int Graph::getNumVertices() const
    {
        return adjacencyMatrix.size(); //return the num of vertex rows = cols = vertex
    }

    const vector<vector<int>>& Graph::getgraph() const 
    {
        return adjacencyMatrix; 
    }

    int Graph::getEdgeWeight(int src, int dest) const
    {
        return adjacencyMatrix[src][dest]; 
    }
}
