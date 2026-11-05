#ifndef TREE_H
#define TREE_H
#include <iostream>

template <typename T>
class Tree{
    private:
    T key;
    Tree<T>* firstChild;
    Tree<T>* nextSibling;

    bool findPreOrder(T value){
        if(key == value){
            return true;
        }
        Tree<T>* current = firstChild;
        while(current != nullptr){
            if(current->findPreOrder(value)){
                return true;
            }
            current = current->nextSibling;
        }
        return false;
    }

    bool findInOrder(T value){
        if(firstChild != nullptr){
            if(firstChild->findInOrder(value)){
                return true;
            }
        }
        if(key == value){
            return true;
        }
        Tree<T>* current = nullptr;
        if(firstChild != nullptr){
            current = firstChild->nextSibling;
        }
        while(current != nullptr){
            if(current->findInOrder(value)){
                return true;
            }
            current = current->nextSibling;
        }
        return false;
    }

    bool findPostOrder(T value){
        Tree<T>* current = firstChild;
        while(current != nullptr){
            if(current->findPostOrder(value)){
                return true;
            }
            current = current->nextSibling;
        }
        if(key == value){
            return true;
        }
        return false;
    }

    public:
    //constructor:
    Tree(T value);

    //insertion:
    void insertChild(T value);

    // searching:
    Tree<T>* search(T value);

    void preOrder();
    void inOrder();
    void postOrder();

    // find data:
    void findData(int choice, T value);

};

//define:
template <typename T>
Tree<T>::Tree(T value){
    key = value;
    firstChild = nullptr;
    nextSibling = nullptr;
}

// inserting a child:
template <typename T>
void Tree<T>::insertChild(T value){
    // creates a new child
    Tree<T>* newNode = new Tree<T>(value);

    // if there's no child:
    if(firstChild == nullptr){
        firstChild = newNode;
    }else{
        Tree<T>* current = firstChild;

        while(current->nextSibling != nullptr){
            current = current->nextSibling;
        }
        // adding the new node at the end
        current->nextSibling = newNode; 
    }
}

template <typename T>
Tree<T>* Tree<T>::search(T value){

    //check current node:
    if(key == value){
        return this;
    }

    //search children:
    Tree<T>* current = firstChild;

    while(current != nullptr){
        Tree<T>* found = current->search(value);
        if(found != nullptr){
            return found;
        }
        current = current->nextSibling;
    }
    return nullptr;
}

// pre-order:
template <typename T>
void Tree<T>::preOrder(){
    std::cout << key << " ";
    Tree<T>* current = firstChild;

    while(current != nullptr){
        current->preOrder();
        current = current->nextSibling;
    }
}

// in order:
template <typename T>
void Tree<T>::inOrder(){

    if(firstChild != nullptr){
        firstChild->inOrder();
    }

    std::cout << key << " ";
    Tree<T>* current = nullptr;

    if(firstChild != nullptr){
        current = firstChild->nextSibling;
    }

    while(current != nullptr){
        current->inOrder();
        current = current->nextSibling;
    }
}

// post order:
template <typename T>
void Tree<T>::postOrder(){

    Tree<T>* current = firstChild;

    while(current != nullptr){
        current->postOrder();
        current = current->nextSibling;
    }
    std::cout << key << " ";
}

// find data:
template <typename T>
void Tree<T>::findData(int choice, T value){
    bool found = false;

    // pre-order:
    if(choice == 1){
        found = findPreOrder(value);
    }
    // in order:
    else if(choice == 2){
        found = findInOrder(value);
    }

    // post-order:
    else if(choice == 3){
        found = findPostOrder(value);
    }

    if(found){
        std::cout << value << " was found!" << std::endl;
    }
}

#endif