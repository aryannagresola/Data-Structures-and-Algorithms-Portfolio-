#include <iostream>
#include <stack> // call the stack from the STL

int main(){
    std::stack<int> newStack; // created an object

    // testing the empty() function to check if the stack is empty
    std::cout << "Is the stack empty? " << newStack.empty() << std::endl;

    //insert a 3 elements:
    newStack.push(3);
    std::cout << "Top of stack: " << newStack.top() << std::endl;
    newStack.push(2);
    std::cout << "Top of stack: " << newStack.top() << std::endl;
    newStack.push(1);
    std::cout << "Top of stack: " << newStack.top() << std::endl;

    // checking if the stack is empty
    std::cout << "Is the stack empty? " << newStack.empty() << std::endl;

    newStack.push(6);
    newStack.push(7);
    newStack.push(8);
    // checking the size of the current stack
    std::cout << "Size of the stack is: " << newStack.size() << std::endl;

    // emplace -> construct and inert element -> public member function
    std::cout << "EMPLACE" << std::endl;
    newStack.emplace(9);
    std::cout << "New top of the stack after emplace: " << newStack.top() << std::endl;

    // swap -> swap the contents of the public member functions
    std::cout << "SWAP" << std::endl;
    std::stack<int> secondStack;

    secondStack.push(10);
    secondStack.push(11);
    secondStack.push(12);

    std::cout << "Before swap: " << std::endl;
    std::cout << "Top of newStack: " << newStack.top() << std::endl;
    std::cout << "Top of secondStack: " << secondStack.top() << std::endl;

    newStack.swap(secondStack);

    std::cout << "After swap: " << std::endl;
    std::cout << "Top of newStack: " << newStack.top() << std::endl;
    std::cout << "Top of secondStack: " << secondStack.top() << std::endl;


    return 0;
}
