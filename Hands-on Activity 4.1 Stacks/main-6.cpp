#include <iostream>
#include"listStack.h"

int main(){
    std::cout << " ------ PUSHING 'I' 'E' 'E' 'E' ------ \n";

    // pushing
    push('I');
    push('E');
    push('E');
    push('E');

    displayAll<char>();
    // display top
    Top<char>();
    std::cout << std::endl;

    // pop and print each element
    std::cout << " ------ POPPING 'I' 'E' 'E' 'E' ------ \n";
    while(!isEmpty<char>()){
        std::cout << "Popping: " << pop<char>() << std::endl;
    }
    // test stack underflow
    pop<char>();

    return 0;
}




