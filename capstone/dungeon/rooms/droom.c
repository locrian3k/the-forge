// Base dungeon room for the Haunted Mine area.
// All mine rooms inherit from this file to get shared setup.
// /players/<name>/areas/haunted_mine/rooms/droom.c

#pragma strong_types
#include "../defs.h"
inherit "room/dungeon/dr.c";

// TODO: Set up dungeon scaling and shared room features.
//
// In create(), you need:
//   1. Call ::create() to initialize the parent
//   2. set_dungeon(DNAME, 8, 1, 1, 1) for level 8 scaling
//   3. set_light(1) so players can see
//   4. Add default add_item() calls that apply to ALL mine rooms
//      (tunnel walls, floor, darkness, air quality, etc.)
//   5. set_block_message() for invalid exit directions

void create()
{
  ::create();

  // TODO: Set dungeon scaling. Level 8 dungeon.
  // set_dungeon(DNAME, 8, 1, 1, 1);

  set_light(1);

  // TODO: Add 2+ default add_item() calls that every mine room shares.
  // These give players something to examine even before individual rooms
  // add their own items.
  //
  // Example:
  // add_item(({"tunnel","passage","mine"}),
  //   "The mine tunnel is carved from dark stone, supported by aging "
  //   "timber beams. Dust motes drift in the stale air.");
  //
  // add_item(({"walls","stone","rock"}),
  //   "Rough-hewn stone walls bear the marks of countless pickaxes. "
  //   "Veins of dark mineral streak through the grey rock.");

  // TODO: Set a block message for when players try invalid directions.
  // set_block_message("Solid rock blocks your way in that direction.\n");

  return;
}

// TODO (Phase 3): Add helper functions for spawning monsters and items.
// These are optional but save typing in individual room files.
//
// Example helper to clone monsters by short name:
//
// varargs object *addc(string x, int y)
// {
//   return add_clone(sprintf("%s%s", HM_MOBS, x), (y ? y : 1), 0, 1);
// }
//
// Example helper to clone items by short name:
//
// void item(string x) { add_clone(HM_ITEM + x); }

void init()
{
  ::init();
  return;
}
