/*
  ex03_standard.c
  Exercise 20.3 — Room Comparison: Standard Version
  Create the same room using /room/room (no dungeon system).
  Compare with ex03_dungeon.c to see what the dungeon layer adds.
  The layout, items, and exits should be identical.
*/

#pragma strong_types
#include "defs.h"

inherit "room/room";

void create()
{
  ::create();

  // TODO: Set light, short, and long descriptions.
  //       Use the SAME descriptions as ex03_dungeon.c.

  // TODO: Add the same examinable items as ex03_dungeon.c.

  // TODO: Add the same exits as ex03_dungeon.c.

  // NOTE: There is no set_dungeon() call here. That is the
  //       entire difference between this file and ex03_dungeon.c.

  return;
}
