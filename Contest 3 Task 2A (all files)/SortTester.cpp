#include "SortTester.h"
#include "SortFunctions.h"
#include <chrono>
#include <vector>

double SortTester::measureMergeSortTime(std::vector<int>& array, int size) {
  const int numTrials = 10;
  long long totalTime = 0;

  for (int trial = 0; trial < numTrials; ++trial) {
    std::vector<int> arrayToSort = array;
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arrayToSort, 0, arrayToSort.size() - 1);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    totalTime += std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
  }
  return static_cast<double>(totalTime) / numTrials;
}

double SortTester::measureHybridMergeSortTime(std::vector<int>& array, int size, int threshold) {
  const int numTrials = 10;
  long long totalTime = 0;

  for (int trial = 0; trial < numTrials; ++trial) {
    std::vector<int> arrayToSort = array;
    auto start = std::chrono::high_resolution_clock::now();
    hybridMergeSort(arrayToSort, 0, arrayToSort.size() - 1, threshold);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    totalTime += std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
  }
  return static_cast<double>(totalTime) / numTrials;
}
