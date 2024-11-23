#ifndef SORT_FUNCTIONS_H
#define SORT_FUNCTIONS_H

#include <vector>

// Объявления функций
void merge(std::vector<int>& array, int left, int mid, int right);
void mergeSort(std::vector<int>& array, int left, int right);
void insertionSort(std::vector<int>& array, int left, int right);
void hybridMergeSort(std::vector<int>& array, int left, int right, int threshold);

#endif // SORT_FUNCTIONS_H
