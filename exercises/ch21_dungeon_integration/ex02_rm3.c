/*
  ex02_rm3.c
  Exercise 21.2 — Area Layout: Room 3
  Central chamber connecting Room 2 (west) and Room 4 (north).
  Inherits the base droom.
*/

#pragma strong_types
#include "defs.h"

inherit TRAINING_ROOM + "ex01_droom";

void create()
{
  ::create();

  // TODO: Set short and long descriptions for a central chamber
  //       (e.g. a vaulted room with pillars).

  // TODO: Add examinable items (pillars, floor, etc.)

  // TODO: Add exits:
  //       add_exit(TRAINING_ROOM + "ex02_rm2", "west");
  //       add_exit(TRAINING_ROOM + "ex02_rm4", "north");

  return;
}
