#include <math.h>
#include <stdio.h>

void quadraticFormula(double a, double b, double c, double *root1,
                      double *root2, int *hasRealRoots) {
  double discriminant = b * b - 4 * a * c;

  if (discriminant >= 0) {
    *hasRealRoots = 1;
    *root1 = (-b + sqrt(discriminant) / (2 * a);
    *root2 = (-b - sqrt(discriminant)) / (2 * a);
  } else {
    *hasRealRoots = 0;
  }
}

int main() {
  double a = 1.0, b = -3.0, c = 2.0;
  double root1, root2;
  int hasRealRoots;

  quadraticFormula(a, b, c, &root1, &root2, &hasRealRoots);
  printf("Equation: %.2fx^2 + %.2fx + %.2f\n", a, b, c);

  if (hasRealRoots) {
    printf("Root 1: %.2f\n", root1);
    printf("Root 2: %.2f\n", root2);
  } else {
    printf("No real roots\n");
  }

  return 0;
}