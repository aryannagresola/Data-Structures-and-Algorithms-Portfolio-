#ifndef PRINTER_H
#define PRINTER_H
#include <iostream>
#include <string>

class Job{
public:
    int id;
    std::string user;
    int pages;

    Job(){
        id = 0;
        user = " ";
        pages = 0;
    }

    Job(int i, std::string u, int p){
        id = i; 
        user = u;
        pages = p;
    }
};

template <class T>
class Node{
public:
    T data;
    Node<T>* next;

    Node(T value){
        data = value;
        next = nullptr;
    }
};

template <class T>
class Printer{
private: 
    Node<T>* front;
    Node<T>* rear;
public: 
    // constructor
    Printer(){
        front = nullptr;
        rear = nullptr;
    }
    // checking if the queue is empty
    bool isEmpty(){
        return front == nullptr;
    }
    // add print job
    void addJob(T job){
        Node<T>* newNode = new Node<T>(job);
        if (isEmpty()){
            front = newNode;
            rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << std::endl;
        std::cout << "Print Job Added Successfully!" << std::endl;
        std::cout << "Job ID: " << job.id << std::endl;
        std::cout << "User: " << job.user << std::endl;
        std::cout << "Pages: " << job.pages << std::endl;
    }
    // display queue
    void displayQueue(){
        if (isEmpty()){
            std::cout << "Printer Queue is empty." << std::endl;
            return;
        }
        Node<T>* temp = front;
        std::cout << "--- PENDING PRINT JOBS ---" << std::endl;

        while (temp != nullptr){
            std::cout << "Job ID: " << temp->data.id << std::endl;
            std::cout << "User: " << temp->data.user << std::endl;
            std::cout << "Pages: " << temp->data.pages << std::endl;
            std::cout << std::endl;

            temp = temp->next;
        }
    }
    // search job
    void searchJob(int id){
        if (isEmpty()){
            std::cout << "Printer Queue is empty." << std::endl;
            return;
        }
        Node<T>* temp = front;

        while (temp != nullptr){
            if (temp->data.id == id){
                std::cout << "Job Found!" << std::endl;
                std::cout << "Job ID: " << temp->data.id << std::endl;
                std::cout << "User: " << temp->data.user << std::endl;
                std::cout << "Pages: " << temp->data.pages << std::endl;
                return;
            }
            temp = temp->next;
        }
        std::cout << "Job ID not found. Please try again.";
    }
    // peek next job in queue
    void peekNextJob(){
        if (isEmpty()){
            std::cout << "Printer Queue is empty." << std::endl;
            return;
        }
        std::cout << "--- NEXT PRINT JOB ---" << std::endl;
        std::cout << "Job ID: " << front->data.id << std::endl;
        std::cout << "User: " << front->data.user << std::endl;
        std::cout << "Pages: " << front->data.pages << std::endl;
    }
    // printer status
    void printerStatus(){
        int jobs = 0;
        int pages = 0;

        Node<T>* temp = front;
        while (temp != nullptr){
            jobs++;
            pages += temp->data.pages;
            temp = temp->next;
        }
        std::cout << "--- PRINTER STATUS ---" << std::endl;
        if (isEmpty()){
            std::cout << "Status: Idle (Inactive)" << std::endl;
            std::cout << "Pending Jobs: 0" << std::endl;
            std::cout << "Total Pages: 0" << std::endl;
        }else{
            std::cout << "Status: Busy" << std::endl;
            std::cout << "Pending Jobs: " << jobs << std::endl;
            std::cout << "Total Pages: " << pages << std::endl;
            std::cout << "Next User: " << front->data.user << std::endl;
        }
    }
    // process next job 
    void processNextJob(){
        if (isEmpty()){
            std::cout << "Printer Queue is empty." << std::endl;
            return;
        }
        Node<T>* temp = front;

        std::cout << "--- PRINTING JOB ---" << std::endl;
        std::cout << "Job ID: " << temp->data.id << std::endl;
        std::cout << "User: " << temp->data.user << std::endl;
        std::cout << "Pages: " << temp->data.pages << std::endl;
        std::cout << "Status: Completed" << std::endl;

        front = front->next;
        delete temp;
        if (front == nullptr){
            rear = nullptr;
        }
        std::cout << "Job Successfully Printed!" << std::endl;
    }
    // process all jobs
    void processJobs(){
        if (isEmpty()){
            std::cout << "Printer Queue is empty." << std::endl;
            return;
        }
        std::cout << "--- PROCESSING ALL PRINT JOBS --- " << std::endl;
        while (front != nullptr){
            std::cout << "Printing Job..." << std::endl;
            std::cout << "Job ID: " << front->data.id << std::endl;
            std::cout << "User: " << front->data.user << std::endl;
            std::cout << "Pages: " << front->data.pages << std::endl;
            std::cout << "Status: Completed" << std::endl;
            
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        std::cout << "All Print Jobs Have Been Processed." << std::endl;
    }
};

#endif