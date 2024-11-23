#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H

#include <vector>

class ArrayGenerator {
private:
  std::vector<int> baseArray;
  int maxArraySize;
  int minValue;
  int maxValue;

  void generateBaseArray();

public:
  ArrayGenerator();

  std::vector<int> getRandomArray(int size);
  std::vector<int> getReversedArray(int size);
  std::vector<int> getNearlySortedArray(int size, int swaps);
};

#endif // ARRAY_GENERATOR_H
