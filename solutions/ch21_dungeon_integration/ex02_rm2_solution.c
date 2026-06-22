/* ex02_rm2.c / Mimic 260316 / First dungeon room */

#pragma strong_types
#include "defs.h"

// Exercise 21.2, Area Layout: Room 2
// First interior room. Inherits the base droom so it gets
// set_dungeon(), set_light(), and direction blocking for free.

inherit TRAINING_ROOM + "ex01_droom";

void create()
{
  ::create();

  set_short("A Torchlit Corridor");
  set_long(
    "A corridor stretches into the dungeon, its walls lined "
    "with iron sconces holding sputtering torches. The stone "
    "floor is well-worn from years of traffic. The cave "
    "entrance lies to the south, and the passage continues "
    "east into a wider chamber."
  );

  add_item(
    ({"torches", "sconces", "iron sconces"}),
    "Iron sconces are bolted to the walls at regular intervals, "
    "each holding a torch of bundled reeds and pitch. They cast "
    "a warm but unsteady light."
  );
  add_item(
    ({"walls", "stone"}),
    "The corridor walls are rough-hewn stone, scored with chisel "
    "marks and blackened by torch smoke near the ceiling."
  );

  add_exit(TRAINING_ROOM + "ex02_entrance", "south");
  add_exit(TRAINING_ROOM + "ex02_rm3", "east");

  return;
}
