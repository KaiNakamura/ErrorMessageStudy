#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
  int left = 0, right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] > target) {
      right = mid - 1;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 7;

  int result = binarySearch(arr, size, target);

  if (result != -1) {
    printf("Element %d found at index %d.\n", target, result);
  } else {
    printf("Element %d not found in the array.\n", target);
  }

  return 0;
}