#include <iostream>
#include "queueArr.h"

int main(){

    int capacity;
    std::cout << "Enter queue capacity: ";
    std::cin >> capacity;
    // constructor
    Queue<char> queue(capacity);
    std::cout << "CONSTRUCTOR" << std::endl;
    std::cout << "Queue created successfully." << std::endl;

    // empty:
    std::cout << "Is Queue empty? " << (queue.empty()? "Yes" : "No") << std::endl;

    // size
    std::cout << "Size: " << queue.size() << std::endl;
    std::cout << std::endl;

    // enqueue
    std::cout << "ENQUEUE" << std::endl;
    queue.enqueue('A');
    std::cout << queue.front() << " " << queue.back() << std::endl;
    queue.enqueue('R');
    std::cout << queue.front() << " " << queue.back() << std::endl;
    queue.enqueue('Y');
    std::cout << queue.front() << " " << queue.back() << std::endl;
    queue.enqueue('A');
    std::cout << queue.front() << " " << queue.back() << std::endl;

    // checking front:
    std::cout << "Front: " << queue.front() << std::endl;

    // checking back:
    std::cout << "Back: " << queue.back() << std::endl;

    // checking size:
    std::cout << "Size: " << queue.size() << std::endl;
    std::cout << std::endl;


    // dequeue
    std::cout << "DEQUEUE" << std::endl;
    queue.dequeue();
    std::cout << "Front after dequeue: " << queue.front() << std::endl;
    std::cout << "Back after dequeue: " << queue.back() << std::endl;
    std::cout << "Size after dequeue: " << queue.size() << std::endl;
    std::cout << std::endl;

    // testing circular queue:
    std::cout << "CIRCULAR QUEUE TEST" << std::endl;
    queue.enqueue('N');
    std::cout << "Front: " << queue.front() << std::endl;
    std::cout << "Back: " << queue.back() << std::endl;
    std::cout << "Size: " << queue.size() << std::endl;
    std::cout << std::endl;

    // copy constructor:
    std::cout << "COPY CONSTRUCTOR" << std::endl;
    Queue<char> copiedQueue(queue);
    std::cout << "Copied Queue Front: " << copiedQueue.front() << std::endl;
    std::cout << "Copied Queue Back: " << copiedQueue.back() << std::endl;
    std::cout << "Copied Queue Size: " << copiedQueue.size() << std::endl;
    std::cout << std::endl;

    // copy assignment operator:
    std::cout << "COPY ASSIGNMENT OPERATOR" << std::endl;
    Queue<char> assignedQueue(capacity);
    assignedQueue = queue;

    std::cout << "Assigned Queue Front: " << assignedQueue.front() << std::endl;
    std::cout << "Assigned Queue Back: " << assignedQueue.back() << std::endl;
    std::cout << "Assigned Queue Size: " << assignedQueue.size() << std::endl;
    std::cout << std::endl;


    // clear:
    std::cout << "CLEAR" << std::endl;
    queue.clear();
    std::cout << "Size After Clear: " << queue.size() << std::endl;
    std::cout << "Is Queue empty? " << (queue.empty()? "Yes" : "No") << std::endl;
    std::cout << std::endl;

    // destructor
    std::cout << "DESTRUCTOR" << std::endl;
    std::cout << "It will automatically release." << std::endl;

    return 0;
}

