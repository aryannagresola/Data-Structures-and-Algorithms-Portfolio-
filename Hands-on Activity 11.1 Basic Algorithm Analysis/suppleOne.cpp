#include <iostream>
#include <vector>
#include <chrono>

bool Unique(std::vector<int> A) {

    int n = A.size();

    for (int i = 0; i <= n - 1; i++) {

        for (int j = i + 1; j <= n - 1; j++) {

            if (A[i] == A[j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {

    int sizes[] = {1000, 10000, 100000};

    for (int size : sizes) {

        std::vector<int> A;

        for (int i = 0; i <= size - 1; i++) {
            A.push_back(i);
        }

        auto start = std::chrono::steady_clock::now();

        bool result = Unique(A);

        auto end = std::chrono::steady_clock::now();

        auto time = std::chrono::duration_cast<std::chrono::microseconds>
                    (end - start).count();

        std::cout << "Input Size: " << size << std::endl;
        std::cout << "Result: "
                  << (result ? "Unique" : "Not Unique")
                  << std::endl;
        std::cout << "Execution Time: "
                  << time << " microseconds"
                  << std::endl;

        std::cout << "------------------------" << std::endl;
    }

    return 0;
}