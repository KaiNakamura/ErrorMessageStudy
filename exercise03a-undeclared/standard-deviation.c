#include <math.h>
#include <stdio.h>

double calculateMean(int arr[], int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  return (double)sum / size;
}

double calculateStandardDeviation(int arr[], int size) {
  double mean = calculateMean(arr, size);
  double sumSquaredDifferences = 0.0;

  for (int i = 0; i < size; i++) {
    sumSquaredDifferences += pow(arr[i] - mean, 2);
  }

  return sqrt(sumSquaredDifferences / size);
}

int main() {
  int arr[] = {2, 4, 6, 8, 10};
  int size = sizeof(arr) / sizeof(arr[0]);

  double mean = calculateMean(arr, size);
  double standardDeviation = calculateStandardDeviation(arr, size);

  printf("Mean: %.2f\n", mean);
  printf("Standard deviation: %.2f\n", standardDeviation);

  return 0;
}