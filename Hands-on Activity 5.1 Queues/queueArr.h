#ifndef QUEUEARRAY_H 
#define QUEUEARRAY_H
#include <iostream>

template <typename T>
class Queue{
private: 
    // data members:
    T* q_array;
    int q_capacity;
    int q_size;
    int q_front;
    int q_back;

public:
    // constructor
    Queue(int capacity){
        q_capacity = capacity;
        q_size = 0;
        q_front = 0;
        q_back = -1;
        q_array = new T[q_capacity];
    }

    // empty operation:
    bool empty() const{
        if (q_size == 0){
            return true;
        }
        return false;
    }

    // size operation:
    int size() const{
        return q_size;
    }

    // clear operation:
    void clear(){
        q_size = 0;
        q_front =  0;
        q_back = -1;
    }

    // front operation:
    T front() const{
        if (empty()){
            std::cout << "Queue is empty." << std::endl;
            return T();
        }
        return q_array[q_front];
    }

    // back operation:
    T back() const{
        if (empty()){
            std::cout << "Back queue is empty." << std::endl;
            return T();
        }
        return q_array[q_back];
    }

    // enqueue operation:
    void enqueue(T newData){
        // checks if the queue is full
        if (q_size == q_capacity){
            std::cout << "Queue is full." << std::endl;
            return;
        }
        // inserting into an empty queue
        if (q_size == 0){
            q_front = 0;
            q_back = 0;
        }else{
            // circular
            q_back = (q_back + 1) % q_capacity;
        }
        q_array[q_back] = newData;
        q_size++;
    }

    // dequeue operation:
    void dequeue(){
        // check if queueu is empty
        if (empty()){
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        // queue (1 item)
        if (q_size == 1){
            q_front = 0;
            q_back = -1;
            q_size = 0;
            return;
        }
        // move in front
        q_front = (q_front + 1) % q_capacity;
        q_size--;
    }

    // copy constructor operator:
    Queue(const Queue& other){
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        q_array = new T[q_capacity];
        // copy the entire array
        for (int i = 0; i < q_capacity; i++){
            q_array[i] = other.q_array[i];
        }
    }

    // copy assignment operator:
    Queue& operator=(const Queue& other){
        // check if it's assigning to itself
        if (this == &other){
            return *this;
        }
        // delete existing array
        delete[] q_array;
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;
        // create new array
        q_array = new T[q_capacity];
        // copy the entire array
        for (int i = 0; i < q_capacity; i++){
            q_array[i] = other.q_array[i];
        }
        return *this;
    }

    // destructor operator
    ~Queue(){
        delete[] q_array;
    }
};

#endif
