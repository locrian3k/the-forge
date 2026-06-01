/*
  ex01_treasure.c
  Exercise 14.1 — Treasure Object
  Create a treasure object that players can pick up, examine,
  and sell to shops. Includes examinable sub-details.
*/
#pragma strong_types
#include "defs.h"
inherit "obj/treasure";

void create()
{
  ::create();

  // TODO: Set the creator
  //   set_creator("mimic");

  // TODO: Set the internal name (lowercase, used by the game engine)
  //   set_name("gold ring");

  // TODO: Set aliases with at least 3 alternate names
  //   set_alias(({"ring","gold ring","signet","signet ring","band"}));

  // TODO: Set a short description (shown in inventory lists)
  //   set_short("A Gold Signet Ring");

  // TODO: Set a long description (at least two sentences)
  //   Describe what the object looks like in detail.

  // TODO: Add at least one add_item() for an examinable detail
  //   on the object. Example:
  //   add_item(({"signet","seal","face","crest"}),
  //     "The signet depicts a rearing griffin...");

  // TODO: Set a gold value with set_value() (positive integer)

  // TODO: Set a weight with set_weight() (positive integer, 1-5)

  return;
}
