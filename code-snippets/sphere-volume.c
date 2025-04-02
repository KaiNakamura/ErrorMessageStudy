#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

double sphereVolume(double radius) {
  return (4.0 / 3.0) * PI * pow(radius, 3);
}

int main() {
  double radius1 = 3.0;
  double radius2 = 5.0;

  double volume1 = sphereVolume(radius1);
  double volume2 = sphereVolume(radius2);

  printf("Volume for radius of %.2f: %.2f\n", radius1, volume1);
  printf("Volume for radius of %.2f: %.2f\n", radius2, volume2);

  return 0;
}