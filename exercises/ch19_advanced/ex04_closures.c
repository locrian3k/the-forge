/*
  ex04_closures.c
  Exercise 19.4 — Closures
  Demonstrates three closure styles in LPC:
    1. Efun closures: #'< (reference to built-in operator)
    2. Inline closures for filter: (: $1 > 20 :)
    3. Inline closures for map: (: $1 + " the Brave" :)
*/

#pragma strong_types
#include "defs.h"

// TODO: Declare global arrays for processing:
//       int *numbers;
//       string *names;
//       int *high_values;

// TODO: Implement sort_numbers()
//       Sort the numbers array in ascending order using an efun closure.
//       #'< is a reference to the built-in less-than operator.
//       numbers = sort_array(numbers, #'<);
void sort_numbers()
{
  // TODO: Sort numbers using sort_array() with #'< closure

  return;
}

// TODO: Implement filter_high()
//       Filter the numbers array to keep only values above 20.
//       Use an inline closure with filter():
//       high_values = filter(numbers, (: $1 > 20 :));
//       $1 refers to each element as filter() iterates.
void filter_high()
{
  // TODO: Filter numbers using filter() with an inline closure

  return;
}

// TODO: Implement title_names()
//       Append " the Brave" to each name using map() with an
//       inline closure:
//       names = map(names, (: $1 + " the Brave" :));
void title_names()
{
  // TODO: Transform names using map() with an inline closure

  return;
}

void create()
{
  // TODO: Initialize numbers with an unsorted array of integers:
  //       numbers = ({42, 7, 99, 3, 55, 18});

  // TODO: Initialize names with an array of name strings:
  //       names = ({"Gandalf", "Frodo", "Arwen", "Sam"});

  // TODO: Call the three processing functions:
  //       sort_numbers();
  //       filter_high();
  //       title_names();

  return;
}

// Query functions to return the processed arrays.
// These are already complete — implement the logic above.
int *query_numbers() { return numbers; }
int *query_high_values() { return high_values; }
string *query_names() { return names; }
