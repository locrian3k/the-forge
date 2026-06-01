/* ex03_dungeon.c / Mimic 260316 / Dungeon room for comparison */

#pragma strong_types
#include "defs.h"

// Exercise 20.3, Room Comparison: Dungeon Version
// This room uses /room/dungeon/dr.c. The set_dungeon() call adds
// level scaling for monsters spawned here and registers the room
// with the dungeon system. Compare with ex03_standard.c.

inherit "room/dungeon/dr.c";

void create()
{
  ::create();

  // This is the key difference from ex03_standard.c.
  // Without this call, the room would behave like a normal room.
  set_dungeon("The Training Dungeon", 5, 1, 1, 1);

  set_light(1);
  set_short("A Quiet Alcove");
  set_long(
    "A small alcove branches off from the main corridor. Rough "
    "wooden shelves line the walls, holding a scattering of old "
    "candles and dusty jars. The dungeon air carries a faint "
    "chill that makes the candle flames flicker and dance."
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
