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

  // TODO: Spawn an initial monster using clone_object().
  //       Use TRAINING_MOBS path constant and move it to TO.

  return;
}

// reset() is called periodically by the driver to repopulate rooms.
// Use present() to check if a monster already exists before
// spawning, preventing duplicate monsters from stacking up.
void reset()
{
  ::reset();

  // TODO: Respawn a goblin guard if none exists.
  //       Use present() to check, clone_object() to create, ->move(TO) to place.

  // TODO: Optionally spawn a second monster type with a random
  //       chance (e.g. 50% using random(2)).

  return;
}
