#include <iostream>
#include "sortingAlgo.h"

int main(){
    // problem 1:
    std::cout << "PROBLEM 1" << std::endl;

    int numSet[] = {12, 25, 11, 42, 56, 75, 10};
    int setSize = 7;

    std::cout << "--- ORIGINAL UNSORTED ARRAY ---" << std::endl;
    display(numSet, setSize);
    std::cout << std::endl;

    int pivot = arrPartition(numSet, 0, setSize - 1);
    std::cout << "--- AFTER PARTITION IN QUICK SORT ---" << std::endl;
    display(numSet, setSize);

    std::cout << "PIVOT: " << numSet[pivot] << std::endl;

    // this part will sort the left sublist using insertion sort:
    insertionSort(numSet, 0, pivot - 1);
    // this part will sort the right sublist using insertion sort:
    insertionSort(numSet, pivot + 1, setSize - 1);

    std::cout << "--- AFTER SORTING LEFT AND RIGHT SUBLISTS ---" << std::endl;
    display(numSet, setSize);
    std::cout << std::endl;

    // problem 2:
    std::cout << "PROBLEM 2" << std::endl;
    const int SIZE = 15;
    int num[SIZE] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};

    // seperate copies for different sorting algo:
    int mergeNum[SIZE];
    int quickNum[SIZE];

    for(int i = 0; i < SIZE; i++){
        mergeNum[i] = num[i];
        quickNum[i] = num[i];
    }

    // implementing merge sort:
    std::cout << "--- MERGE SORT ---" << std::endl;
    std::cout << "Before: ";
    display(mergeNum, SIZE);

    mergeSort(mergeNum, 0, SIZE - 1);
    std::cout << "After: ";
    display(mergeNum, SIZE);
    std::cout << std::endl;

    // implementing quick sort:
    std::cout << "--- QUICK SORT ---" << std::endl;
    std::cout << "Before: ";
    display(quickNum, SIZE);
    
    quickSort(quickNum, 0, SIZE - 1);
    std::cout << "After: ";
    display(quickNum, SIZE);

    return 0;
}

