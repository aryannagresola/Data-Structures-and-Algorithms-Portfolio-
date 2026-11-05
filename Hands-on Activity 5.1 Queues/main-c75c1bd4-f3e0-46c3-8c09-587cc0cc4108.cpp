#include <iostream>
#include "queueLL.h"

int main(){
    // use front and back becasue this is a queue implementation
    qNode<char> *front = nullptr;
    qNode<char> *back = nullptr; 

    // enqueue
    enqueue('A', &front, &back);
    std::cout << front->data << " " << back->data <<std::endl;
    enqueue('R', &front, &back);
    std::cout << front->data << " " << back->data <<std::endl;
    enqueue('Y', &front, &back);
    std::cout << front->data << " " << back->data <<std::endl;
    enqueue('A', &front, &back);
    std::cout << front->data << " " << back->data <<std::endl;

    // dequeue
    dequeue(&front, &back);
    std::cout << front->data << " " << back->data <<std::endl;


    // checking front
    checkFront(&front);
    checkBack(&back);
    display(&front);

    return 0;
}