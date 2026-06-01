/*
  ex03_droom.c
  Exercise 18.3 — Base Area Room (droom)
  Create an inheritable base room for your area. All interior
  rooms should inherit this file instead of /room/room directly.
  This centralizes shared setup (light, direction blocking).
*/

#pragma strong_types
#include "../defs.h"

inherit "room/room";

// TODO: Declare a mapping of all compass directions for wall-blocking.
//       This is used by block_them() to detect when a player tries
//       to move in a direction that has no exit.
//
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
  set_light(1);

  return;
}

// block_them() intercepts player movement commands.
// If the player typed a compass direction that has no exit in this
// room, print a wall message and block the movement.
// Return 1 to block, 0 to allow.
status block_them(string arg)
{
  string verb;

  verb = query_verb();

  // TODO: Check if the verb is a valid exit or hidden exit.
  //       If so, return 0 to allow movement.
  //       Use: member(query_exits(), verb)
  //            member(query_hidden(), verb)

  // TODO: Check if the verb is a compass direction (in all_dirs_map)
  //       but has no exit. If so:
  //       - write() a wall message
  //       - return 1 to block

  // Not a direction at all, let other actions handle it
  return 0;
}

void init()
{
  ::init();

  // TODO: Register block_them to catch all player input.
  //       add_action("block_them", "", 1);
  //       The empty string with flag 1 matches every command.

  return;
}
