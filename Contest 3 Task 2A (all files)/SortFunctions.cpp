#include "SortFunctions.h"

// Реализация merge
void merge(std::vector<int>& array, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> leftArray(n1);
  std::vector<int> rightArray(n2);

  for (int i = 0; i < n1; ++i) leftArray[i] = array[left + i];
  for (int j = 0; j < n2; ++j) rightArray[j] = array[mid + 1 + j];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (leftArray[i] <= rightArray[j]) {
      array[k] = leftArray[i];
      i++;
    }
    else {
      array[k] = rightArray[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    array[k] = leftArray[i];
    i++;
    k++;
  }

  while (j < n2) {
    array[k] = rightArray[j];
    j++;
    k++;
  }
}

// Реализация mergeSort
void mergeSort(std::vector<int>& array, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
  }
}

// Реализация insertionSort
void insertionSort(std::vector<int>& array, int left, int right) {
  for (int i = left + 1; i <= right; ++i) {
    int key = array[i];
    int j = i - 1;
    while (j >= left && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}

// Реализация hybridMergeSort
void hybridMergeSort(std::vector<int>& array, int left, int right, int threshold) {
  if (right - left + 1 <= threshold) {
    insertionSort(array, left, right);
  }
  else {
    int mid = left + (right - left) / 2;
    hybridMergeSort(array, left, mid, threshold);
    hybridMergeSort(array, mid + 1, right, threshold);
    merge(array, left, mid, right);
  }
}
