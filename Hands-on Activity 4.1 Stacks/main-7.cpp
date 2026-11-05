#include <iostream>
#include <string>
#include "arrayStack.h"


bool isBalanced(std::string expression){
    top = -1; // resetting stack
    for (char c : expression){
        
        // opening symbols 
        if (c == '(' || c == '[' || c == '{'){ 
            push(c);
        } else if (c == ')' || c == '}' || c == ']'){ // closing symbols 
            if (isEmpty()){
                return false;
            }
            char open = pop();
            if ((open == '(' && c != ')') ||
                (open == '[' && c != ']')  ||
                (open == '{' && c != '}')){
                return false;
            }
         }
    }
    return isEmpty();
}

int main() {
    std::string expression;
    std::cout << "Enter Expression: ";
    getline(std::cin, expression);

    if (isBalanced(expression))
        std::cout << "Expression is VALID." << std::endl;
    else
        std::cout << "Expression is INVALID." << std::endl;
    return 0;
}


