
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <random>

using Clock = std::chrono::steady_clock;

// BUBBLE SORT
void bubbleSort(std::vector<int>& a) {
    int n = static_cast<int>(a.size());

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

// MERGE FUNCTION
void merge(std::vector<int>& a, std::vector<int>& temp,
           int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {
        temp[k++] = a[j++];
    }

    for (int p = left; p <= right; p++) {
        a[p] = temp[p];
    }
}

// MERGE SORT
void mergeSort(std::vector<int>& a, std::vector<int>& temp,
               int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(a, temp, left, mid);
    mergeSort(a, temp, mid + 1, right);
    merge(a, temp, left, mid, right);
}

// MEASURE BUBBLE SORT IN DECIMAL MICROSECONDS
double measureBubble(std::vector<int> a) {
    auto start = Clock::now();

    bubbleSort(a);

    auto end = Clock::now();

    std::chrono::duration<double, std::micro> elapsed = end - start;

    return elapsed.count();
}

// MEASURE MERGE SORT IN DECIMAL MICROSECONDS
double measureMerge(std::vector<int> a) {
    std::vector<int> temp(a.size());

    auto start = Clock::now();

    if (!a.empty()) {
        mergeSort(a, temp, 0, static_cast<int>(a.size()) - 1);
    }

    auto end = Clock::now();

    std::chrono::duration<double, std::micro> elapsed = end - start;

    return elapsed.count();
}

// RUN BOTH ALGORITHMS ON THE SAME INPUT
void runTest(const std::vector<int>& data, const char* caseName) {
    double bubbleTime = measureBubble(data);
    double mergeTime = measureMerge(data);

    std::cout << "\n" << caseName << "\n";

    std::cout << "Input Size: " << data.size() << '\n';

    std::cout << "Bubble Sort: "
              << bubbleTime << " microseconds\n";

    std::cout << "Merge Sort:  "
              << mergeTime << " microseconds\n";
}

int main() {
    int sizes[] = {100, 1000, 10000};

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 100000);
    std::cout << std::fixed << std::setprecision(3);

    std::cout << "   BUBBLE SORT VS MERGE SORT\n";

    for (int n : sizes) {
        std::vector<int> randomData(n);

        for (int& x : randomData) {
            x = dist(rng);
        }

        std::vector<int> bestCase = randomData;
        std::sort(bestCase.begin(), bestCase.end());

        std::vector<int> worstCase = bestCase;
        std::reverse(worstCase.begin(), worstCase.end());

        std::cout << std::endl;
        std::cout << "INPUT SIZE: " << n << '\n';
       
        runTest(bestCase, "BEST CASE (SORTED)");
        runTest(worstCase, "WORST CASE (REVERSE)");
    }

    return 0;
}
