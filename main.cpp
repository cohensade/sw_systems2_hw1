#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"

int main() {
    // Create an instance of the Graph class
    Graph graph(3);

    // Create an adjacency matrix
    vector<vector<int>> adjacencyMatrix = {
    //  {1, 1, 1, 1, 1},
    // {1, 1, 1, 1, 1},
    // {1, 1, 1, 1, 1},
    // {1, 1, 1, 1, 1},
    // {1, 1, 1, 1, 1}

    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 0}
   
};


    // Load the graph from the adjacency matrix
    graph.loadGraph(adjacencyMatrix);

    // Print the graph edges with their weights
    for (int i = 0; i < graph.getNumVertices(); ++i) {
        for (int j : graph.getAdjacencyList(i)) {
            cout << "Edge from " << i << " to " << j << " with weight " << graph.getEdgeWeight(i, j) << endl;
        }
    }

    // Print the graph
    graph.printGraph();

    // Get the number of vertices
    cout << "Number of vertices: " << graph.getNumVertices() << endl;

    if (Algorithms::isConnected(graph)) {
        cout << "The graph is connected. " << endl;
    } else {
        cout << "The graph is not connected. " << endl;
    }
    cout << Algorithms::shortestPath(graph, 0, 1) << endl;

if (Algorithms::isContainsCycle(graph))
{
    cout << "The graph contain cycle. " << endl;
}else
{
    cout << "The graph not contain cycle. " << endl;
}

if (Algorithms::isBipartite)
{
    cout << "The graph is bipartite. " << endl;
}
else
{
    cout << "The graph is not bipartite. "<< endl;
}


    return 0;
}
