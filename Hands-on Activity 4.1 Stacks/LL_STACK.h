#ifndef LL_STACK_H
#define LL_STACK_H

#include <iostream>

class Node{
    public:
        char data;
        Node* next = nullptr;
};

Node* head = nullptr;

//push opereation
void push(char newData){
    //create new node
    Node* newNode = new Node;
    //assign data
    newNode->data = newData;
    //point the new node to the current head
    newNode->next = head;
    //assign the new head
    head = newNode;
}

//isEmpty operation
bool isEmpty(){
    return head == nullptr;
}

//pop operation
char pop(){
    //checks if the stack is empty
    if(isEmpty()){
        std::cout << "Stack Underflow." << std::endl;
        return '\0';
    }
    //save the current top node
    Node* temp = head;
    //save the data
    char tempVal = temp->data;
    //move head to the next node
    head = head->next;
    //free memory
    delete temp;
    return tempVal;
}

//top operation
char Top(){
    if(isEmpty()){
        return '\0';
    }
    return head->data;
}

#endif

