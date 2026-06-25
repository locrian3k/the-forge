/*
  ex03_recursion.c
  YourName YYMMDD
  Exercise 6.3 — Recursive Power
  Implements factorial and fibonacci using recursion.
  Function prototypes are declared before create() so the compiler
  knows about them before they are referenced.
*/
#pragma strong_types
#include "../defs.h"

// TODO: Declare function prototypes (forward declarations).
//   These go before create() so the compiler knows the functions exist.
//   Declare prototypes for both factorial and fibonacci.

void create()
{
  // Nothing to initialize for this exercise.
  return;
}

// TODO: Implement int factorial(int n)
//   Computes n! recursively.
//   Base case: if n <= 1, return 1
//   Recursive case: return n * factorial(n - 1)
//
//   Examples:
//     factorial(0) = 1
//     factorial(5) = 120
//     factorial(10) = 3628800

// TODO: Implement int fibonacci(int n)
//   Computes the nth Fibonacci number recursively.
//   Base case: if n <= 0, return 0
//   Base case: if n == 1, return 1
//   Recursive case: return fibonacci(n - 1) + fibonacci(n - 2)
//
//   Examples:
//     fibonacci(0) = 0
//     fibonacci(1) = 1
//     fibonacci(6) = 8
//     fibonacci(10) = 55
