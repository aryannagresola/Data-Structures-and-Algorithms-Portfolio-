#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"
#include "sortingAlgo.h"

const int SIZE = 100;

int main(){
    int numbers[SIZE];
    srand(time(0));
    // generating 100 random numbers:
    for(int i = 0; i < SIZE; i++){
        numbers[i] = rand() % 100 + 1;
    }

    // display:
    std::cout << "Array Elements (random numbers): " << std::endl;
    display(numbers, SIZE);
    std::cout << std::endl;

    // bubble sort:
    std::cout << "Bubble Sort: " << std::endl;
    bubbleSort(numbers, SIZE);
    display(numbers, SIZE);
    std::cout << std::endl;

    // selection sort: 
    std::cout << "Selection Sort: " << std::endl;
    selectionSort(numbers, SIZE);
    display(numbers, SIZE);
    std::cout << std::endl;

    // insertion sort:
    std::cout << "Insertion Sort: " << std::endl;
    insertionSort(numbers, SIZE);
    display(numbers, SIZE);
    std::cout << std::endl;



    return 0;
}