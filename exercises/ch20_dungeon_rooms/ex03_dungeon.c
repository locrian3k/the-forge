/*
  ex03_dungeon.c
  Exercise 20.3 — Room Comparison: Dungeon Version
  Create a room using /room/dungeon/dr.c with set_dungeon().
  Compare this with ex03_standard.c to see what the dungeon
  layer adds. Use the same layout and items in both files.
*/

#pragma strong_types
#include "defs.h"

inherit "room/dungeon/dr.c";

void create()
{
  ::create();

  // TODO: Register with the dungeon system.
  //       This is the key difference from ex03_standard.c.

  // TODO: Set light, short, and long descriptions.
  //       Use the SAME descriptions as ex03_standard.c so the
  //       only difference is the dungeon registration.

  // TODO: Add the same examinable items as ex03_standard.c.

  // TODO: Add the same exits as ex03_standard.c.

  return;
}
