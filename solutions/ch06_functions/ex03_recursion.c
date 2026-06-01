#pragma strong_types
#include "defs.h"

//
// Exercise 6.3: Recursive Power
// Implements factorial and fibonacci using recursion.
// Function prototypes are declared before create() so the compiler
// knows about them before they are referenced.
//

// Function prototypes (forward declarations)
int factorial(int n);
int fibonacci(int n);

void create()
{
  // Optional: uncomment for testing
  // write("factorial(5) = " + factorial(5) + "\n");
  // write("fibonacci(6) = " + fibonacci(6) + "\n");
  return;
}

//
// factorial - Computes n! recursively.
// Base case: n <= 1 returns 1.
// Recursive case: n * factorial(n - 1).
//
// Examples:
//   factorial(0) = 1
//   factorial(5) = 120
//   factorial(10) = 3628800
//
int factorial(int n)
{
  // Base case: 0! and 1! are both 1
  if (n <= 1)
    return 1;

  // Recursive case: n! = n * (n-1)!
  return n * factorial(n - 1);
}

//
// fibonacci - Computes the nth Fibonacci number recursively.
// Base cases: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n-1) + fib(n-2).
//
// Examples:
//   fibonacci(0) = 0
//   fibonacci(1) = 1
//   fibonacci(6) = 8
//   fibonacci(10) = 55
//
int fibonacci(int n)
{
  // Base case: fib(0) = 0
  if (n <= 0)
    return 0;

  // Base case: fib(1) = 1
  if (n == 1)
    return 1;

  // Recursive case: fib(n) = fib(n-1) + fib(n-2)
  return fibonacci(n - 1) + fibonacci(n - 2);
}
