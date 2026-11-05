#include <iostream>
#include "node.h"
#include "searchingAlgo2.h"

const int max_size = 10;

int main(){
    int dataset[max_size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int dataFind = 8;

    std::cout << "PROBLEM 4: " << std::endl;
    std::cout << "Array Recursive Binary Search result is: "; 
    recursiveBinarySearch(dataset, 0, max_size - 1, dataFind);

    return 0;
}


