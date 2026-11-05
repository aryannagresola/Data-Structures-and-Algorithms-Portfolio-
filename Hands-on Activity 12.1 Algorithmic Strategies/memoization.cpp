#include <iostream>
#include <algorithm>

int memo[1001];

int getMinSteps(int n){
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];

    int r = 1 + getMinSteps(n - 1);

    if (n % 2 == 0)
        r = std::min(r, 1 + getMinSteps (n / 2));

    if (n % 3 == 0)
        r = std::min(r, 1 + getMinSteps (n / 3));

    memo[n] = r;
    return r;
}

int main (){
    int n;

    std::cout << "--- MEMOIZATION ---" << std::endl;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    while (n < 1 || n > 1000){
        std::cout << "Invalid input. Enter a number from 1 - 1000. ";
        return 0;
    }

    for (int i = 0; i <= n; i++){
        memo[i] = -1;
    }

    std::cout << "Minimum number of steps: " << getMinSteps(n) << std::endl;
    
    return 0;

}





