#include <iostream>
#include "node.h"

#ifndef SEARCHINGALGO2_H
#define SEARCHINGALGO2_H

// problem 1:
template <typename T>
void linearSearchArrComp(int arrSize, T dataFind, T list[]){
    int i = 0;
    int comparisons = 0;

    while(i < arrSize){
        comparisons++;
        if (dataFind == list[i]){
            std::cout << "Searching successful" << std::endl;
            std::cout << "Number of comparisons: " << comparisons << std::endl;
        return;
        }
        i++;
    }
    std::cout << "Searching is unsuccessful." << std::endl;
}

template <typename T>
void linearSearchLLComp(Node<T>* head, T dataFind){
    int comparisons = 0;
    while(head != nullptr){
        comparisons++;

        if(head->data == dataFind){
            std::cout << "Searching is successful." << std::endl;
            std::cout << "Number of comparisons: " << comparisons << std::endl;
            return;
        }
        head = head->next;
    }
    std::cout << "Searching is unsuccessful." << std::endl;
}

// problem 2: 
template <typename T>
int linearSearchArrCount(int arrSize, T dataFind, T list[]){
    int i = 0;
    int count = 0;

    while(i < arrSize){
        if(dataFind == list[i]){
            count++;
        }
        i++;
    }
    return count;
}

template <typename T>
int linearSearchLLCount(Node<T>* head, T dataFind){
    int count = 0;
    while(head != nullptr){
        if(head->data == dataFind){
            count++;
        }
        head = head->next;
    }
    return count;
}

// problem 3:
template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]){
    int low = 0;
    int up =  arrSize - 1;
    while(low <= up){
        int mid = ( low + up ) / 2;
        if(dataFind == list[mid]){
            std::cout << "Search element is found!" << std::endl;
            std::cout << "Found at index: " << mid << std::endl;
            return;
        }else if(dataFind < list[mid]){
            up = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    std::cout << "Search element is not found." << std::endl;
}

// problem 4:
template <typename T>
void recursiveBinarySearch(T list[], int low, int up, T dataFind){
    if(low > up){
        std::cout << "Search element is not found." << std::endl;
        return;
    }
    int mid = (low + up) / 2;
    if(dataFind == list[mid]){
        std::cout << "Search element is found." << std::endl;
        return;
    }else if(dataFind < list[mid]){
        recursiveBinarySearch(list, low, mid - 1, dataFind);
    }else{
        recursiveBinarySearch(list, mid + 1, up, dataFind);
    }
}
#endif