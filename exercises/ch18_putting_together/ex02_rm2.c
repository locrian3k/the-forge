/*
  ex02_rm2.c
  Exercise 18.2 — Area Layout: Room 2
  First interior room, connected south to the entrance and
  east to Room 3. Uses bidirectional exits.
*/

#pragma strong_types
#include "defs.h"

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  // TODO: Set short and long descriptions for an interior room
  //       (e.g. a torchlit corridor, a stone hallway).

  // TODO: Add examinable items (torches, walls, weapon marks, etc.)

  // TODO: Add bidirectional exits:
  //       - south back to the entrance
  //       - east to Room 3
  //       Use path constants from defs.h for room paths.

  return;
}
