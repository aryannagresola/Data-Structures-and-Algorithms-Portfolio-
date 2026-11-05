#include <iostream>
#include "AdjacencyMatrix.h"

int main() {

    const int N = 6;

    AdjacencyMatrix graph(N);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 4, 3);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 1, 4);
    graph.addEdge(4, 3, 3);

    graph.display();

    return 0;
}





