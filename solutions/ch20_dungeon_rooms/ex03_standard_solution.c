/* ex03_standard.c / Mimic 260316 / Standard room for comparison */

#pragma strong_types
#include "defs.h"

// Exercise 20.3, Room Comparison: Standard Version
// This room uses /room/room. Compare with ex03_dungeon.c to see
// what the dungeon layer adds. The room layout, items, and exits
// are identical so the only difference is the inheritance.

inherit "room/room";

void create()
{
  ::create();

  set_light(1);
  set_short("A Quiet Alcove");
  set_long(
    "A small alcove branches off from the main corridor. Rough "
    "wooden shelves line the walls, holding a scattering of old "
    "candles and dusty jars. The air is still and quiet here, "
    "untouched by the drafts that sweep through the passages."
  );

  add_item(
    ({"shelves", "wooden shelves"}),
    "Rough-cut wooden shelves are fixed to the stone walls with "
    "iron brackets. They hold an assortment of half-melted candles "
    "and ceramic jars sealed with wax."
  );
  add_item(
    ({"candles", "old candles"}),
    "A collection of candles in various states of decay. Some are "
    "mere stubs of tallow, others still have a wick poking from "
    "a pool of hardened wax."
  );

  add_exit(TO, "north");

  return;
}
