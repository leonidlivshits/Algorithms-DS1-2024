#include <vector>
#include <iostream>
#include <algorithm>

void insertionSort(std::vector<int>& arr, int left, int right) {
  for (int i = left + 1; i <= right; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= left && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
  for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    }
    else {
      arr[k++] = R[j++];
    }
  }

  while (i < n1) arr[k++] = L[i++];
  while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

void hybridMergeSort(std::vector<int>& arr, int left, int right, int threshold) {
  if (right - left + 1 <= threshold) {
    insertionSort(arr, left, right);
    return;
  }

  if (left < right) {
    int mid = left + (right - left) / 2;
    hybridMergeSort(arr, left, mid, threshold);
    hybridMergeSort(arr, mid + 1, right, threshold);
    merge(arr, left, mid, right);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;

  if (n == 0) {
    return 0;
  }

  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  const int threshold = 15;

  hybridMergeSort(arr, 0, n - 1, threshold);

  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << '\n';

  return 0;
}