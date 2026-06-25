/*
  ex01_treasure.c
  YourName YYMMDD
  Exercise 14.1 — Treasure Object
  Create a treasure object that players can pick up, examine,
  and sell to shops. Includes examinable sub-details.
*/
#pragma strong_types
#include "../defs.h"
inherit "obj/treasure";

void create()
{
  ::create();

  // TODO: Set the creator using set_creator()

  // TODO: Set the internal name (lowercase, used by the game engine)
  //   using set_name()

  // TODO: Set aliases with at least 3 alternate names
  //   using set_alias()

  // TODO: Set a short description (shown in inventory lists)
  //   using set_short()

  // TODO: Set a long description (at least two sentences)
  //   using set_long(). Describe what the object looks like in detail.

  // TODO: Add at least one add_item() for an examinable detail
  //   on the object.

  // TODO: Set a coin value with set_value() (positive integer)

  // TODO: Set a weight with set_weight() (positive integer, 1-5)

  return;
}
