#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>

const int MAX = 100;
char stack[MAX];
int top = -1;

// push operation:
void push (char value){
    if(top == MAX - 1)
        return;
    
    stack[++ top] = value;
}

// popping operation:
char pop(){
    if(top == -1)
        return '\0';

    return stack[top--];
}

// top operation:
char Top(){
    if (top == -1)
        return '\0';
    return stack[top];
}

// isEmpty operation:
bool isEmpty(){
    return top == -1;
}

#endif

