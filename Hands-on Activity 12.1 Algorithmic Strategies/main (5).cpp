#include <iostream>

const int ROWS = 4;
const int COLS = 4;

int matrix[ROWS][COLS] ={
    {7, 4, 8, 5},
    {1, 3, 7, 6},
    {5, 3, 4, 6},
    {2, 2, 7, 2}
};

int targetCost;
int countPaths(int row, int col, int cost){
    if (row >= ROWS || col >= COLS) {
        return 0;
    }

    cost += matrix[row][col];

    if (cost > targetCost){
        return 0;
    }
    if (row == ROWS - 1 && col == COLS - 1){
        return (cost == targetCost) ? 1 : 0;
    }

    // where recursion happens:
    int rightPaths = countPaths(row, col + 1, cost);
    int downPaths = countPaths(row + 1, col, cost);
    return rightPaths + downPaths;
}

int main (){
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "Enter target cost: ";
    std::cin >> targetCost;

    if (targetCost < 0){
        std::cout << "Target cost must be non-negative." << std::endl;
        return 1;
    }

    int result = countPaths(0, 0, 0);
    std::cout << "Target cost: " << targetCost << std::endl;
    std::cout << "Number of valid paths: " << result << std::endl;

    return 0;
}


