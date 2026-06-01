/*
  ex01_calculator.c
  Exercise 4.1 — Calculator Object
  Basic arithmetic operations with division-by-zero protection.
*/
#pragma strong_types
#include "defs.h"

inherit "obj/treasure";

void create()
{
  ::create();

  // TODO: Set the object identity:
  //   name  -> "calculator"
  //   alias -> ({"calc", "calculator"})
  //   short -> "a calculator"
  //   long  -> a description of your choice
  //   value -> 15
  //   weight -> 2

  return;
}

// TODO: Implement int do_add(int a, int b)
//   Return a + b

// TODO: Implement int do_sub(int a, int b)
//   Return a - b

// TODO: Implement int do_mul(int a, int b)
//   Return a * b

// TODO: Implement int do_div(int a, int b)
//   Return a / b, but if b is 0 return 0 instead of crashing.
//   IMPORTANT: Division by zero causes a runtime error in LPC.
//   Check b before dividing.

// TODO: Implement int do_mod(int a, int b)
//   Return a % b (the remainder), but if b is 0 return 0.
//   The modulo operator also crashes on zero, guard it the same way.
