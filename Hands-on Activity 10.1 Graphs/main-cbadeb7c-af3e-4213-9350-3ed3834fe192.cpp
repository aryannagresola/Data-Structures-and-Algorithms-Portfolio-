#include <iostream>
#include "Graph.h"

int main(){
    Graph graph(6);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 4, 3);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 1, 4);
    graph.addEdge(4, 3, 3);

    std::cout << "GRAPH IMPLEMENTATION: CREATE A GRAPH" << std::endl;
    std::cout << std::endl;

    graph.displayVertices();
    std::cout << std::endl;

    graph.displayEdges();

    return 0;
}





