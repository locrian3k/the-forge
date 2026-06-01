#pragma strong_types
#include "defs.h"

// Exercise 19.4, Closures
// Demonstrates efun closures, inline filter, and inline map.

// Global arrays for processing
int *numbers;
string *names;
int *high_values;

// Sort numbers in ascending order using an efun closure.
// #'< is a reference to the built-in less-than operator.
void sort_numbers()
{
  numbers = sort_array(numbers, #'<);
  return;
}

// Filter to keep only values above 20 using an inline closure.
// $1 refers to each element as filter() iterates the array.
void filter_high()
{
  high_values = filter(numbers, (: $1 > 20 :));
  return;
}

// Append a title to each name using map() with an inline closure.
// $1 is each string element; map() returns the transformed array.
void title_names()
{
  names = map(names, (: $1 + " the Brave" :));
  return;
}

void create()
{
  // Initialize with unsorted integers
  numbers = ({42, 7, 99, 3, 55, 18});

  // Initialize with plain name strings
  names = ({"Gandalf", "Frodo", "Arwen", "Sam"});

  // Process the arrays using three closure styles
  sort_numbers();
  filter_high();
  title_names();

  return;
}

// Query functions to return the processed arrays
int *query_numbers() { return numbers; }
int *query_high_values() { return high_values; }
string *query_names() { return names; }
