#pragma strong_types
#include "../defs.h"

// Array Operations - demonstrates foreach iteration,
// filter(), and sort_array() with closure comparators.

// Monster levels for analysis
int *levels;

// Function prototypes
void create();
int average_level();
int *filter_above(int threshold);
int *sort_descending();

// Initialize the levels array with sample monster data.
void create()
{
  levels = ({ 5, 12, 3, 18, 7, 25, 14, 9 });
  return;
}

// Return the integer average of all monster levels.
// Uses foreach to sum, then divides by count.
int average_level()
{
  int total, val;

  total = 0;
  foreach (val : levels)
    total += val;
  return total / sizeof(levels);
}

// Return only the levels strictly above the threshold.
// Uses filter() with a closure comparator.
int *filter_above(int threshold)
{
  return filter(levels, (: $1 > $(threshold) :));
}

// Return a copy of levels sorted from highest to lowest.
// Uses sort_array() with a descending closure.
int *sort_descending()
{
  return sort_array(copy(levels), (: $2 - $1 :));
}
