#include "node.h"
#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchArr(int arrSize, T dataFind, T list[]) {

    //Step 1: I := 0
    int i = 0;
    //Repeat while I <= n
    while (i < arrSize) {
        //  If (item = data[i])
        if (dataFind == list[i]) {
            //  Print "Searching is successful"
            std::cout << "Searching is successful.\n";
            return;
        }
        i++;
    }
    // Print "Searching is Unsuccessful"
    std::cout << "Searching is unsuccessful." << std::endl;
}

template <typename T>
void linearSearchLL(Node<T>* head, T dataFind){
    while(head != nullptr){
        if(head->data == dataFind){
            std::cout << "Searching is successful." << std::endl;
            return;
        }
        head = head->next;
    }
    std::cout << "Searching is unsuccessful." << std::endl;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;

    while(fast != last && fast->next != last){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){
    Node<T>* last = nullptr;
    while(start != last){
        Node<T>* middle = getMiddle(start, last);

        if(middle->data == dataFind){
            std::cout << "Searching is successful." << std::endl;
            return;
        }
        else if(middle->data > dataFind){
            last = middle;
        }
        else{
            start = middle->next;
        }
    }
    std::cout << "Searching is unsuccessful." << std::endl;
}

template <typename T> 
void binarySearchArr(int arrSize, T dataFind, T list[]){
    int low = 0;
    int up = arrSize - 1;

    while(low <= up){
        int mid = (low + up) / 2;
        if(dataFind == list[mid]){
            std::cout << "Search element is found!" << std::endl;
            return;
        }
        else if(dataFind < list[mid]){
            up = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    std::cout << "Search element is not found." << std::endl;
}

#endif