/*
  ex02_rm2.c
  Exercise 21.2 — Area Layout: Room 2
  First interior dungeon room. Inherits the base droom so it
  gets set_dungeon(), set_light(), and direction blocking for free.
  Connected south to the entrance and east to Room 3.
*/

#pragma strong_types
#include "defs.h"

// Inherit the base droom from exercise 21.1
inherit TRAINING_ROOM + "ex01_droom";

void create()
{
  ::create();

  // TODO: Set short and long descriptions for a torchlit corridor.
  //       Note: set_light() and set_dungeon() are already called
  //       by the parent droom, so you don't need them here.

  // TODO: Add examinable items (torches, walls, etc.)

  // TODO: Add exits south to the entrance and east to Room 3.
  //       Use the TRAINING_ROOM path constant.

  return;
}
