#include <iostream>
#include "Tree.h"

int main(){

    //create root:
    Tree<char>* tree = new Tree<char>('A');

    // children of A:
    tree->insertChild('B');
    tree->insertChild('C');
    tree->insertChild('D');
    tree->insertChild('E');
    tree->insertChild('F');
    tree->insertChild('G');

    // child of D:
    Tree<char>* D = tree->search('D');
    D->insertChild('H');

    // child of E:
    Tree<char>* E = tree->search('E');
    E->insertChild('I');
    E->insertChild('J');
    
    // children of J:
    Tree<char>* J = tree->search('J');
    J->insertChild('P');
    J->insertChild('Q');

    // children of F:
    Tree<char>* F = tree->search('F');
    F->insertChild('K');
    F->insertChild('L');
    F->insertChild('M');

    // child of G:
    Tree<char>* G = tree->search('G');
    G->insertChild('N');

    // TASK 3.2:
    std::cout << "--- TREE TRAVERSAL (OUTPUT) ---" << std::endl;

    // pre-order:
    std::cout << "Pre-Order Output: ";
    tree->preOrder();
    std::cout << std::endl;

    // in-order:
    std::cout << "In-Order Output: ";
    tree->inOrder();
    std::cout << std::endl;

    // post-order:
    std::cout << "Post-Order: ";
    tree->postOrder();
    std::cout << std::endl;

    // TASK 3.3:
    std::cout << std::endl;
    std::cout << "--- FIND DATA ---" << std::endl;

    // choice 1: pre-order
    tree->findData(1, 'G');

    //choice 2: in-order:
    tree->findData(2, 'F');

    //choice 3: post-order:
    tree->findData(3, 'H');


    // TASK 3.4
    // inserting O as child of G:
    G->insertChild('O');
    
    std::cout << std::endl;
    std::cout << "--- ADDING O AS A CHILD OF G ---" << std::endl;

    tree->findData(1, 'O');
    // pre-order:
    std::cout << "Pre-Order Output (after adding O): ";
    tree->preOrder();
    std::cout << std::endl;

    // in-order:
    std::cout << "In-Order Output (after adding O): ";
    tree->inOrder();
    std::cout << std::endl;

    // post-order:
    std::cout << "Post-Order Output (after adding O): ";
    tree->postOrder();
    std::cout << std::endl;

    return 0;
}


