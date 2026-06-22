#pragma strong_types
#include "../defs.h"

// Exercise 18.2, Area Layout: Room 3
// Central training chamber with exits west and north.

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  set_short("The Practice Chamber");
  set_long(
    "A wide chamber opens up here, its ceiling supported by "
    "thick stone pillars. Training dummies line one wall, "
    "their straw innards spilling from countless stab wounds. "
    "Passages lead west and north."
  );

  add_item(
    ({"dummies", "dummy", "training dummies", "straw"}),
    "Battered training dummies made of wood and straw. They "
    "have been stabbed, slashed, and bludgeoned into sorry shape."
  );
  add_item(
    ({"pillars", "pillar", "columns"}),
    "Thick stone pillars support the ceiling, each one chipped "
    "and dented from errant weapon swings."
  );

  // Bidirectional exits
  add_exit(TRAINING_ROOM + "rm2", "west");
  add_exit(TRAINING_ROOM + "rm4", "north");

  return;
}
