/*
  ex02_array_funcs.c
  Exercise 12.2 — Array Operations
  Demonstrates foreach iteration, filter(), and sort_array()
  with closure comparators.
*/
#pragma strong_types
#include "defs.h"

// TODO: Declare a global array variable:
//   int *levels;

// TODO: Add function prototypes:
//   void create();
//   int average_level();
//   int *filter_above(int threshold);
//   int *sort_descending();

// Initialize the levels array with sample monster data.
void create()
{
  // TODO: Set levels to an array of at least 8 integer values
  //   Example: levels = ({ 5, 12, 3, 18, 7, 25, 14, 9 });

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
//   Use the filter() efun with a closure comparator:
//     return filter(levels, (: $1 > $(threshold) :));
//
//   The $() syntax captures the local variable's value into
//   the closure at creation time.

// TODO: Implement sort_descending()
//   Return a copy of levels sorted from highest to lowest.
//   Use sort_array() with a descending closure:
//     return sort_array(copy(levels), (: $2 - $1 :));
//
//   Use copy() to avoid modifying the original array.
