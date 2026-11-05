#include <iostream>
#include "simply_LL.h"

int main(){

    //creating empty list
    SimplyList<char>* head = new SimplyList<char>;
    SimplyList<char>* second =new SimplyList<char>;
    SimplyList<char>* third = new SimplyList<char>;
    SimplyList<char>* fourth = new SimplyList<char>;
    SimplyList<char>* fifth = new SimplyList<char>;
    SimplyList<char>* sixth = new SimplyList<char>;

    
    //assign the data 
    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = fourth;

    fourth->data = '0';
    fourth->next = fifth;

    fifth->data = '1';
    fifth->next = sixth;

    sixth->data = '0';
    sixth->next = nullptr;
    
    // std::cout << head->next->data << std::endl;

    // listTraversal(head);
    std::cout << "Traversal: " << std::endl;
    listTraversal(head);
    std::cout << std::endl;

    std::cout << "\n Inserting a new node at the head. " << std::endl;
    sllinsertHead('G', &head);
    listTraversal(head);
    std::cout << std::endl;

    std::cout << "\n Inserting a new node at the any. " << std::endl;
    sllGeneralInsert('E', head->next->next);
    listTraversal(head);
    std::cout << std::endl; 

    // std::cout << "\n Inserting a new node at the end. " << std::endl;
    // sllInsertEnd('U', &head);
    // listTraversal(head);
    // std::cout << std::endl;
    
    std::cout << "\nDelete C:" << std::endl;
    sllDeleteNode('C', &head);
    listTraversal(head);
    std::cout << std::endl;

    std::cout << "\nDelete P:" << std::endl;
    sllDeleteNode('P', &head);
    listTraversal(head);
    std::cout << std::endl;

    std::cout << "\nFinal List:" << std::endl;
    listTraversal(head);
    std::cout << std::endl;

    std::cout << "\n Deleting all the head node: \n";
    sllDeleteList(&head);
    listTraversal(head);
    std::cout << std::endl;
    return 0;
}

