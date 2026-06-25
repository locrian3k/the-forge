/*
  ex02_scoreboard.c
  YourName YYMMDD
  Exercise 6.2 — Cross-Object Calls (Scoreboard)
  Maintains a mapping of player names to kill counts.
  Other objects call add_kill() and query_kills() on this object
  to demonstrate cross-object communication.
*/
#pragma strong_types
#include "../defs.h"

// TODO: Declare a global mapping named "kills"

void create()
{
  // TODO: Initialize kills as an empty mapping: ([])

  return;
}

// TODO: Implement void add_kill(string name)
//   Increment the kill count for the given name.
//   If the name already exists, add 1 to the existing count.
//   If the name does not exist, create a new entry with count 1.
//
//   Hint: Same pattern as add_item() from Exercise 5.1.

// TODO: Implement int query_kills(string name)
//   Return the kill count for the given name, or 0 if not found.
//   Hint: Mappings return 0 for missing keys by default.
