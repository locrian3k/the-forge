/* ex03_spawn_room.c / Mimic 260316 / Dungeon room with reset spawning */

#pragma strong_types
#include "defs.h"

// Exercise 21.3, Reset Spawning with add_clone
// Demonstrates how to use add_clone() in both create() and reset()
// to populate a dungeon room with monsters that respawn.
//
// add_clone() is the dungeon system's spawn function. Unlike
// clone_object()->move(), add_clone() handles deduplication
// automatically: it checks if the object already exists in the
// room before spawning a new one.

inherit TRAINING_ROOM + "ex01_droom";

void create()
{
  ::create();

  set_short("A Goblin Guard Post");
  set_long(
    "A cramped chamber serves as a guard post for the dungeon's "
    "goblin inhabitants. A rickety wooden table holds scattered "
    "bone dice and scraps of dried meat. A guttering torch in "
    "an iron sconce provides dim, flickering light. Passages "
    "lead south and west."
  );

  add_item(
    ({"table", "wooden table", "dice", "meat"}),
    "A rickety wooden table covered with bone dice, scraps of "
    "dried meat, and a few dull copper coins. The guards were "
    "clearly mid-game."
  );
  add_item(
    ({"torch", "sconce"}),
    "A sputtering torch jammed into a rusted iron sconce. It "
    "casts uneven shadows across the room."
  );

  add_exit(TO, "south");
  add_exit(TO, "west");

  // Spawn an initial goblin guard using the monster() helper
  // from ex01_droom. This calls add_clone(TRAINING_MOBS + "goblin").
  monster("goblin");

  return;
}

// reset() is called periodically by the driver to repopulate rooms.
// add_clone() checks for existing copies automatically, so we do
// not need manual present() checks like we would with clone_object().
void reset()
{
  ::reset();

  // Always try to respawn the goblin guard.
  // add_clone() will skip if one already exists.
  add_clone(TRAINING_MOBS + "goblin");

  // Occasionally spawn a goblin scout with 50% chance.
  // add_clone(path, numerator, denominator) spawns with a
  // numerator-in-denominator probability. Here, 1 in 2 = 50%.
  add_clone(TRAINING_MOBS + "goblin_scout", 1, 2);

  return;
}
