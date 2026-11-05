#ifndef QUEUELL_H
#define QUEUELL_H
#include <iostream>

// create a class 
template <typename T>
class qNode{
    public: 
        T data;
        qNode<T>* next;
};

// creates the new node
template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

// enqueue operation
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    // creates the new node
    qNode<T>* newNode = new_node(newData);

    // inserting into an empty queue:
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }

    // inserting an item into a non-empty queue
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

// dequeue operation
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    //check first if empty:
     if((*frontPtr) == nullptr){
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    // create a temporary node
    qNode<T>* deleteNode = nullptr; // temp variable
    deleteNode = *frontPtr;

    // check if the queue has only 1 node
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }

    // delete the node
    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;
 }

 // check the front 
 template <typename T>
 void checkFront(qNode<T>** frontPtr){
    if((*frontPtr) == nullptr){ // checking if there's an existing front queue
        std::cout << "Front queue is empty." << std::endl; 
        return;
    }
    std::cout << "Front: " << (*frontPtr)->data << std::endl;
 }

 // check the back
 template <typename T>
 void checkBack(qNode<T>** backPtr){
    if((*backPtr) == nullptr){
        std::cout << "Back queue is empty. " << std::endl;
        return;
    }
    std::cout << "Back: " << (*backPtr)->data << std::endl;
 }

 // display all
template <typename T>
void display(qNode<T>** frontPtr){
    qNode<T>* temp = *frontPtr;
    std::cout << "Queue: ";

    if(temp == nullptr){
        std::cout << "Queue is empty. " << std::endl;
        return;
    }
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

}

#endif