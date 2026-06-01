/*
  ex02_rm3.c
  Exercise 18.2 — Area Layout: Room 3
  Central chamber connecting Room 2 (west) and Room 4 (north).
*/

#pragma strong_types
#include "../defs.h"

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  // TODO: Set short and long descriptions for a central chamber
  //       (e.g. a practice room, a wide chamber with pillars).

  // TODO: Add examinable items relevant to the room's theme.

  // TODO: Add bidirectional exits:
  //       - west back to Room 2
  //       - north to Room 4

  return;
}
