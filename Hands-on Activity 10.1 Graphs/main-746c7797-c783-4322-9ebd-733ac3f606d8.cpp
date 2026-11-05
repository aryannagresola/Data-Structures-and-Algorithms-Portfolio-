#include <iostream>
#include "DiaGraph.h"

// print all adjacent vertices of a given vertex
void display_AdjList(adjNode* ptr, int i){
    std::cout << "Vertex " << i << ": ";

    if (ptr == nullptr){
        std::cout << "No edges";
    }else{
        while (ptr != nullptr) {
            std::cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ")";

            if (ptr->next != nullptr){
                std::cout << " -> ";
            }
            ptr = ptr->next;
        }
    }
    std::cout << std::endl;
}

// graph implementation
int main()
{
    graphEdge edges[] ={

        // (x, y, w) -> edge from x to y with weight w
        {0,1,2},
        {0,2,4},
        {1,4,3},
        {2,3,2},
        {3,1,4},
        {4,3,3}
    };

    int N = 6; // number of vertices in the graph
    // calculate number of edges
    int n = sizeof(edges) / sizeof(edges[0]);
    DiaGraph diagraph(edges, n, N);

    std::cout << "GRAPH ADJACENCY LIST" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Format: (start_vertex, end_vertex, weight)" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < N; i++){
        display_AdjList(diagraph.head[i], i);
    }

    return 0;
}




