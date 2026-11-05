#ifndef SORTING_H
#define SORTING_H
#include <iostream>

// display func:
template <typename T>
void display(T arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
        if((i + 1) % 10 == 0){
            std::cout << std::endl;
        }
    }
}

#endif

