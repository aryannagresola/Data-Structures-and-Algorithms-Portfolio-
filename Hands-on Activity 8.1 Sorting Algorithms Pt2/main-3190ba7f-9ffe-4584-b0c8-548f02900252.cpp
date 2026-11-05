#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"
#include "sortingAlgo.h"

int main(){
    const int SIZE = 100;
    int numbers[SIZE];
    srand(time(0));

    // generating 100 random numbers:
    for(int i  = 0; i < SIZE; i++){
        numbers[i] = rand() % 100 + 1;
    }

    std::cout << "--- ORIGINAL UNSORTED ARRAY ---" << std::endl;
    display(numbers, SIZE);
    std::cout << std::endl;

    std::cout << "--- SORTED ARRAY ---" << std::endl;
    // shell sort:
    std::cout << "Shell Sort: " << std::endl;
    shellSort(numbers, SIZE);
    display(numbers, SIZE);
    std::cout << std::endl;

    // merge sort:
    std::cout << "Merge Sort: " << std::endl;
    mergeSort(numbers, 0, SIZE - 1);
    display(numbers, SIZE);
    std::cout << std::endl;

    // quick sort:
    std::cout << "Quick Sort: " << std::endl;
    quickSort(numbers, 0, SIZE - 1);
    display(numbers, SIZE);
    std::cout << std::endl;

    return 0;
}


