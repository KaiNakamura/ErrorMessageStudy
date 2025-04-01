#include <stdio.h>

void simultaneousMinAndMax(int arr[], int n, int *min, int *max) {
  if (n == 1) {
    // If there's only one element, it's both the min and max
    *min = arr[0];
    *max = arr[0];
    return;
  }

  // Initialize min and max
  if (arr[0] > arr[1]) {
    *max = arr[0];
    *min = arr[1];
  } else {
    *max = arr[1];
    *min = arr[0];
  }

  // Process elements in pairs
  for (int i = 2; i < n - 1; i += 2) {
    if (arr[i] > arr[i + 1]) {
      if (arr[i] > *max) {
        *max = arr[i];
      }
      if (arr[i + 1] < *min) {
        *min = arr[i + 1];
      }
    } else {
      if (arr[i + 1] > *max) {
        *max = arr[i + 1];
      }
      if (arr[i] < *min) {
        *min = arr[i];
      }
    }
  }

  // If there's an odd number of elements, compare the last one
  if (n % 2 != 0) {
    if (arr[n - 1] > *max) {
      *max = arr[n - 1];
    }
    if (arr[n - 1] < *min) {
      *min = arr[n - 1];
    }
  }
}

int main() {
  int arr[] = {3, 5, 10, 1, 2, 9, 6, 4, 8, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  int min, max;

  simultaneousMinAndMax(arr, n, &min, &max);

  printf("Minimum: %d\n", min);
  printf("Maximum: %d\n", max);

  return 0;
}