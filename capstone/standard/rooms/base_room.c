/*
  base_room.c
  YourName YYMMDD
  Base room that all interior rooms in this area inherit from.
  Shared setup goes here so individual rooms stay short.
*/
#pragma strong_types
#include "../defs.h"

inherit "room/room";

// Mapping of all compass directions for the direction blocker.
mapping all_dirs_map = ([
  "north" : 1, "south" : 1, "east" : 1, "west" : 1,
  "northeast" : 1, "northwest" : 1, "southeast" : 1, "southwest" : 1,
  "up" : 1, "down" : 1,
]);

void create()
{
  ::create();
  set_light(1);

  // TODO: Add default items that all rooms share (walls, floor, air, etc.).
  // add_item("walls", "Stone walls surround you.");
  // add_item("floor", "The floor is packed earth.");

  return;
}

// Block movement in directions that have no exit.
// Players get a custom message instead of the default "You cannot go that way."
status block_them(string arg)
{
  string verb;

  verb = query_verb();
  if (!member(all_dirs_map, verb))
    return 0;
  if (member(query_exits(), verb) || member(query_hidden(), verb))
    return 0;

  // TODO: Customize the blocked message for your area's theme.
  write("There is no passage in that direction.\n");
  return 1;
}

void init()
{
  ::init();
  add_action("block_them", "", 1);
  return;
}
