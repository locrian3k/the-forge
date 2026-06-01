/*
  ex01_dungeon_room.c
  Exercise 20.1 — Basic Dungeon Room
  Create a room using /room/dungeon/dr.c instead of /room/room.
  The key addition is set_dungeon(), which registers this room
  with the dungeon system and enables level-based scaling.
*/

#pragma strong_types
#include "defs.h"

inherit "room/dungeon/dr.c";

void create()
{
  ::create();

  // TODO: Register this room with the dungeon system.
  //       set_dungeon(name, level, scale_hp, scale_damage, scale_exp)
  //         name         - The dungeon's display name (string)
  //         level        - Base difficulty level (int, e.g. 5)
  //         scale_hp     - HP multiplier for monsters (1 = normal)
  //         scale_damage - Damage multiplier for monsters (1 = normal)
  //         scale_exp    - Experience multiplier (1 = normal)
  //
  //       Example: set_dungeon("The Training Dungeon", 5, 1, 1, 1);

  // TODO: Set light so the room is visible: set_light(1);

  // TODO: Set short and long descriptions for a dungeon passage.

  // TODO: Add examinable items using add_item()
  //       (works exactly like /room/room).

  // TODO: Add at least one exit using add_exit()
  //       (works exactly like /room/room).

  return;
}
