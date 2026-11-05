#ifndef LIST_STACK_H
#define LIST_STACK_H
#include <iostream>

//class mode with data and next members 
template <typename T>
class Node{
    public:
    T data;
    Node<T>* next = nullptr;
};

// global
template <typename T>
Node<T>* head = nullptr;

// pushing operation:
template <typename T>
void push(T newData){

    // create a new node 
    Node<T>* newNode = new Node<T>;
    // assign the data to the new node
    newNode->data = newData;
    // point the newnode next to the current top
    newNode->next = head<T>;
    // assign the new top to the new node 
    head<T> = newNode;
}

//isEmpty operation:
template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

// popping operation:
template <typename T>
T pop(){
    // if the stack is empty error catch:
    if(isEmpty<T>()){
        std::cout << "Stack underflow." << std::endl;
        return T();
    } 
    // saving a current top node to a temporary variable 
    Node<T>* temp = head<T>;
    // store the data to a temporary variable 
    T tempVal = temp->data;
    // move the head to next node
    head<T> = head<T>->next;
    // free up the memory
    delete temp;
    //return the temporary variable data
    return tempVal;
}

// top operation:
template <typename T>
void Top(){
    // what if the stack is empty?
    if(isEmpty<T>()) 
        return;
    std::cout << "The top is: " << head<T>->data << std::endl;
}

// displaying all element in stack
template <typename T>
void displayAll(){
    // first check if the stack is empty
    if (isEmpty<T>()){
        std::cout << "The stack is empty." << std::endl;
        return;
    }
    // starts at the top (head)
    Node<T>* current = head<T>;
    std::cout << "Contents of Stack: ";
    // keeps moving til there are no more nodes
    while (current != nullptr){
        // prints the current node data
        std::cout << current->data << " ";
        // move to the next node til null
        current = current->next;
    }
    std::cout << std::endl;
}


#endif

