#include <math.h>
#include <stdio.h>

double calculateCompoundInterest(double principal, double rate, int time) {
  return principal * pow(1 + rate / 100, time);
}

double calculateInterestEarned(double principal, double amount) {
  return amount - principal;
}

int main() {
  double principal = 1000.0;
  double rate = 5.0;
  int time = 10;

  double amount = calculateCompoundInterest(principal, rate, time);
  double interestEarned = calculateInterestEarned(principal, amount);

  printf("Principal: $%.2f\n", principal);
  printf("Rate: %.2f%%\n", rate);
  printf("Time: %d years\n", time);
  printf("Total Amount: $%.2f\n", amount);
  printf("Interest Earned: $%.2f\n", interestEarned);

  return 0;
}