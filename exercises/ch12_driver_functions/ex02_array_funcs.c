/*
  ex02_array_funcs.c
  YourName YYMMDD
  Exercise 12.2 — Array Operations
  Demonstrates foreach iteration, filter(), and sort_array()
  with closure comparators.
*/
#pragma strong_types
#include "../defs.h"

// TODO: Declare a global int array variable for monster levels.

// TODO: Add function prototypes for all functions in this file.

// Initialize the levels array with sample monster data.
void create()
{
  // TODO: Set levels to an array of at least 8 integer values.

  return;
}

// TODO: Implement average_level()
//   Return the integer average of all monster levels.
//   Steps:
//     1. Declare int total and set to 0
//     2. Use foreach (int val : levels) to sum all values
//     3. Return total / sizeof(levels)

// TODO: Implement filter_above(int threshold)
//   Return only the levels strictly above the threshold.
//   Use the filter() efun with an inline closure comparator.
//   Hint: $1 refers to each element, $(varname) captures a local variable.

// TODO: Implement sort_descending()
//   Return a copy of levels sorted from highest to lowest.
//   Use sort_array() with a descending closure.
//   Hint: Use copy() to avoid modifying the original array.
