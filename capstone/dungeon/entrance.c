// Haunted Mine - Entrance (outdoor, no dungeon scaling)
// /players/<name>/areas/haunted_mine/entrance.c

#pragma strong_types
#include "defs.h"
inherit "room/dungeon/dr.c";

void create()
{
  ::create();
  set_light(1);

  // TODO: Set the room's short description (the room title).
  // Example: set_short("An Abandoned Minehead");

  // TODO: Set the room's long description (what the player sees on 'look').
  // Describe the abandoned mine entrance on a hillside. 2-3 sentences.
  // Example:
  // set_long(
  //   "A gaping hole in the hillside marks the entrance to a long-abandoned "
  //   "mine. Rotting timber frames the opening, and a cold draft breathes "
  //   "outward carrying the faint sound of dripping water.");

  // TODO: Add at least 3 examinable items with add_item().
  // Think about what a player would see at an abandoned mine entrance:
  //   - The mine entrance itself
  //   - The hillside or surrounding terrain
  //   - Old equipment (carts, rails, winches)
  //   - Warning signs or posted notices
  //   - The timber framing
  //
  // Example:
  // add_item(({"entrance","mine","opening","hole"}),
  //   "Description of the mine entrance here.");

  // TODO: Add an exit leading into the mine.
  // The entrance connects south to the first interior room (rm2).
  //
  // add_exit(HM_ROOM + "rm2", "south");

  return;
}
