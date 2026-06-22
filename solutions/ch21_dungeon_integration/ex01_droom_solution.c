/* ex01_droom.c / Mimic 260316 / Base dungeon room for area rooms */

#pragma strong_types
#include "defs.h"

// Exercise 21.1, Base Dungeon Room (droom.c pattern)
// This is an inheritable base room that all dungeon rooms in an
// area should inherit from. It centralizes shared behavior:
//   - set_dungeon() so every room is registered with the dungeon
//   - set_light() so every room is lit by default
//   - monster() and item() helpers for shorter add_clone calls
//   - block_them() to prevent movement in invalid directions

inherit "room/dungeon/dr.c";

// Mapping of all compass directions used for blocking movement.
// If a player types a direction that has no exit, block_them()
// catches it and prints a wall message instead of the default
// "You cannot go that way."
mapping all_dirs_map =
([
  "north",
  "south",
  "east",
  "west",
  "northeast",
  "northwest",
  "southeast",
  "southwest",
  "up",
  "down"
]);

void create()
{
  ::create();

  // Register this room with the dungeon system.
  // All rooms inheriting this file share the same dungeon name
  // and level, keeping the area consistent.
  set_dungeon(DNAME, 8, 1, 1, 1);
  set_light(1);

  return;
}

// Shortcut to spawn a monster from the area's mon/ directory.
// Usage: monster("goblin") instead of add_clone(TRAINING_MOBS + "goblin")
void monster(string path)
{
  add_clone(TRAINING_MOBS + path);
  return;
}

// Shortcut to spawn an item from the area's obj/ directory.
// Usage: item("treasure") instead of add_clone(TRAINING_ITEM + "treasure")
void item(string path)
{
  add_clone(TRAINING_ITEM + path);
  return;
}

// Blocks player movement in directions that have no exit defined.
// Returns 1 to block the command, 0 to let it through.
status block_them(string arg)
{
  string verb;

  verb = query_verb();

  // If the direction is a valid exit or hidden exit, allow movement
  if (member(query_exits(), verb) || member(query_hidden(), verb))
    return 0;

  // If the player typed a compass direction with no exit, block it
  if (member(all_dirs_map, verb))
  {
    write("Solid stone blocks your way in that direction.\n");
    return 1;
  }

  // Not a direction at all, let other actions handle it
  return 0;
}

void init()
{
  ::init();

  // Catch all player input so block_them can check for invalid
  // directions. The empty string with flag 1 matches everything.
  add_action("block_them", "", 1);

  return;
}
