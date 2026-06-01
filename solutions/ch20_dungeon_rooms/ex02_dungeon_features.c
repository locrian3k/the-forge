/* ex02_dungeon_features.c / Mimic 260316 / Dungeon features with add_clone */

#pragma strong_types
#include "defs.h"

// Exercise 20.2, Dungeon Features
// Demonstrates add_clone(), a dungeon-specific feature that
// spawns objects or monsters in the room during reset cycles.

inherit "room/dungeon/dr.c";

void create()
{
  ::create();

  set_dungeon("The Training Dungeon", 8, 1, 1, 1);

  set_light(1);
  set_short("A Dusty Armory");
  set_long(
    "This wide chamber once served as an armory. Wooden racks "
    "line the walls, most of them empty or broken. A thick layer "
    "of dust covers everything, disturbed only by the occasional "
    "footprint. A few pieces of equipment remain scattered about, "
    "forgotten by whoever once garrisoned this place."
  );

  add_item(
    ({"racks", "weapon racks", "wooden racks"}),
    "Sturdy wooden racks line the walls, built to hold swords "
    "and spears. Most slots stand empty now, the wood cracked "
    "and dry with age."
  );
  add_item(
    ({"stands", "armor stands"}),
    "A row of wooden armor stands lines the far wall. Only one "
    "still holds a battered set of leather armor, the rest bare."
  );
  add_item(
    ({"dust", "layer"}),
    "A thick blanket of grey dust coats every surface. It swirls "
    "lazily in the faint draft that seeps through the room."
  );

  add_exit(TO, "east");
  add_exit(TO, "west");

  // add_clone() is a dungeon room feature. Unlike clone_object()->move(),
  // add_clone() registers the object with the dungeon system so it:
  //   1. Checks for duplicates automatically (won't stack up on reset)
  //   2. Only spawns during reset cycles, not on every room load
  //   3. Benefits from dungeon-level scaling for monsters
  //
  // Usage: add_clone(path)
  //        add_clone(path, chance_numerator, chance_denominator)
  //   The optional second and third args set spawn probability:
  //   add_clone("/obj/treasure", 1, 2) means 1 in 2 chance (50%).
  add_clone("/obj/treasure");

  return;
}
