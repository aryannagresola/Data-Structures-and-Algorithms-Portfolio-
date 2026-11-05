
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using Clock = std::chrono::steady_clock;

// LINEAR SEARCH
int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

// BINARY SEARCH
// The array must be sorted.
int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

// MEASURE LINEAR SEARCH IN MICROSECONDS
double measureLinear(const std::vector<int>& arr, int target) {
    auto start = Clock::now();

    linearSearch(arr, target);

    auto end = Clock::now();

    std::chrono::duration<double, std::micro> elapsed = end - start;

    return elapsed.count();
}

// MEASURE BINARY SEARCH IN MICROSECONDS
double measureBinary(const std::vector<int>& arr, int target) {
    auto start = Clock::now();

    binarySearch(arr, target);

    auto end = Clock::now();

    std::chrono::duration<double, std::micro> elapsed = end - start;

    return elapsed.count();
}

int main() {
    int sizes[] = {1000, 10000, 100000};

    // Target is outside the array, ensuring worst-case searches.
    const int target = -1;

    std::cout << std::fixed << std::setprecision(3);

    std::cout << "BINARY SEARCH VS LINEAR SEARCH\n";
    std::cout << "Worst-Case Execution Time\n";
    std::cout << "---------------------------------------------\n";

    std::cout << "Input Size | Binary Search | Linear Search\n";
    std::cout << "---------------------------------------------\n";

    for (int n : sizes) {
        // Create a sorted array: 0, 1, 2, ..., n-1
        std::vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        // Repeat measurements to reduce timer noise.
        const int repetitions = 100;
        double binaryTotal = 0.0;
        double linearTotal = 0.0;

        for (int r = 0; r < repetitions; r++) {
            binaryTotal += measureBinary(arr, target);
            linearTotal += measureLinear(arr, target);
        }

        double binaryAverage = binaryTotal / repetitions;
        double linearAverage = linearTotal / repetitions;

        std::cout << n << " | "
                  << binaryAverage << " microseconds | "
                  << linearAverage << " microseconds\n";
    }

    std::cout << "---------------------------------------------\n";

    return 0;
}
