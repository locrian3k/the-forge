/*
  ex03_spawn_room.c
  Exercise 21.3 — Reset Spawning with add_clone
  Create a dungeon room that uses add_clone() to spawn monsters.
  Unlike clone_object()->move(), add_clone() handles deduplication
  automatically and integrates with the dungeon system's scaling.
*/

#pragma strong_types
#include "defs.h"

// Inherit the base droom from exercise 21.1
inherit TRAINING_ROOM + "ex01_droom";

void create()
{
  ::create();

  // TODO: Set short and long descriptions for a guard post room.

  // TODO: Add examinable items (table, torch, etc.)

  // TODO: Add exits to adjacent rooms.

  // TODO: Spawn an initial monster using the monster() helper
  //       from the base droom:
  //       monster("goblin");
  //       This calls add_clone(TRAINING_MOBS + "goblin").

  return;
}

// reset() is called periodically by the driver to repopulate rooms.
// add_clone() checks for existing copies automatically, so we do
// not need manual present() checks like we would with clone_object().
void reset()
{
  ::reset();

  // TODO: Always try to respawn the goblin guard.
  //       add_clone() skips if one already exists.
  //       add_clone(TRAINING_MOBS + "goblin");

  // TODO: Optionally spawn a second monster type with a probability.
  //       add_clone(path, numerator, denominator) sets the chance.
  //       add_clone(TRAINING_MOBS + "goblin_scout", 1, 2);  // 50%

  return;
}
