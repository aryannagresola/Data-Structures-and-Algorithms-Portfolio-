#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

int main(){
    // create an object:
    std::queue<char> myQ;

    myQ.push('Y');
    myQ.push('A');
    myQ.push('N');
    myQ.push('N');
    myQ.push('A');
    
    // try all member function:
    // size
    std::cout << "Queue Size: " << myQ.size() << std::endl;
    // front
    std::cout << "Queue Front: " << myQ.front() << std::endl;
    // back
    std::cout << "Queue Back: " << myQ.back() << std::endl;
    // display original:
    std::cout << "Original Queue: ";
    display(myQ);
    // pop
    myQ.pop();
    std::cout << "After pop operation: ";
    display(myQ);
    // push
    myQ.push('!');
    std::cout << "After push operation: ";
    display(myQ);
    // empty
    if (myQ.empty())
        std::cout << "Queue is empty. " << std::endl;
    else    
        std::cout << "Queue is not empty." << std::endl;

    return 0;
}
void display(std::queue<char> copyQ){
    // create a copy of the queue that was passed
    std::queue<char> c = copyQ;
    while(!c.empty()){
        std::cout << " " << c.front();
        c.pop();
    }
    std::cout << std::endl;
}

