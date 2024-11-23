#ifndef SORT_TESTER_H
#define SORT_TESTER_H

#include <vector>
#include <string>

class SortTester {
public:
  double measureMergeSortTime(std::vector<int>& array, int size);
  double measureHybridMergeSortTime(std::vector<int>& array, int size, int threshold);
};

#endif // SORT_TESTER_H
