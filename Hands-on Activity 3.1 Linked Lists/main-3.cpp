#include <iostream>
#include "double_LL.h"

int main(){

    DoubleList<char>* head = createNode('C');
    DoubleList<char>* second = createNode('P');
    DoubleList<char>* third = createNode('E');

    //link nodes together
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "TRAVERSAL TESTING " << std::endl;
    dllTraverse(head);
    std::cout << std::endl;

    std::cout << "INSERT HEAD TESTING " << std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);
    std::cout << std::endl;

    std::cout << "INSERT END TESTING " << std::endl;
    dllInsertEnd('I', head);
    dllTraverse(head);
    std::cout << std::endl;

    std::cout << "INSERT ANY TESTING" << std::endl;
    dllInsert('Y', second);
    dllTraverse(head);
    std::cout << std::endl;

    std::cout << "DELETE TESTING" << std::endl;
    dllDelete(&head, head); // Delete P
    dllTraverse(head);
    std::cout << std::endl;

    std::cout << "DELETE ALL TESTING" << std::endl;
    dllDeleteAll(&head);
    dllTraverse(head);
    std::cout << std::endl;

    return 0;
}