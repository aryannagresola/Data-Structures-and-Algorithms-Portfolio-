#ifndef SIMPLY_LL_H
#define SIMPLY_LL_H

template <typename T>

class SimplyList{
    public:
        T data;
        SimplyList<T> *next = nullptr;
};


template <typename T> // create a template 
void listTraversal(SimplyList<T>* head){
    if(head == nullptr){
        std::cout << "List is empty." << std::endl;
        return;
    }

    while(head != nullptr){
        std::cout << head->data;
        if(head->next != nullptr){
            std::cout <<" -> ";
        }
        head = head->next;
    }
}

// INSERTION
template <typename T> // create a template
void sllinsertHead(T newData, SimplyList<T>** currentHead){
    // allocate memory
    SimplyList<T>* newNode = new SimplyList<T>;
    // put data to new node
    newNode->data = newData;
    // set next of the new node to the previous head
    newNode->next = *currentHead;
    // reset head to point to the new node 
    *currentHead= newNode;
}

template <typename T> // create a template
void sllGeneralInsert(T newData, SimplyList<T>* prevNode){ 
    if(prevNode == nullptr){
        std::cout << "Previous Node cannot be null." << std::endl;
        return;
    }
    // allocate new node
    SimplyList<T>* newNode = new SimplyList<T>;
    // store in the new node
    newNode->data = newData;
    // point new node to the node previous node was pointing to
    newNode->next = prevNode->next;
    // point previous node to the new node
    prevNode->next = newNode;

}

template <typename T>
void sllInsertEnd(T newData, SimplyList<T>** head){
    // allocate new node
    SimplyList<T>* newNode = new SimplyList<T>;
    // dereference to the head node
    SimplyList<T>* currentNode = *head;
    // store data into a new node
    newNode->data = newData;
    // point next of new node to null
    newNode->next = nullptr;
    // traverse the list until next of the node is nullptr
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    // point the next of the current node to the new node
    currentNode-> next = newNode;
}

template <typename T>
void sllDeleteNode(T findData, SimplyList<T>** head){
    // check if there is no list to be deleted
    if(*head == nullptr) return;
    // find previous node of the node to be deleted
    SimplyList<T>* currNode = *head;
    SimplyList<T>* prevNode = nullptr;

    // searching loop
    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    // data was not found:
    if (currNode == nullptr) return;

    //what if the node to be deleted is the head node?
    if(prevNode == nullptr){
        *head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    // we have to delete the node
    delete currNode;

}

template <typename T>
void sllDeleteList(SimplyList<T>** head){
    SimplyList<T>* current = *head;

    while(current != nullptr){
        SimplyList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}
#endif