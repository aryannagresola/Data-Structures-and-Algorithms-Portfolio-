#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "node.h"
#include "searchingAlgo.h"
#include <algorithm>

const int max_size = 50;

int main() {

    //generate
    int dataset[max_size];
    srand(time(0));
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand() % 100;
    }
    std::sort(dataset, dataset + max_size);

    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;
    int userInput;
    std::cout << "What number to number to search? ";
    std::cin >> userInput;
    // testing
    std::cout << "Array Linear Search result is: ";
    linearSearchArr(max_size, userInput, dataset);
    std::cout << "Array Binary Search result is: ";
    binarySearchArr(max_size, userInput, dataset);

    // create linked list: Y A N N A
    Node<char>* name1 = new_node('Y');
    Node<char>* name2 = new_node('A');
    Node<char>* name3 = new_node('N');
    Node<char>* name4 = new_node('N');
    Node<char>* name5 = new_node('A');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = nullptr;

    // linear
    std::cout << "Linked List Linear Result is (Y): ";
    linearSearchLL(name1, 'Y');
    std::cout << "Linked List Linear Result is (X): ";
    linearSearchLL(name2, 'X');

    // sorted linked list binary
    Node<int>* node1 = new_node(5);
    Node<int>* node2 = new_node(10);
    Node<int>* node3 = new_node(15);
    Node<int>* node4 = new_node(20);
    Node<int>* node5 = new_node(25);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    // testing get mid:
    Node<int>* middle = getMiddle<int>(node1, nullptr);
    std::cout << "Middle Node is: " << middle->data << std::endl;

    // binary:
    std::cout << "Linked List Binary Search result is: ";
    binarySearchLL(node1, 5);

    return 0;

    

}