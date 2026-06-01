/*
  ex02_entrance.c
  Exercise 18.2 — Area Layout: Entrance
  Create the outdoor entrance room for the Training Grounds area.
  This is a standard /room/room (not a dungeon room) since it
  is outside the dungeon.
*/

#pragma strong_types
#include "../defs.h"

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  // TODO: Set the short description for this outdoor entrance.

  // TODO: Set the long description. Describe the path, an archway
  //       or cave entrance, and any scenery like signs or runes.

  // TODO: Add examinable scenery items using add_item().
  //       Include at least 2-3 items players can look at.

  // TODO: Add an exit leading north into the area.
  //       Use the TRAINING_ROOM path constant from defs.h.

  return;
}
