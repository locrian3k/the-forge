#pragma strong_types
#include "../defs.h"

// Exercise 18.4, Reset Spawning
// An area room that respawns monsters on reset using clone_object().

inherit TRAINING_ROOM + "droom";

void create()
{
  ::create();

  set_short("The Guard Post");
  set_long(
    "A cramped guard post hewn from rough stone. A wooden "
    "table is shoved against one wall, littered with bone "
    "dice and scraps of dried meat. A torch gutters in an "
    "iron sconce. Passages lead south and west."
  );

  add_item(
    ({"table", "wooden table", "dice", "meat"}),
    "A rickety wooden table covered with bone dice, scraps "
    "of dried meat, and a few dull copper coins. The guards "
    "were clearly mid-game."
  );
  add_item(
    ({"torch", "sconce"}),
    "A sputtering torch jammed into a rusted iron sconce. "
    "It casts uneven shadows across the room."
  );

  // Exits to adjacent rooms
  add_exit(TRAINING_ROOM + "rm3", "south");
  add_exit(TRAINING_ROOM + "rm2", "west");

  // Spawn an initial goblin guard
  clone_object(TRAINING_MOBS + "goblin")->move(TO);

  return;
}

// reset() is called periodically by the driver to repopulate the room.
// We use present() to check if a monster already exists before spawning,
// preventing duplicate monsters from stacking up.
void reset()
{
  ::reset();

  // Respawn a goblin guard if none exists
  if (!present("goblin"))
    clone_object(TRAINING_MOBS + "goblin")->move(TO);

  // Occasionally spawn a goblin scout (50% chance)
  if (!present("goblin_scout") && random(2))
    clone_object(TRAINING_MOBS + "goblin_scout")->move(TO);

  return;
}
