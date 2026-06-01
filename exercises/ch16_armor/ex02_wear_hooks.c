/*
  ex02_wear_hooks.c
  Exercise 16.2 — Wear/Remove Hooks
  Create armor with do_wear() and do_remove() callbacks.
  Enforce a level requirement and display thematic messages.
*/

#pragma strong_types
#include "../defs.h"

inherit "obj/armour";

void create()
{
  ::create();

  // TODO: Set creator, name, aliases, short, long, type, ac,
  //       weight, and value (same as basic armor)

  // TODO: Register wear and remove hook functions.
  //       This tells the system to call do_wear() and do_remove()
  //       on this object when a player wears or removes it.

  return;
}

// Called when a player tries to wear this armor.
// Return 1 to allow wearing, 0 to block it.
// Use TP to refer to the player trying to wear the item.
status do_wear()
{
  // TODO: Check if the player meets a level requirement.
  //       Use (int)TP->query_level() to get the player's level.
  //
  //       If the player's level is too low:
  //         - Use notify_fail() with a thematic message explaining
  //           why they can't wear it
  //         - return 0; to block
  //
  //       If the player meets the requirement:
  //         - Use write() to show a message to the player
  //         - Use say() to show a message to the room
  //           (use TP->query_name() for the player's name)
  //         - return 1; to allow

  return 1;
}

// Called when a player removes this armor.
// Return 1 to allow removal (almost always should).
status do_remove()
{
  // TODO: Display a thematic removal message to the player
  //       with write() and to the room with say().
  //       Then return 1 to allow the removal.

  return 1;
}
