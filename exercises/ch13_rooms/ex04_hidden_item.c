/*
  ex04_hidden_item.c
  Exercise 13.4 — Hidden Treasure (companion object)
  A simple treasure object cloned by the interactive room when
  a player performs the custom command.
*/
#pragma strong_types
#include "defs.h"
inherit "obj/treasure";

void create()
{
  ::create();

  // TODO: Set the object's internal name with set_name()
  //   Example: set_name("amulet");

  // TODO: Set aliases with set_alias() using an array of
  //   at least 3 alternate names
  //   Example: set_alias(({"bronze amulet","tarnished amulet",
  //     "old amulet"}));

  // TODO: Set a short description with set_short()
  //   Example: set_short("A Tarnished Bronze Amulet");

  // TODO: Set a long description with set_long()
  //   At least two sentences describing the object.

  // TODO: Set weight with set_weight() (small number like 1)

  // TODO: Set gold value with set_value() (e.g. 75)

  return;
}
