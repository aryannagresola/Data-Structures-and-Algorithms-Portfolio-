#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H
#include <iostream>

class AdjacencyMatrix{
private:
    int N;
    int** matrix;

public:
    AdjacencyMatrix(int vertices){
        N = vertices;

        matrix = new int*[N];
        for (int i = 0; i < N; i++){
            matrix[i] = new int[N];

            for (int j = 0; j < N; j++){
                matrix[i][j] = 0;
            }
        }
    }

    ~AdjacencyMatrix(){

        for (int i = 0; i < N; i++){
            delete[] matrix[i];
        }

        delete[] matrix;
    }

    void addEdge(int start, int end, int weight){

        if (start >= 0 && start < N &&
            end >= 0 && end < N){
            matrix[start][end] = weight;
        }
    }

    void display(){
        std::cout << "ADJACENCY MATRIX" << std::endl;
        std::cout << "    ";

        for (int i = 0; i < N; i++){
            std::cout << i << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < N; i++){
            std::cout << i << " | ";

            for (int j = 0; j < N; j++){
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif


