#ifndef __combinatoricst_H
#define __combinatorics_H

#include "components.hpp"

unsigned long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

unsigned long permutation(int n, int k) {
  if (n < k) {
    return 0; // Invalid input, as k should be less than or equal to n
  } else {
    return factorial(n) / factorial(n - k);
  }
}

unsigned long combination(int n, int k) {
  if (n < k) {
    return 0; // Invalid input, as k should be less than or equal to n
  } else {
    return factorial(n) / (factorial(k) * factorial(n - k));
  }
}

void factorial_func()
{
  int n = 0;
  unsigned long result = 0;

  display2layermenu("Factorial", "");

  n = GET_NUMBER_DECIMAL("Enter Number");

  result = factorial(n);

  displayresult("Factorial", result);
};

void permutation_func()
{
  int n = 0, r = 0;
  unsigned long result = 0;

  display2layermenu("Permutation", "");

  n = GET_NUMBER_DECIMAL("Enter n");

  r = GET_NUMBER_DECIMAL("Enter r");

  result = permutation(n, r);

  displayresult("Permutation", result);
};

void combination_func()
{
  int n = 0, r = 0;
  unsigned long result = 0;

  display2layermenu("Combination", "");

  n = GET_NUMBER_DECIMAL("Enter n");

  r = GET_NUMBER_DECIMAL("Enter r");

  result = combination(n, r);

  displayresult("Combination", result);
};

#endif