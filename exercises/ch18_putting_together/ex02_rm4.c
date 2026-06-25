/*
  ex02_rm4.c
  YourName YYMMDD
  Exercise 18.2 — Area Layout: Room 4
  Dead-end room at the north end. Only exit leads south
  back to Room 3.
*/

#pragma strong_types
#include "../defs.h"

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  // TODO: Set short and long descriptions for a dead-end room
  //       (e.g. an armory alcove, a storage area).

  // TODO: Add examinable items (weapon racks, armor stands,
  //       cobwebs, etc.)

  // TODO: Add a single exit south back to Room 3.

  return;
}
