#pragma strong_types
#include "defs.h"

//
// Exercise 7.3: Loop Workshop
// Demonstrates the three main loop constructs in LPC:
//   for    , index-based iteration over an array
//   foreach, key-value iteration over a mapping
//   while  , conditional iteration with early exit
//

// Global data structures populated in create()
string *monsters;
mapping levels;

void create()
{
  // Set up a roster of monsters and their levels
  monsters = ({
    "goblin",
    "orc",
    "troll",
    "dragon",
    "skeleton",
  });

  levels = ([
    "goblin": 3,
    "orc": 7,
    "troll": 15,
    "dragon": 50,
    "skeleton": 4,
  ]);
  return;
}

//
// list_monsters - Uses a for loop to build a numbered list string
// from the monsters array.
//
// Example output:
//   "1. goblin\n2. orc\n3. troll\n4. dragon\n5. skeleton\n"
//
string list_monsters()
{
  string result;
  int i;

  result = "";
  for (i = 0; i < sizeof(monsters); i++)
  {
    // Arrays are 0-indexed, but humans count from 1
    result += (i + 1) + ". " + monsters[i] + "\n";
  }
  return result;
}

//
// total_levels - Uses foreach to iterate over the levels mapping
// and sum all the level values.
//
int total_levels()
{
  int sum;

  sum = 0;
  foreach (string name, int lvl in levels)
  {
    sum += lvl;
  }
  return sum;
}

//
// first_above - Uses a while loop to walk the monsters array and
// return the name of the first monster whose level exceeds the
// given threshold. Returns "none" if no monster qualifies.
//
string first_above(int threshold)
{
  int i;

  i = 0;
  while (i < sizeof(monsters))
  {
    if (levels[monsters[i]] > threshold)
      return monsters[i];
    i++;
  }
  return "none";
}
