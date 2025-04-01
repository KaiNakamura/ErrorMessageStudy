#include <stdio.h>
#include <stdlib.h>

// Function to perform modular exponentiation (base^exp % mod)
long long modExp(long long base, long long exp, long long mod) {
  long long result = 1;
  base = base % mod;

  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return result;
}

// Miller-Rabin test for a single base 'a'
int millerTest(long long d, long long n, long long a) {
  long long x = modExp(a, d, n);

  if (x == 1 || x == n - 1) {
    return 1; // Probably prime
  }

  while (d != n - 1) {
    x = (x * x) % n;
    d *= 2;

    if (x == 1) {
      return 0; // Composite
    }
    if (x == n - 1) {
      return 1; // Probably prime
    }
  }

  return 0; // Composite
}

// Miller-Rabin Primality Test
int isPrime(long long n, int k) {
  if (n <= 1 || n == 4) {
    return 0; // Not prime
  }
  if (n <= 3) {
    return 1; // Prime
  }

  // Find d such that n-1 = d * 2^r
  long long d = n - 1;
  while (d % 2 == 0) {
    d /= 2;
  }

  // Perform k iterations of the test
  for (int i = 0; i < k; i++) {
    long long a = 2 + rand() % (n - 4); // Random base in [2, n-2]
    if (!millerTest(d, n, a)) {
      return 0; // Composite
    }
  }

  return 1; // Extremely likely prime
}

int main() {
  long long n = 999999733;
  int k = 100; // Number of iterations for accuracy

  if (isPrime(n, k)) {
    printf("%lld is prime.\n", n);
  } else {
    printf("%lld is composite.\n", n);
  }

  return 0;
}