/*
  ex02_dungeon_features.c
  YourName YYMMDD
  Exercise 20.2 — Dungeon Features (add_clone)
  Create a dungeon room that uses add_clone() to spawn objects
  or monsters. Unlike clone_object()->move(), add_clone()
  handles deduplication and only spawns during reset cycles.
*/

#pragma strong_types
#include "defs.h"

inherit "room/dungeon/dr.c";

void create()
{
  ::create();

  // TODO: Register with the dungeon system using set_dungeon().

  // TODO: Set light, short, and long descriptions.

  // TODO: Add examinable items.

  // TODO: Add exits.

  // TODO: Use add_clone() to spawn objects in this room.
  //       Syntax: add_clone(path) — spawns one object (100% chance).
  //       Syntax: add_clone(path, numerator, denominator) — probability.
  //
  //       add_clone() differs from clone_object()->move() because:
  //         1. It checks for duplicates automatically
  //         2. It only spawns during reset cycles
  //         3. Monsters benefit from dungeon-level scaling

  return;
}
