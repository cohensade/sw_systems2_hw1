#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"

int main() {
    // Create an instance of the Graph class
    Graph graph(5);

    // Create an adjacency matrix
    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 0, 1, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}

        // {1, 1},
        // {1, 1}

        // {0, 1, 1, 1},
        // {1, 0, 1, 1},
        // {1, 1, 0, 1},
        // {1, 1, 1, 0}
    };

    // Load the graph from the adjacency matrix
    graph.loadGraph(adjacencyMatrix);

    // Print the graph
    graph.printGraph();

    // Get the number of vertices
    cout << "Number of vertices: " << graph.getNumVertices() << endl;

   if (Algorithms::isConnected(graph))
   {
    cout << "The graph is connected. " << endl;
   }else
   {
    cout << "The graph is not connected. " << endl;
   }
  cout << "The shortest path from vertex 0 to vertex 4 is: " << Algorithms::shortestPath(graph, 0, 4) << endl;

    return 0;
}