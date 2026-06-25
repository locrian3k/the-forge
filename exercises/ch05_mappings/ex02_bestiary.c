/*
  ex02_bestiary.c
  YourName YYMMDD
  Exercise 5.2 — Monster Bestiary
  Demonstrates nested mappings, iteration with foreach, and
  conditional filtering over mapping data.
*/
#pragma strong_types
#include "../defs.h"

// TODO: Declare a global mapping variable named "bestiary"

void create()
{
  // TODO: Populate bestiary with at least 5 monsters.
  //   Each entry maps a monster name (string) to an inner mapping
  //   with keys: "level" (int), "race" (string), "aggressive" (int 1/0).
  //
  //   Syntax for nested mappings:
  //   mapping = ([
  //     "key": ([ "inner_key": value, "inner_key2": value ]),
  //   ]);

  return;
}

// TODO: Implement mapping lookup(string name)
//   Return the inner stat mapping for the given monster name.
//   Return 0 if the monster is not in the bestiary.

// TODO: Implement string strongest()
//   Iterate over all monsters and return the name of the one with
//   the highest level. Return "none" if the bestiary is empty.
//
//   Hint: Use foreach (string name, mapping stats in bestiary)
//   Track the best_name and best_level as you iterate.

// TODO: Implement string *aggressive_list()
//   Return a sorted array of monster names where "aggressive" is 1.
//   Return ({}) (empty array) if none qualify.
//
//   Hint: Build up a result array with +=
//     result += ({ name })
//   then sort_array(result, 1) before returning.
