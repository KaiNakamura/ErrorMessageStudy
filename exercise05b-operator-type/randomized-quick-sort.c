#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

int randomizedPartition(int arr[], int low, int high) {
  int randomIndex = low + rand() % (high - low + 1);
  swap(&arr[randomIndex], &arr[high]);
  return partition(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high) {
  if (low < high) {
    int i = randomizedPartition(arr, low, high);
    randomizedQuickSort(arr, low, i - 1);
    randomizedQuickSort(arr, i + 1, high);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  printArray(arr, n);

  randomizedQuickSort(arr, 0, n - 1);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}