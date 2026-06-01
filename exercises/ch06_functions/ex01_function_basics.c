/*
  ex01_function_basics.c
  Exercise 6.1 — Function Basics
  Demonstrates void, int, and string return types, plus calling
  one function from another (composition).
*/
#pragma strong_types
#include "../defs.h"

void create()
{
  // Nothing to initialize for this exercise.
  return;
}

// TODO: Implement void do_greet()
//   Use write() to display a greeting message to the player.
//   Void functions must end with an explicit return;

// TODO: Implement int do_add(int a, int b)
//   Return the sum of a and b.

// TODO: Implement string query_title()
//   Return a title string, e.g. "Apprentice of the Forge"

// TODO: Implement string do_combo(int a, int b)
//   This function demonstrates composition — calling your own
//   functions from within another function.
//
//   1. Call do_add(a, b) and store the result in a local int variable
//   2. Call query_title() and store the result in a local string variable
//   3. Return a combined string like:
//      "Apprentice of the Forge reports: 3 + 5 = 8"
//
//   Hint: LPC auto-converts ints to strings when concatenated with +
