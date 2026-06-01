/*
  ex01_first_room.c
  Exercise 13.1 — Your First Room
  Create a basic room that a player can enter, look around in,
  and leave through an exit.
*/
#pragma strong_types
#include "defs.h"
inherit "room/room";

void create()
{
  ::create();

  // TODO: Set room lighting so players can see
  //   set_light(1);

  // TODO: Set a short description (shown in brief mode and on the map)
  //   set_short("A Dusty Stone Chamber");

  // TODO: Set a long description (at least two sentences describing
  //   the room). You can break long strings across multiple lines:
  //   set_long(
  //     "First part of description "
  //     "continues on the next line.");

  // TODO: Add one exit. Use this file's own path as the destination
  //   so it loops back to itself for testing:
  //   add_exit(EXERCISES + "ch13_rooms/ex01_first_room", "south");

  return;
}
