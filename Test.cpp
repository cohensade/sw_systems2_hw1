#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
using namespace std;

TEST_CASE("Test isConnected with connected graph")
{
    ariel::Graph g;
    // Define a connected graph
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected with disconnected graph")
{
    ariel::Graph g;
    // Define a disconnected graph
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected with single vertex")
{
    ariel::Graph g;
    // Define a graph with a single vertex
    vector<vector<int>> graph = {{0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected with no edges")
{
    ariel::Graph g;
    // Define a graph with multiple vertices and no edges
    vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath with valid path")
{
    ariel::Graph g;
    // Define a graph with a valid path
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == 2);
}

TEST_CASE("Test shortestPath with no path")
{
    ariel::Graph g;
    // Define a graph with no path
    vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == -1);
}

TEST_CASE("Test shortestPath with single vertex")
{
    ariel::Graph g;
    // Define a graph with a single vertex
    vector<vector<int>> graph = {{0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == -1);
}

TEST_CASE("Test shortestPath in larger graph")
{
    ariel::Graph g;
    // Define a larger graph
    vector<vector<int>> graph = {
        {0, 1, 4, 0, 0, 0},
        {1, 0, 4, 2, 7, 0},
        {4, 4, 0, 3, 5, 0},
        {0, 2, 3, 0, 4, 6},
        {0, 7, 5, 4, 0, 7},
        {0, 0, 0, 6, 7, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 5) == 9);
}

TEST_CASE("Test isContainsCycle with cyclic graph")
{
    ariel::Graph g;
    // Define a cyclic graph
    vector<vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isContainsCycle with acyclic graph")
{
    ariel::Graph g;
    // Define an acyclic graph
    vector<vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isContainsCycle with self-loop")
{
    ariel::Graph g;
    // Define a graph with a self-loop
    vector<vector<int>> graph = {
        {1, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isContainsCycle with larger acyclic graph")
{
    ariel::Graph g;
    // Define a larger acyclic graph
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isBipartite with bipartite graph")
{
    ariel::Graph g;
    // Define a bipartite graph
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == true);
}

TEST_CASE("Test isBipartite with non-bipartite graph")
{
    ariel::Graph g;
    // Define a non-bipartite graph
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == false);
}

TEST_CASE("Test isBipartite with isolated vertex")
{
    ariel::Graph g;
    // Define a graph with an isolated vertex
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == true);
}

TEST_CASE("Test isBipartite with complex bipartite graph")
{
    ariel::Graph g;
    // Define a more complex bipartite graph
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == true);
}

TEST_CASE("Test negativeCycle with no negative cycle")
{
    ariel::Graph g;
    // Define a graph with no negative cycle
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == false);
}

TEST_CASE("Test negativeCycle with negative cycle")
{
    ariel::Graph g;
    // Define a graph with a negative cycle
    vector<vector<int>> graph = {
        {0, -1, 0},
        {0, 0, -1},
        {-1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == true);
}

TEST_CASE("Test negativeCycle with isolated negative edge")
{
    ariel::Graph g;
    // Define a graph with an isolated negative edge
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, -2}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == true);
}

TEST_CASE("Test negativeCycle with large graph with no cycle")
{
    ariel::Graph g;
    // Define a larger graph with no negative cycle
    vector<vector<int>> graph = {
        {0, 2, 0, 0, 3},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == false);
}

TEST_CASE("Test negativeCycle with zero-weight edges")
{
    ariel::Graph g;
    // Define a graph with zero-weight edges
    vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == false);
}
