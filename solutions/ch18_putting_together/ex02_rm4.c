#pragma strong_types
#include "defs.h"

// Exercise 18.2, Area Layout: Room 4
// Dead-end room at the north end of the Training Grounds.

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  set_short("The Armory Alcove");
  set_long(
    "A small alcove at the end of the passage, lined with "
    "weapon racks and armor stands. Most are empty, but a "
    "few rusty practice weapons remain. Cobwebs hang thick "
    "in the corners. The only exit leads south."
  );

  add_item(
    ({"racks", "weapon racks", "weapons", "practice weapons"}),
    "Wooden weapon racks line the walls, mostly empty. A few "
    "dull practice swords and blunted spears remain."
  );
  add_item(
    ({"armor stands", "stands", "armor"}),
    "Wooden armor stands, most bare. One holds a dented "
    "breastplate that has seen far better days."
  );
  add_item(
    ({"cobwebs", "webs", "corners"}),
    "Thick cobwebs drape the corners, suggesting this alcove "
    "has not seen much use lately."
  );

  // Single exit back south
  add_exit(TRAINING_ROOM + "rm3", "south");

  return;
}
