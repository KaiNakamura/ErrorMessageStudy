#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function to compute gcd using Euclid's Algorithm
int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// Function to compute modular exponentiation (base^exp % mod)
int modExp(int base, int exp, int mod) {
  int result = 1;
  base = base % mod;

  while (exp > 0) {
    if (exp % 2 == 1) { // If exp is odd
      result = (result * base) % mod;
    }
    exp = exp >> 1; // Divide exp by 2
    base = (base * base) % mod;
  }
  return result;
}

// Function to compute the modular multiplicative inverse using the Extended
// Euclidean Algorithm
int modInverse(int e, int phi) {
  int t = 0, newT = 1;
  int r = phi, newR = e;

  while (newR != 0) {
    int quotient = r / newR;
    int temp = t;
    t = newT;
    newT = temp - quotient * newT;

    temp = r;
    r = newR;
    newR = temp - quotient * newR;
  }

  if (r > 1) {
    printf("e is not invertible\n");
    return -1;
  }
  if (t < 0) {
    t += phi;
  }
  return t;
}

int main() {
  // Example RSA setup
  int p = 3, q = 11;           // Two prime numbers
  int N = p * q;               // Compute N
  int phi = (p - 1) * (q - 1); // Compute phi(N)

  int e = 7; // Choose e such that gcd(e, phi) = 1
  if (gcd(e, phi) != 1) {
    printf("e and phi are not coprime\n");
    return 1;
  }

  int d = modInverse(e, phi); // Compute the private key d
  if (d == -1) {
    return 1;
  }

  printf("Public Key: (e=%d, N=%d)\n", e, N);
  printf("Private Key: (d=%d, N=%d)\n", d, N);

  // Example message
  int M = 2; // Message to encrypt
  printf("Original Message: %d\n", M);

  // Encrypt the message
  int C = modExp(M, e, N);
  printf("Encrypted Message: %d\n", C);

  // Decrypt the message
  int decryptedM = modExp(C, d, N);
  printf("Decrypted Message: %d\n", decryptedM);

  return 0;
}