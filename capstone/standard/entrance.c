/*
  entrance.c
  YourName YYMMDD
  Outdoor entrance to your area.
*/
#pragma strong_types
#include "defs.h"

inherit "room/room";

void create()
{
  ::create();

  set_light(1);

  // TODO: Set the short description (one line, shown in movement messages).
  // set_short("Outside Your Area");

  // TODO: Set the long description (what players see when they look).
  // set_long(
  //   "A description of the outdoor entrance to your area. "
  //   "Describe what players see as they approach."
  // );

  // TODO: Add examinable items (at least 3).
  // add_item("path", "A worn dirt path leads north.");
  // add_item("trees", "Tall oaks surround the clearing.");
  // add_item("sign", "A wooden sign points the way.");

  // TODO: Add an exit into your area.
  // add_exit(MY_ROOMS + "rm2", "north");

  return;
}
