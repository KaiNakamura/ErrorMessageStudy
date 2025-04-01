#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

double sphereVolume(double radius) {
  return (4.0 / 3.0) * PI * pow(radius, 3);
}

int main() {
  double r1 = 3.0;
  double r2 = 5.0;

  printf("Volume for radius of %.2f: %.2f\n", r1, sphereVolume(r1));
  printf("Volume for radius of %.2f: %.2f\n", r2, sphereVolume(r2));

  return 0;
}