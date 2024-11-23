

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "ArrayGenerator.h"
#include "SortTester.h"
#include "SortFunctions.h"

void writeResultsToCSV(const std::string& filename, const std::vector<std::tuple<int, double, std::string>>& results) {
  std::ofstream file(filename);
  file << "Size,Time,Array Type\n";
  for (const auto& [size, time, arrayType] : results) {
    file << size << "," << time << "," << arrayType << "\n";
  }
  file.close();
}

void writeHybridResultsToCSV(const std::string& filename, const std::vector<std::tuple<int, int, double, std::string>>& results) {
  std::ofstream file(filename);
  file << "Size,Threshold,Time,Array Type\n";
  for (const auto& [size, threshold, time, arrayType] : results) {
    file << size << "," << threshold << "," << time << "," << arrayType << "\n";
  }
  file.close();
}

int main() {
  ArrayGenerator generator;
  SortTester tester;

  std::vector<int> sizes;
  for (int size = 500; size <= 10000; size += 100) {
    sizes.push_back(size);
  }

  std::vector<int> thresholds = { 5, 10, 15, 20, 30, 50 };

  // Merge Sort Results
  std::vector<std::tuple<int, double, std::string>> mergeSortResults;
  for (int size : sizes) {
    // Random Array
    std::vector<int> randomArray = generator.getRandomArray(size);
    double randomTime = tester.measureMergeSortTime(randomArray, size);
    mergeSortResults.emplace_back(size, randomTime, "Random Array");

    // Reversed Array
    std::vector<int> reversedArray = generator.getReversedArray(size);
    double reversedTime = tester.measureMergeSortTime(reversedArray, size);
    mergeSortResults.emplace_back(size, reversedTime, "Reversed Array");

    // Nearly Sorted Array
    std::vector<int> nearlySortedArray = generator.getNearlySortedArray(size, size / 10);  // 10% swaps
    double nearlySortedTime = tester.measureMergeSortTime(nearlySortedArray, size);
    mergeSortResults.emplace_back(size, nearlySortedTime, "Nearly Sorted Array");
  }

  // Save Merge Sort Results
  writeResultsToCSV("merge_sort_results.csv", mergeSortResults);

  // Hybrid Merge Sort Results
  std::vector<std::tuple<int, int, double, std::string>> hybridSortResults;
  for (int size : sizes) {
    for (int threshold : thresholds) {
      // Random Array
      std::vector<int> randomArray = generator.getRandomArray(size);
      double randomTime = tester.measureHybridMergeSortTime(randomArray, size, threshold);
      hybridSortResults.emplace_back(size, threshold, randomTime, "Random Array");

      // Reversed Array
      std::vector<int> reversedArray = generator.getReversedArray(size);
      double reversedTime = tester.measureHybridMergeSortTime(reversedArray, size, threshold);
      hybridSortResults.emplace_back(size, threshold, reversedTime, "Reversed Array");

      // Nearly Sorted Array
      std::vector<int> nearlySortedArray = generator.getNearlySortedArray(size, size / 10);  // 10% swaps
      double nearlySortedTime = tester.measureHybridMergeSortTime(nearlySortedArray, size, threshold);
      hybridSortResults.emplace_back(size, threshold, nearlySortedTime, "Nearly Sorted Array");
    }
  }

  // Save Hybrid Merge Sort Results
  writeHybridResultsToCSV("hybrid_sort_results.csv", hybridSortResults);

  std::cout << "Results written to CSV files.\n";

  return 0;
}

//#include "ArrayGenerator.h"
//#include "SortTester.h"
//#include "SortFunctions.h"
//#include <fstream>
//#include <vector>
//
//int main() {
//  ArrayGenerator generator;
//  SortTester tester;
//
//  std::vector<int> thresholds = { 5, 10, 15, 20, 30, 50 };
//  std::ofstream mergeSortResults("merge_sort_results.csv");
//  std::ofstream hybridSortResults("hybrid_sort_results.csv");
//
//  mergeSortResults << "Size,Time\n";
//  hybridSortResults << "Size,Threshold,Time\n";
//
//  for (int size = 500; size <= 10000; size += 100) {
//    std::vector<int> randomArray = generator.getRandomArray(size);
//    double mergeSortTime = tester.measureMergeSortTime(randomArray, size);
//    mergeSortResults << size << "," << mergeSortTime << "\n";
//    for (int threshold : thresholds) {
//      double hybridTime = tester.measureHybridMergeSortTime(randomArray, size, threshold);
//      hybridSortResults << size << "," << threshold << "," << hybridTime << "\n";
//    }
//  }
//
//  mergeSortResults.close();
//  hybridSortResults.close();
//
//  return 0;
//}