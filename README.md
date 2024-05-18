ID : 208565820    
Mail : danielcohen1717@gmail.com

Opening:
In this task we asked to create a class that represent a graph by adj matrix and to implement some algorithms on those graphs.

Because you told us that the graph can be directed, undirected, with weights (negative and positive) and it can be unweighted.

My way:
My way of building and represnting the graph was by treat the graph as a directed graph 
because we need to represnt the graph with adj matrix so for me that was easier to refer the
graph as a directed one (because in adj matrix mat[x][y]!=0 means that there is an edge from x to y).

Graph class:
I created a class for graph by using graph.h and graph.cpp.
In graph.h I declared the function signatures and the field of the class(i created only one field aka adjmatrix to represnet the graph).

In graph.c I implemented all the functions frop the header file.
The constructor is empty so by defult it will allows the creation of objects of that class.
We loading the graph by loadGraph function and print the graph with printGraph.(the functions that we needed to do for the task)

In addition i created more 2 function to help me:
1.Get the number of the vertices.
2.Get the edge weight. 

Algorithms class:
In this class we asked to implement the following algorithms on the graph class:
isConnected, shortestPath, isContainCycle, isBipartite and negativeCycle.

for those algorithms i created 3 "help" functions: DFS, BellmanFordAlgo and dfsCycleHelper
each one of them is build to help we those algorithms

In graph.hpp I declared the function signatures and did all of them static because i dont need a instance of algorithms class. in addition i created a privte functions as i mentioned erlier to help me with the other functions.

In graph.cpp I using DFS function that calc the shortestpath from starting vertex to all others and i use him to help me to check if the graph is connected or no by that i do dfs and if after i finished there is a vertex that not visited the graph is not connected.
(dfs algo working )


I using bellmanford algo that iin the end returns the path(vector) of the shortest path from vertex x to vertex y.

In shortestPath function I am using BellmanFord algo as I mentioned above and returns the shortest path by taking the path that BellmanFord gives me and calc all the weights of the edges in this path.

In isContainCycle function I am using dfsCycleHelper function that using dfs and recursivly explore vertices and detect for cycle.

in isBipartite I am coloring all the vertex in -1 color and then starting from vertex 0 (coloring him with color 0), checking every neighboors of this vertex and if there is an edge between him and other vertex i coloring this vertex in 1 - color of vertex 0 and i go on with this approch for all the vertex in the end if there is a vertex that have the same color as his neighboor it will return false.

in negativeCycle function I am using in BellmanFord approch that is can detect if there is negative cycle in the graph by relax the graph n-1 times (n represent the number of vertices) and every relax to check if the way for each vertex is reduce and then after n-1 relaxs we will do another time relax, if in this time we found a way to reduce one of the edges there is a negative cycle in the graph.

In addition i did tests to check cases for my functions(Test.cpp).








