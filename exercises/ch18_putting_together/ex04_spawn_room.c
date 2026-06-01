/*
  ex04_spawn_room.c
  Exercise 18.4 — Reset Spawning
  Create a room that spawns monsters using clone_object() in
  create() and respawns them in reset(). Uses present() to
  prevent duplicate monsters from stacking up.
*/

#pragma strong_types
#include "defs.h"

// This room inherits the base droom from exercise 18.3
inherit TRAINING_ROOM + "droom";

void create()
{
  ::create();

  // TODO: Set short and long descriptions for a guard post room.

  // TODO: Add examinable items.

  // TODO: Add exits to adjacent rooms.

  // TODO: Spawn an initial monster using clone_object():
  //       clone_object(TRAINING_MOBS + "goblin")->move(TO);

  return;
}

// reset() is called periodically by the driver to repopulate rooms.
// Use present() to check if a monster already exists before
// spawning, preventing duplicate monsters from stacking up.
void reset()
{
  ::reset();

  // TODO: Respawn a goblin guard if none exists:
  //       if (!present("goblin"))
  //         clone_object(TRAINING_MOBS + "goblin")->move(TO);

  // TODO: Optionally spawn a second monster type with a random
  //       chance, e.g. 50% chance:
  //       if (!present("goblin_scout") && random(2))
  //         clone_object(TRAINING_MOBS + "goblin_scout")->move(TO);

  return;
}
