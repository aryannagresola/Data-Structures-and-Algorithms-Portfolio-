#include <iostream>
#include <string>
#include "printer.h"

int main(){
    Printer<Job> printer;

    int choice;
    int nextJobID = 101;

    do{
        std::cout << std::endl;
        std::cout << "--- SHARED PRINTER SYSTEM ---" << std::endl;
        std::cout << "1. Add Print Job" << std::endl;
        std::cout << "2. Display Queue" << std::endl;
        std::cout << "3. Search Job" << std::endl;
        std::cout << "4. Peek Next Job" << std::endl;
        std::cout << "5. Printer Status" << std::endl;
        std::cout << "6. Process Next Job" << std::endl;
        std::cout << "7. Process All Jobs " << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice){
            case 1: {
                std::string user;
                int pages;

                std::cout << "--- ADD PRINT JOB --- " << std::endl;
                std::cout << "Assigned Job ID: " << nextJobID << std::endl;

                std::cin.ignore();

                std::cout << "Enter Username: ";
                std::getline(std::cin, user);
                std::cout << "Enter number of pages: ";
                std::cin >> pages;

                Job job(nextJobID, user, pages);
                printer.addJob(job); 
                nextJobID++;
                break;
            }
            case 2: 
                printer.displayQueue();
                break;
            case 3: {
                int id;
                std::cout << "Enter Job ID to search: ";
                std::cin >> id;
                printer.searchJob(id);
                break;
            }
            case 4: 
                printer.peekNextJob();
                break;
            case 5:
                printer.printerStatus();
                break;
            case 6:
                printer.processNextJob();
                break;
            case 7:
                printer.processJobs();
            case 8: 
                std::cout << "Exiting Shared Printer System..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        
    } while (choice != 8);

    return 0;
}