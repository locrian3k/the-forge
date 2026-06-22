/*
  ex04_hidden_item.c
  Exercise 13.4 — Hidden Treasure (companion object)
  A simple treasure object cloned by the interactive room when
  a player performs the custom command.
*/
#pragma strong_types
#include "../defs.h"
inherit "obj/treasure";

void create()
{
  ::create();

  // TODO: Set the object's internal name with set_name()

  // TODO: Set aliases with set_alias() using an array of
  //   at least 3 alternate names

  // TODO: Set a short description with set_short()

  // TODO: Set a long description with set_long()
  //   At least two sentences describing the object.

  // TODO: Set weight with set_weight()

  // TODO: Set coin value with set_value()

  return;
}
