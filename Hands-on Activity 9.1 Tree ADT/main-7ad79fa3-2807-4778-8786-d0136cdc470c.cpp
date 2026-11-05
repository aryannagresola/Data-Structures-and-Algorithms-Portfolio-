#include <iostream>
#include "BST.h"

int main(){
    BinarySearchTree<int>* tree = new BinarySearchTree(2); // pivot value 

    tree->insert(3);
    tree->insert(9);
    tree->insert(18);
    tree->insert(0);
    tree->insert(1);    
    tree->insert(4);
    tree->insert(5);

    std::cout << "--- BINARY SEARCH TREE ---" << std::endl;
    
    // PRE-ORDER OUTPUT:
    std::cout << "Pre-Order Output: ";
    tree->preOrder();
    std::cout << std::endl;

    // IN-ORDER OUTPUT:
    std::cout << "In-Order Output: ";
    tree->inOrder();
    std::cout << std::endl; 

    // POST-ORDER OUTPUT:
    std::cout << "Post-Order Output: ";
    tree->postOrder();
    std::cout << std::endl;

    return 0;
}