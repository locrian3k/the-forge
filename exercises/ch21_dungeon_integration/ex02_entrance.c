/*
  ex02_entrance.c
  YourName YYMMDD
  Exercise 21.2 — Area Layout: Entrance
  The outdoor entrance to the dungeon. Uses /room/room (not
  the dungeon base room) since it is outside the dungeon.
*/

#pragma strong_types
#include "defs.h"

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  // TODO: Set the short description for the outdoor entrance.

  // TODO: Set the long description. Describe the path, the cave
  //       entrance, surrounding terrain, and any signs/markers.

  // TODO: Add examinable scenery items (path, trees, entrance,
  //       sign, etc.) using add_item().

  // TODO: Add an exit north into the dungeon.
  //       The first interior room is ex02_rm2.
  //       Use the TRAINING_ROOM path constant.

  return;
}
