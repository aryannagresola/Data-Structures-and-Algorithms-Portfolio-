#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

struct Edge{
    int start;
    int end;
    int weight;
};

class Graph{
private:
    int vertices;
    Edge edges[100];
    int edgeCount;

public:
    Graph(int v){
        vertices = v;
        edgeCount = 0;
    }

    void addVertex(){ // 1. add vertex
        vertices++;
    }

    void addEdge(int start, int end, int weight){ // 2. add edge
        if(edgeCount < 100){
            edges[edgeCount].start = start;
            edges[edgeCount].end = end;
            edges[edgeCount].weight = weight;
            edgeCount++;
        }
    }
    
    void displayVertices(){ // 3. display graph vertices
        std::cout << "Vertices: ";
        for (int i = 0; i < vertices; i++){
            std::cout << i << " ";
        }
    }

    void displayEdges(){ // 3.1 display graph edges
        std::cout << "Edges:" << std::endl;
        for(int i = 0; i < edgeCount; i++){
            std::cout << edges[i].start << " - " << edges[i].end 
            << " (weight: " << edges[i].weight << ")" << std::endl;
        }
    }
};

#endif



