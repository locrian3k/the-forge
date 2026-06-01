/*
  ex03_loops.c
  Exercise 7.3 — Loop Workshop
  Demonstrates the three main loop constructs in LPC:
    for     - index-based iteration over an array
    foreach - key-value iteration over a mapping
    while   - conditional iteration with early exit
*/
#pragma strong_types
#include "../defs.h"

// TODO: Declare two global variables:
//   A string array for monster names
//   A mapping of monster names to level values

void create()
{
  // TODO: Populate the monsters array with at least 4 monster names.

  // TODO: Populate the levels mapping with matching entries.
  //   Each monster name should map to an integer level.

  return;
}

// TODO: Implement string list_monsters()
//   Use a FOR loop to build a numbered list string from the
//   monsters array.
//
//   Example output: "1. goblin\n2. orc\n3. troll\n4. dragon\n"
//
//   Hint: for (i = 0; i < sizeof(monsters); i++)
//   Arrays are 0-indexed, but humans count from 1.

// TODO: Implement int total_levels()
//   Use a FOREACH loop to iterate over the levels mapping
//   and sum all the level values.
//
//   Hint: foreach (string name, int lvl in levels)

// TODO: Implement string first_above(int threshold)
//   Use a WHILE loop to walk the monsters array and return the
//   name of the first monster whose level exceeds the threshold.
//   Return "none" if no monster qualifies.
//
//   Hint: Initialize an index before the loop, check the condition,
//   increment inside the body. Return early when you find a match.
