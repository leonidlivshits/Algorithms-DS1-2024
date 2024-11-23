#include "ArrayGenerator.h"
#include <algorithm>
#include <random>
#include <ctime>

void ArrayGenerator::generateBaseArray() {
  std::mt19937 generator(static_cast<unsigned>(std::time(nullptr)));
  std::uniform_int_distribution<int> distribution(minValue, maxValue);

  for (int i = 0; i < maxArraySize; ++i) {
    baseArray.push_back(distribution(generator));
  }
}

ArrayGenerator::ArrayGenerator() : maxArraySize(10000), minValue(0), maxValue(6000) {
  generateBaseArray();
}

std::vector<int> ArrayGenerator::getRandomArray(int size) {
  if (size > maxArraySize) {
    size = maxArraySize;
  }
  return std::vector<int>(baseArray.begin(), baseArray.begin() + size);
}

std::vector<int> ArrayGenerator::getReversedArray(int size) {
  if (size > maxArraySize) {
    size = maxArraySize;
  }
  std::vector<int> reversedArray(baseArray.begin(), baseArray.begin() + size);
  std::sort(reversedArray.rbegin(), reversedArray.rend());
  return reversedArray;
}

std::vector<int> ArrayGenerator::getNearlySortedArray(int size, int swaps) {
  if (size > maxArraySize) {
    size = maxArraySize;
  }
  std::vector<int> nearlySortedArray(baseArray.begin(), baseArray.begin() + size);
  std::sort(nearlySortedArray.begin(), nearlySortedArray.end());

  std::mt19937 generator(static_cast<unsigned>(std::time(nullptr)));
  std::uniform_int_distribution<int> distribution(0, size - 1);

  for (int i = 0; i < swaps; ++i) {
    std::swap(nearlySortedArray[distribution(generator)], nearlySortedArray[distribution(generator)]);
  }

  return nearlySortedArray;
}
