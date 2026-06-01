/*
  ex01_droom.c
  Exercise 21.1 — Base Dungeon Room (droom.c pattern)
  Create an inheritable base room for a dungeon area.
  All interior dungeon rooms should inherit this file.
  It centralizes: set_dungeon(), set_light(), helper functions
  for spawning, and direction blocking.
*/

#pragma strong_types
#include "defs.h"

inherit "room/dungeon/dr.c";

// TODO: Declare a mapping of all compass directions for blocking.
//       Include all 10 compass directions (n/s/e/w, diagonals, up/down).

void create()
{
  ::create();

  // TODO: Register with the dungeon system using the DNAME constant.

  // TODO: Set light so all inheriting rooms start lit.

  return;
}

// Shortcut to spawn a monster from the area's mon/ directory.
// Usage in child rooms: monster("goblin");
// instead of: add_clone(TRAINING_MOBS + "goblin");
void monster(string path)
{
  // TODO: Call add_clone() with the full monster path.
  //       Use TRAINING_MOBS + path to build it.

  return;
}

// Shortcut to spawn an item from the area's obj/ directory.
// Usage in child rooms: item("treasure");
// instead of: add_clone(TRAINING_ITEM + "treasure");
void item(string path)
{
  // TODO: Call add_clone() with the full item path.
  //       Use TRAINING_ITEM + path to build it.

  return;
}

// Block movement in directions with no exit.
// Returns 1 to block, 0 to allow.
status block_them(string arg)
{
  string verb;

  verb = query_verb();

  // TODO: If the verb is a valid exit or hidden exit, return 0.
  //       Use member() to check query_exits() and query_hidden().

  // TODO: If the verb is a compass direction with no exit,
  //       write a wall message and return 1 to block.

  return 0;
}

void init()
{
  ::init();

  // TODO: Catch all player input so block_them can check directions.
  //       Syntax: add_action("func", "", 1); matches every command.

  return;
}
