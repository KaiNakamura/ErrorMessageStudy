#include <stdio.h>

double fahrenheitToCelsius(double fahrenheit) {
  return (fahrenheit - 32) * 5.0 / 9.0;
}

double celsiusToFahrenheit(double celsius) {
  return (celsius * 9.0 / 5.0) + 32;
}

int main() {
  double fahrenheit = 212.0;
  double celsius = 0.0;

  double fahrenheitConverted = fahrenheitToCelsius(fahrenheit);
  double celsiusConverted = celsiusToFahrenheit(celsius);

  printf("%.2f F = %.2f C\n", fahrenheit, fahrenheitConverted);
  printf("%.2f C = %.2f F\n", celsius, celsiusConverted);

  return 0;
}