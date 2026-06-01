/*
  ex01_first_room.c
  Exercise 13.1 — Your First Room
  Create a basic room that a player can enter, look around in,
  and leave through an exit.
*/
#pragma strong_types
#include "../defs.h"
inherit "room/room";

void create()
{
  ::create();

  // TODO: Set room lighting so players can see.
  //   Syntax: set_light(level);

  // TODO: Set a short description (shown in brief mode and on the map).

  // TODO: Set a long description (at least two sentences describing
  //   the room). You can break long strings across multiple lines by
  //   placing them next to each other: "part one " "part two"

  // TODO: Add one exit. Use this file's own path as the destination
  //   so it loops back to itself for testing.
  //   Syntax: add_exit(path, direction);

  return;
}
