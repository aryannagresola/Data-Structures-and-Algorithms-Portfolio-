#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

//TEMPLATING
template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T> *next = nullptr;
        DoubleList<T> *prev = nullptr;

};

// Function to Create a new node
template <typename T>
DoubleList<T>* createNode(T newData) {
    // Dynamically allocate memory for the new node
    DoubleList<T>* newNode = new DoubleList<T>;
    
    newNode->data = newData; 
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // Return the address of the new node
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T> *currentNode) {

    DoubleList<T> *tail;

    if(currentNode == nullptr){
        std::cout << "The list is empty.";
        return;
    }
    
    // Forward Traversal
    std::cout << "Forward Traversal: " << std::endl;
    // moves toward the last node 
    while(currentNode != nullptr){
        // print the data
        std::cout << currentNode->data<<" ";
        //saved the current node as the last visited node
        tail = currentNode;
        // move to the next node
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
    
    //backward traversing:
    std::cout << "Backward: " << std::endl;
    while(tail != nullptr){
        //printed the data
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
    std::cout << std::endl;
}

template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    // create a node
    DoubleList<T>* newNode = createNode(newData);
    //new node should point to the current head 
    newNode->next = *currentHead;
    // current head should point back to the new
    if(*currentHead != nullptr){
        (*currentHead)->prev = newNode;
    }
    // update the header pointer
    *currentHead = newNode;
}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T> *currentHead){

    //create new node 
    DoubleList<T> *newNode = createNode(newData);
    //traverse to the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }
    currentHead->next = newNode;
    //connect to the new node 
    newNode->prev = currentHead;
}

template <typename T>
void dllInsert(T newData, DoubleList<T>* currentNode){
    // will check if current node exists
    if(currentNode == nullptr){
        return;
    }
    // create new node
    DoubleList<T>* newNode = createNode(newData);
    // connect new node
    newNode->next = currentNode->next;
    newNode->prev = currentNode;
    // if not inserting in the end
    if(currentNode->next != nullptr){
        currentNode->next->prev = newNode;
    }
    currentNode->next = newNode;
}

template <typename T>
void dllDelete(DoubleList<T>** currentHead, DoubleList<T>* deleteNode){
    if(deleteNode == nullptr){
        return;
    }
    // if deleting the head
    if(deleteNode == *currentHead){
        *currentHead = deleteNode->next;
    }
    // Connect previous node
    if(deleteNode->prev != nullptr){
        deleteNode->prev->next = deleteNode->next;
    }
    // Connect next node
    if(deleteNode->next != nullptr){
        deleteNode->next->prev = deleteNode->prev;
    }
    delete deleteNode;

}

template <typename T>
void dllDeleteAll(DoubleList<T>** currentHead){
    DoubleList<T>* temp;

    while(*currentHead != nullptr){
        temp = *currentHead;
        *currentHead = (*currentHead)->next;
        delete temp;
    }
}

#endif // DOUBLE_LL_H