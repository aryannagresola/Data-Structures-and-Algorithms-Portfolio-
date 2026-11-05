#include <iostream>

const size_t maxCap = 100;
int stack[maxCap];
int top = -1, newData, elements;

// prototyping
bool isFull();
bool isEmpty();
void push();
void pop();
void Top();
void displayAll();


int main(){
    int choice;
    // asked the user for the maximum elements to be inserted
    std::cout << "Enter the number of maximum elements for the new stack (max: 100): ";
    std::cin >> elements;

    while(true){
        std::cout << "STACK OPERATIONS: " << std::endl;
        std::cout << " 1. Push\n 2. Pop\n 3. Top\n 4. isEmpty\n 5. isFull\n 6. Display All\n";
        std::cout << "Choose Operation: ";
        std::cin >> choice;

        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout << isEmpty() << std::endl;
            break;
            case 5: std::cout << isFull() << std::endl;
            case 6: displayAll();
            break;
            default: std::cout << "Invalid choice." << std::endl;
            break;

        }
    }

    return 0;
}

bool isEmpty(){
    // top is -1
    if(top == -1){
        std::cout << "Stack Underflow" << std::endl;
        return true;
    }
    return false;
}

bool isFull(){
    // not equal to the maxCap
    if(top >= elements-1){
        std::cout << "Stack overflow.";
        return true;
    }
    return false;
}

void push(){
    // check if the stack is full. if yes return an error 
    if(isFull()) return;
    // ask the use for a value to be pushed into the stack
    std::cout << "What number you want to add to the stack? ";
    std::cin >> newData;
    //store inside the stack? check pre incre vs. post incre 
    stack[++top] = newData; 
}

void pop(){
    // check if there are no more elements inside the stack
    if(isEmpty()) return;
     
    //display the element to be popped:
    std::cout << "Popping: " << stack[top] << std::endl;

    //decrement the top
    top--;
}

void Top(){
    // error checking
    if(isEmpty()) return;

    //display the top element
    std::cout << "The top element is: " << stack[top] << std::endl;
}

void displayAll(){
    if (isEmpty()) return;

    std::cout << "Contents of the Stack: " << std::endl;

    for (int i = top; i >= 0; i--){
        std::cout << stack[i] << std::endl;
    }
}