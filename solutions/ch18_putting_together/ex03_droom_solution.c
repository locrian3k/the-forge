#pragma strong_types
#include "../defs.h"

// Exercise 18.3, Base Area Room
// Inheritable base room for the Training Grounds area.
// All interior rooms in the area should inherit this file.

inherit "room/room";

// Mapping of all compass directions for wall-blocking
mapping all_dirs_map =
([
  "north",
  "south",
  "east",
  "west",
  "northeast",
  "northwest",
  "southeast",
  "southwest",
  "up",
  "down"
]);

void create()
{
  ::create();
  set_light(1);

  return;
}

// Block movement in directions that have no exit defined.
// Returns 1 to block the action, 0 to allow it.
status block_them(string arg)
{
  string verb;
  verb = query_verb();

  // If the direction is a valid exit, allow movement
  if (member(query_exits(), verb) || member(query_hidden(), verb))
    return 0;

  // If the player typed a compass direction with no exit, block it
  if (member(all_dirs_map, verb))
  {
    write("Solid stone blocks your way in that direction.\n");
    return 1;
  }

  // Not a direction at all, let other actions handle it
  return 0;
}

void init()
{
  ::init();

  // Catch all player input so block_them can check for invalid directions
  add_action("block_them", "", 1);

  return;
}
