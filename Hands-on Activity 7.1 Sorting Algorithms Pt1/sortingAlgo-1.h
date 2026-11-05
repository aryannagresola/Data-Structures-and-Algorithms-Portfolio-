#ifndef SORTINGALGO_H
#define SORTINGALGO_H
#include <iostream>

template <typename T>
void insertionSort(T arr[], int arrSize){
    int j;
    T temp; 

    for(int i = 1; i < arrSize; i++){
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j  + 1] = temp;
    }
}

#endif


