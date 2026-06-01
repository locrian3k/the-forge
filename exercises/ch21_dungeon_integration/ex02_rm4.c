/*
  ex02_rm4.c
  Exercise 21.2 — Area Layout: Room 4
  Dead-end alcove at the north end. Only exit leads south
  back to Room 3. Inherits the base droom.
*/

#pragma strong_types
#include "defs.h"

inherit TRAINING_ROOM + "ex01_droom";

void create()
{
  ::create();

  // TODO: Set short and long descriptions for a dead-end room
  //       (e.g. a collapsed alcove, a sealed chamber).

  // TODO: Add examinable items (rubble, carvings, etc.)

  // TODO: Add a single exit south back to Room 3:
  //       add_exit(TRAINING_ROOM + "ex02_rm3", "south");

  return;
}
