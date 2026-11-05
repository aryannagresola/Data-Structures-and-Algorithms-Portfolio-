#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include "sortingAlgo.h"

int main(){
    const int ARR_SIZE = 101;
    int voteArr[ARR_SIZE];
    int voteCount[5] = {0, 0, 0, 0, 0};

    std::string candidate[5] = {
        "Bo Dolton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    srand(time(NULL));
    // generate random votes:
    for(int i = 0; i < ARR_SIZE; i++){
        voteArr[i] = rand() % 5 + 1;
    }

    // displays candidate:
    std::cout << "--- LIST OF CANDIDATES ---" << std::endl;
    for(int i = 0; i < 5; i++ ){
        std::cout << i + 1 << ". " << candidate[i] << std::endl;
    }
    std::cout << std::endl;

    // display unsorted votes array:
    std::cout << "--- UNSORTED VOTES ARRAY ---" << std::endl;
    for(int i = 0; i < ARR_SIZE; i++){
        std::cout << voteArr[i] << " ";
        if((i + 1) % 20 == 0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    // sorting the array using insertion sort:
    insertionSort(voteArr, ARR_SIZE);
    // displaying sorted votes array:
    std::cout << "---SORTED VOTES ARRAY---" << std::endl;
    for(int i = 0; i < ARR_SIZE; i++){
        std::cout << voteArr[i] << " ";
        if((i + 1) % 20 == 0){
            std::cout << std::endl;
        }
    }

    // count the votes: 
    for(int i = 0; i < ARR_SIZE; i++){
        if(voteArr[i] == 1){
            voteCount[0]++;
        }
        else if(voteArr[i] == 2){
            voteCount[1]++;
        }
        else if(voteArr[i] == 3){
            voteCount[2]++;
        }
        else if(voteArr[i] == 4){
            voteCount[3]++;
        }
        else if(voteArr[i] == 5){
            voteCount[4]++;
        }

    }

    // display vote count:
    std::cout << std::endl;
    std::cout << "--- VOTE COUNT ---" << std::endl;
    for(int i = 0; i < 5; i++){
        std::cout << candidate[i] << " = " << voteCount[i] << " votes" << std::endl;
    }

    // determine the winner:
    int winner = 0;
    for(int i = 1; i < 5; i++){
        if(voteCount[i] > voteCount[winner]){
            winner = i;
        }
    }

    // display the finalized result:
    std::cout << std::endl;
    std::cout << "--- FINAL RESULT---" << std::endl;
    std::cout << "Winning Candidate: " << candidate[winner] << std::endl;
    std::cout << "Number of Votes: " << voteCount[winner] << std::endl;
    std::cout << "Congratulations!" << std::endl;

return 0;
}



