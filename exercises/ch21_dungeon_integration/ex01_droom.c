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
//       mapping all_dirs_map =
//       ([
//         "north",
//         "south",
//         "east",
//         "west",
//         "northeast",
//         "northwest",
//         "southeast",
//         "southwest",
//         "up",
//         "down"
//       ]);

void create()
{
  ::create();

  // TODO: Register with the dungeon system using the DNAME constant:
  //       set_dungeon(DNAME, 8, 1, 1, 1);

  // TODO: Set light so all inheriting rooms start lit:
  //       set_light(1);

  return;
}

// Shortcut to spawn a monster from the area's mon/ directory.
// Usage in child rooms: monster("goblin");
// instead of: add_clone(TRAINING_MOBS + "goblin");
void monster(string path)
{
  // TODO: Call add_clone() with the full monster path:
  //       add_clone(TRAINING_MOBS + path);

  return;
}

// Shortcut to spawn an item from the area's obj/ directory.
// Usage in child rooms: item("treasure");
// instead of: add_clone(TRAINING_ITEM + "treasure");
void item(string path)
{
  // TODO: Call add_clone() with the full item path:
  //       add_clone(TRAINING_ITEM + path);

  return;
}

// Block movement in directions with no exit.
// Returns 1 to block, 0 to allow.
status block_them(string arg)
{
  string verb;

  verb = query_verb();

  // TODO: If the verb is a valid exit or hidden exit, return 0.
  //       if (member(query_exits(), verb) || member(query_hidden(), verb))
  //         return 0;

  // TODO: If the verb is a compass direction with no exit:
  //       if (member(all_dirs_map, verb))
  //       {
  //         write("Solid stone blocks your way in that direction.\n");
  //         return 1;
  //       }

  return 0;
}

void init()
{
  ::init();

  // TODO: Catch all player input so block_them can check directions.
  //       add_action("block_them", "", 1);

  return;
}
