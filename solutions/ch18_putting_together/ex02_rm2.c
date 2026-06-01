#pragma strong_types
#include "defs.h"

// Exercise 18.2, Area Layout: Room 2
// First interior room inside the Training Grounds.

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  set_short("Training Hall Entrance");
  set_long(
    "A long stone corridor stretches into the hillside, lit by "
    "iron-bracketed torches. The walls are scarred with old "
    "weapon marks, evidence of countless practice bouts. The "
    "passage continues east, while daylight filters in from "
    "the south."
  );

  add_item(
    ({"torches", "torch", "brackets"}),
    "Iron-bracketed torches line the walls, casting a warm "
    "but flickering light across the stone."
  );
  add_item(
    ({"walls", "marks", "weapon marks", "scars"}),
    "Deep gouges and slash marks cover the stone walls, "
    "left by generations of students honing their skills."
  );

  // Bidirectional exits
  add_exit(TRAINING + "entrance", "south");
  add_exit(TRAINING_ROOM + "rm3", "east");

  return;
}
