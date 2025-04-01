#include <stdio.h>
#include <stdlib.h>

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int merged[]) {
  int i = 0, j = 0, k = 0;

  // Merge elements from both arrays in sorted order
  while (i < size1 && j < size2) {
    if (arr1[i] <= arr2[j]) {
      merged[k++] = arr1[i++];
    } else {
      merged[k++] = arr2[j++];
    }
  }

  // Copy remaining elements from arr1, if any
  while (i < size1) {
    merged[k++] = arr1[i++];
  }

  // Copy remaining elements from arr2, if any
  while (j < size2) {
    merged[k++] = arr2[j++];
  }
}

int main() {
  int arr1[] = {1, 3, 5, 7, 9};
  int arr2[] = {2, 4, 6, 8, 10};
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  int size2 = sizeof(arr2) / sizeof(arr2[0]);

  int *merged = (int *)malloc((size1 + size2) * sizeof(int));
  if (merged == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  mergeSortedArrays(arr1, arr2, size1, size2, merged);

  printf("Merged array: ");
  for (int i = 0; i < size1 + size2; i++) {
    printf("%d ", merged[i]);
  }
  printf("\n");

  free(merged);

  return 0;
}