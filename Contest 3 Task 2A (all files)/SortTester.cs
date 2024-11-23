#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <algorithm>
#include <numeric> // Для std::accumulate

class SortTester
{
    private:
    // Функция для многократного замера времени
    long long measureTime(
        std::function<void(std::vector<int>&, int, int)> sortFunc,
        std::vector<int> arr, int left, int right, int trials = 5
    ) {
        std::vector<long long> times;

        for (int i = 0; i<trials; ++i) {
            auto start = std::chrono::high_resolution_clock::now();
    sortFunc(arr, left, right);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());
        }

// Усреднённое время
return std::accumulate(times.begin(), times.end(), 0LL) / trials;
    }

    long long measureHybridTime(
        std::function<void(std::vector<int>&, int, int, int)> sortFunc,
        std::vector<int> arr, int left, int right, int threshold, int trials = 5
    ) {
    std::vector < long long> times;

    for (int i = 0; i < trials; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();
        sortFunc(arr, left, right, threshold);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());
    }

    // Усреднённое время
    return std::accumulate(times.begin(), times.end(), 0LL) / trials;
}

public:
    // Тестирование стандартного MERGE SORT
    void testMergeSort(
        std::function<void(std::vector<int>&, int, int)> mergeSortFunc,
        ArrayGenerator & generator,
        const std::vector<int>& sizes
    ) {
    std::cout << "Testing MergeSort...\n";
    for (int size : sizes)
    {
        std::cout << "Array size: " << size << "\n";

        auto randomArray = generator.getRandomArray(size);
        auto reverseArray = generator.getReverseSortedArray(size);
        auto nearlySortedArray = generator.getNearlySortedArray(size);

        std::cout << "Random array: "
                  << measureTime(mergeSortFunc, randomArray, 0, size - 1) << " µs\n";

        std::cout << "Reverse sorted array: "
                  << measureTime(mergeSortFunc, reverseArray, 0, size - 1) << " µs\n";

        std::cout << "Nearly sorted array: "
                  << measureTime(mergeSortFunc, nearlySortedArray, 0, size - 1) << " µs\n";
    }
}

// Тестирование MERGE+INSERTION SORT
void testHybridMergeSort(
    std::function<void(std::vector<int>&, int, int, int)> hybridSortFunc,
        ArrayGenerator & generator,
        const std::vector<int>& sizes,
        const std::vector<int>& thresholds
    ) {
    std::cout << "Testing HybridMergeSort...\n";
    for (int size : sizes)
    {
        for (int threshold : thresholds)
        {
            std::cout << "Array size: " << size << ", Threshold: " << threshold << "\n";

            auto randomArray = generator.getRandomArray(size);
            auto reverseArray = generator.getReverseSortedArray(size);
            auto nearlySortedArray = generator.getNearlySortedArray(size);

            std::cout << "Random array: "
                      << measureHybridTime(hybridSortFunc, randomArray, 0, size - 1, threshold)
                      << " µs\n";

            std::cout << "Reverse sorted array: "
                      << measureHybridTime(hybridSortFunc, reverseArray, 0, size - 1, threshold)
                      << " µs\n";

            std::cout << "Nearly sorted array: "
                      << measureHybridTime(hybridSortFunc, nearlySortedArray, 0, size - 1, threshold)
                      << " µs\n";
        }
    }
}
};


