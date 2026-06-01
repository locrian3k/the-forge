#pragma strong_types
#include "defs.h"

//
// Exercise 5.2: Monster Bestiary
// Demonstrates nested mappings, iteration with foreach, and
// conditional filtering over mapping data.
//

// Global mapping: monster_name -> ([ "level", "race", "aggressive" ])
mapping bestiary;

void create()
{
  // Pre-populate with 5 monsters of varying stats
  bestiary = ([
    "goblin": ([
      "level": 3,
      "race": "goblin",
      "aggressive": 1,
    ]),
    "skeleton": ([
      "level": 5,
      "race": "undead",
      "aggressive": 1,
    ]),
    "forest sprite": ([
      "level": 2,
      "race": "fey",
      "aggressive": 0,
    ]),
    "cave troll": ([
      "level": 12,
      "race": "troll",
      "aggressive": 1,
    ]),
    "ancient dragon": ([
      "level": 50,
      "race": "dragon",
      "aggressive": 0,
    ]),
  ]);
  return;
}

//
// lookup - Returns the inner stat mapping for a given monster name.
// Returns 0 if the monster is not in the bestiary.
//
mapping lookup(string name)
{
  if (!bestiary[name])
    return 0;
  return bestiary[name];
}

//
// strongest - Iterates over all monsters and returns the name of
// the one with the highest level. Returns "none" if the bestiary
// is empty.
//
string strongest()
{
  string best_name;
  int best_level;

  best_name = "none";
  best_level = -1;

  foreach (string name, mapping stats in bestiary)
  {
    if (stats["level"] > best_level)
    {
      best_level = stats["level"];
      best_name = name;
    }
  }
  return best_name;
}

//
// aggressive_list - Returns a sorted array of monster names where
// the "aggressive" field is 1. Returns an empty array if none qualify.
//
string *aggressive_list()
{
  string *result;

  result = ({});

  foreach (string name, mapping stats in bestiary)
  {
    if (stats["aggressive"])
      result += ({ name });
  }
  return sort_array(result, 1);
}
