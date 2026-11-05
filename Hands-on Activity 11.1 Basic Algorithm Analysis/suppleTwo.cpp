#include <iostream>
#include <chrono>

long long rpower(int x, int n){
    if (n == 0)
        return 1;
    return x * rpower(x, n - 1);
}


long long brpower(int x, int n) {
    if (n == 0)
        return 1;
    long long half = brpower(x, n / 2);

    if (n % 2 == 0)
        return half * half;
    return x * half * half;
}


int main(){

    int x = 2;
    int n = 10;

    auto start = std::chrono::steady_clock::now();

    long long result1 = rpower(x, n);

    auto end = std::chrono::steady_clock::now();

    auto time1 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    start = std::chrono::steady_clock::now();

    long long result2 = brpower(x, n);

    end = std::chrono::steady_clock::now();

    auto time2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();


    std::cout << "x = " << x << ", n = " << n << std::endl;
    std::cout << "rpower result: " << result1 << std::endl;
    std::cout << "rpower time: " << time1 << " microseconds" << std::endl;
    std::cout << std::endl;

    std::cout << "brpower result: " << result2 << std::endl;
    std::cout << "brpower time: " << time2 << " microseconds" << std::endl;

    return 0;
}