/* ex01_dungeon_room.c / Mimic 260316 / Basic dungeon room example */

#pragma strong_types
#include "defs.h"

// Exercise 20.1, Basic Dungeon Room
// Demonstrates what /room/dungeon/dr.c adds over /room/room.
// The key difference is set_dungeon(), which registers this room
// with the dungeon system and enables level-based scaling for
// any monsters spawned here.

inherit "room/dungeon/dr.c";

void create()
{
  ::create();

  // set_dungeon(name, level, scale_hp, scale_damage, scale_exp)
  //   name        - The dungeon's display name
  //   level       - Base difficulty level for the dungeon
  //   scale_hp    - Multiplier for monster hit points (1 = normal)
  //   scale_damage - Multiplier for monster damage (1 = normal)
  //   scale_exp   - Multiplier for monster experience (1 = normal)
  set_dungeon("The Training Dungeon", 5, 1, 1, 1);

  set_light(1);
  set_short("A Narrow Stone Passage");
  set_long(
    "A narrow passage cuts through solid stone, its walls "
    "worn smooth by centuries of footsteps. The air is cool "
    "and damp, carrying a faint echo of dripping water from "
    "somewhere deeper within the dungeon. Faint torchlight "
    "flickers against the rough ceiling overhead."
  );

  // add_item works exactly as it does in /room/room
  add_item(
    ({"walls", "stone", "passage"}),
    "The stone walls are worn smooth in places where countless "
    "hands have brushed against them. Thin veins of quartz "
    "glitter faintly in the torchlight."
  );
  add_item(
    ({"floor", "ground"}),
    "The stone floor is uneven but well-trodden, polished by "
    "years of use into a walkable surface."
  );

  // Exits work the same as /room/room
  add_exit(TO, "south");

  return;
}
