#include <math.h>
#include <stdio.h>

double sphereVolume(double radius) {
  return (4.0 / 3.0) * pi * pow(radius, 3);
}

int main() {
  double r1 = 3.0;
  double r2 = 5.0;

  printf("Volume for radius of %.2f: %.2f\n", r1, sphereVolume(r1));
  printf("Volume for radius of %.2f: %.2f\n", r2, sphereVolume(r2));

  return 0;
}