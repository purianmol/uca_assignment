#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Generates an array of random integers of given size.
int *generateRandomArray(int size) {
  int *arr = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    arr[i] = rand();
  }
  return arr;
}

// Generates an array of given size in Ascending order
int *generateAscArray(int size) {
  int *arr = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    arr[i] = i;
  }
  return arr;
}

// Generates an array of given size in Descending order
int *generateDescArray(int size) {
  int *arr = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    arr[i] = size - i;
  }
  return arr;
}

// helper function
void merge(int arr[], int low, int mid, int high) {
  int n = high - low + 1;
  int mix[n];
  memset(mix, 0, sizeof(mix));
  int i = low, j = mid + 1, k = 0;
  while (i <= mid && j <= high) {
    if (arr[i] < arr[j]) {
      mix[k] = arr[i];
      i++;
    } else {
      mix[k] = arr[j];
      j++;
    }
    k++;
  }
  while (i <= mid) {
    mix[k] = arr[i];
    i++;
    k++;
  }
  while (j <= high) {
    mix[k] = arr[j];
    j++;
    k++;
  }

  for (int x = 0; x < n; x++) {
    arr[x + low] = mix[x];
  }
}

// helper function
void mergeSort(int arr[], int low, int high) {
  if (low >= high)
    return;
  int mid = low + (high - low) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

// Sorts the given array using Merge Sort.
void applyMergeSort(int arr[], int size) { mergeSort(arr, 0, size - 1); }

// Returns true if the array is sorted, otherwise false.
bool verifySort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }

  return true;
}

// Analyses the time taken
void analyze(int arr[], int size) {
  // Start timer
  clock_t start = clock();

  // Apply sorting algorithm
  applyMergeSort(arr, size);

  // Stop timer
  clock_t end = clock();

  // Calculate execution time
  double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

  if (!verifySort(arr, size)) {
    printf("Failed: array not sorted.");
    exit(-1);
  }

  printf("%.0f\n", executionTime * 1000);

  // Free dynamically allocated memory
  free(arr);
}

int main() {
  printf("Merge sort for random data (execution time in ms):\n");
  for (int size = 8000; size <= 36000; size += 4000) {
    int *arr = generateRandomArray(size);
    analyze(arr, size);
  }

  printf("Merge sort for data in Ascending order (execution time in ms):\n");
  for (int size = 8000; size <= 36000; size += 4000) {
    int *arr = generateAscArray(size);
    analyze(arr, size);
  }

  printf("Merge sort for data in Descending order (execution time in ms):\n");
  for (int size = 8000; size <= 36000; size += 4000) {
    int *arr = generateDescArray(size);
    analyze(arr, size);
  }
  return 0;
}
