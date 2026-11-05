
#include <iostream>
#include <algorithm>

int getMinSteps(int n){
    int dp[1001], i;
    dp[1] = 0; 
    for (i = 2; i <= n; i++){

        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0)
            dp[i] = std::min(dp[i], 1 + dp[i / 2]);
        if (i % 3 == 0)
            dp[i] = std::min(dp[i], 1 + dp[i / 3]);
    }

    return dp[n];
}

int main (){
    int n;
    
    std::cout << "--- BOTTOM UP DP ---" << std::endl;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n < 1 || n > 1000){
        std::cout << "Invalid input. Enter a number from 1 - 1000."; 
        return 0;
    }

    std::cout << "Minimum number of steps: " << getMinSteps(n) << std::endl;

    return 0;
}


