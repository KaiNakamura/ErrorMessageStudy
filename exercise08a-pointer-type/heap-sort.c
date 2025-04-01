#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
  int largest = i;       // Initialize largest as root
  int left = 2 * i + 1;  // Left child
  int right = 2 * i + 2; // Right child

  // If left child is larger than root
  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  // If right child is larger than largest so far
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  // If largest is not root
  if (largest != i) {
    swap(&arr[i], &arr[largest]);

    // Recursively heapify the affected sub-tree
    maxHeapify(arr, n, largest);
  }
}

void buildMaxHeap(int arr[], int n) {
  // Start from the last non-leaf node and heapify each node
  for (int i = n / 2 - 1; i >= 0; i--) {
    maxHeapify(arr, n, i);
  }
}

void heapSort(int arr[], int n) {
  // Build a max heap
  buildMaxHeap(arr, n);

  // Extract elements from the heap one by one
  for (int i = n - 1; i > 0; i--) {
    // Move current root to the end
    swap(&arr[0], &arr[i]);

    // Reduce the heap size and heapify the root
    maxHeapify(arr, i, 0);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Main function
int main() {
  int arr[] = {14, 8, 7, 2, 4, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  printArray(arr, n);

  heapSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}