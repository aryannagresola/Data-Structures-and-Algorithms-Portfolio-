#include <iostream>
#include <string>
#include "LL_STACK.h"

bool isBalanced(std::string expression){
    head = nullptr; //resetting stack

    for(char c : expression){
        //opening symbols
        if(c == '(' || c == '[' || c == '{'){
            push(c);
        }else if(c == ')' || c == ']' || c == '}'){
            if(isEmpty()){
                return false;
            }
            char open = pop();

            if((open == '(' && c != ')') ||
                (open == '[' && c != ']') ||
                (open == '{' && c != '}')){
                    return false;
            }
        }
    }
    return isEmpty();
}

int main(){
    std::string expression;

    std::cout << "Enter Expression: ";
    getline(std::cin, expression);

    if(isBalanced(expression)){
        std::cout << "Expression is VALID." << std::endl;
    }else{
        std::cout << "Expression is INVALID." << std::endl;
    }
    return 0;
}




