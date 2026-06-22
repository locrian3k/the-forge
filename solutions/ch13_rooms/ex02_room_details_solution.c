#pragma strong_types
#include "../defs.h"
inherit "room/room";

// Exercise 13.2 - Room Details
// A room enriched with examinable items, searchable features,
// and multiple exits.

void create()
{
  ::create();
  set_light(1);
  set_short("An Abandoned Guardroom");

  set_long(
    "This rectangular chamber once served as a guardroom. A "
    "heavy oak table sits in the centre, scarred with knife "
    "marks and ringed with old ale stains. Weapon racks line "
    "the east wall, mostly empty now. Torches gutter in iron "
    "sconces, casting shifting shadows across the stone floor. "
    "Exits lead north, east, and south.");

  // Examinable items, alias arrays let multiple keywords work
  add_item(({"table","oak table","heavy table"}),
    "A heavy oak table, its surface scarred with countless knife "
    "marks and grooves. Old ale stains form dark rings across "
    "the wood. Someone has carved a crude map into one corner.");

  add_item(({"racks","weapon racks","weapons","rack"}),
    "Iron weapon racks bolted to the east wall. Most of the pegs "
    "are empty, but a few bent nails and scraps of leather "
    "suggest this once held a respectable armoury.");

  add_item(({"torches","torch","sconces","light"}),
    "Sputtering torches wedged into iron sconces on the walls. "
    "The flames flicker unevenly, as if the air currents down "
    "here are unpredictable.");

  add_item(({"floor","stone floor","stones"}),
    "Worn stone flags, smoothed by countless boots over the "
    "years. Dark stains in the corners could be old blood or "
    "just spilled ale. You prefer not to look too closely.");

  // Searchable features, revealed by 'search <keyword>'
  add_search_item(({"table","oak table","heavy table"}),
    "Rummaging under the table, you find a dull copper coin and "
    "a broken clay pipe.");

  add_search_item(({"racks","weapon racks","rack","weapons"}),
    "Behind a loose bracket on the weapon rack, you discover a "
    "small whetstone someone tucked away for safekeeping.");

  // Three exits (loop back to self for demonstration)
  add_exit(SOLUTIONS + "ch13_rooms/ex02_room_details", "north");
  add_exit(SOLUTIONS + "ch13_rooms/ex02_room_details", "east");
  add_exit(SOLUTIONS + "ch13_rooms/ex02_room_details", "south");
  return;
}
