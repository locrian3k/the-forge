/*
  ex02_room_details.c
  Exercise 13.2 — Room Details
  A room enriched with examinable items, searchable features,
  and multiple exits.
*/
#pragma strong_types
#include "defs.h"
inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  // TODO: Set a short description for the room

  // TODO: Set a long description (mention several features that
  //   players might want to examine, and mention the available exits)

  // TODO: Add at least 3 add_item() calls, each with an alias array
  //   and a descriptive string. Example:
  //   add_item(({"table","oak table","heavy table"}),
  //     "A heavy oak table, its surface scarred with countless "
  //     "knife marks and grooves.");

  // TODO: Add at least 2 add_search_item() calls for discoverable
  //   details when the player types "search <keyword>". Example:
  //   add_search_item(({"table","oak table"}),
  //     "Rummaging under the table, you find a dull copper coin.");

  // TODO: Add at least 3 exits. You can loop them back to this
  //   room or connect to your ex01 room for testing.
  //   add_exit(EXERCISES + "ch13_rooms/ex02_room_details", "north");

  return;
}
