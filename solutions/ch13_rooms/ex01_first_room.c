#pragma strong_types
#include "defs.h"
inherit "room/room";

// Exercise 13.1 - Your First Room
// A basic room with lighting, descriptions, and one exit.

void create()
{
  ::create();
  set_light(1);
  set_short("A Dusty Stone Chamber");

  set_long(
    "You stand in a small stone chamber carved from rough grey "
    "rock. Dust motes drift lazily through the stale air, and "
    "the walls are cold and damp to the touch. A narrow passage "
    "leads south.");

  // Exit loops back to this room for demonstration purposes.
  add_exit(EXERCISES + "ch13_rooms/ex01_first_room", "south");
  return;
}
