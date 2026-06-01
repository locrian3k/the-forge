/*
  ex01_basic_armor.c
  Exercise 16.1 — Basic Armor
  Create a piece of armor with a type and a 10-element AC array.
  Note: 3K uses the British spelling /obj/armour.
*/

#pragma strong_types
#include "defs.h"

inherit "obj/armour";

void create()
{
  ::create();

  // TODO: Set the creator to "mimic" using set_creator()

  // TODO: Set the armor's internal name using set_name() (lowercase)

  // TODO: Set at least 3 aliases using set_alias()

  // TODO: Set the short description using set_short()

  // TODO: Set the long description using set_long()
  //       Make it at least two sentences.

  // TODO: Set the armor type using set_type()
  //       Must be one of: "helmet", "shield", "cloak", "glove",
  //       "boot", "armour", "pants", "belt", "amulet", "ring"

  // TODO: Set the armor class using set_ac() with a 10-element array:
  //       ({edged, blunt, fire, ice, acid, elec, mind, energy, poison, rad})
  //       Each value is typically 0-5. Higher = more protection.
  //       Tailor the values to match your armor's theme, e.g. a
  //       steel helmet should be strong vs edged/blunt.

  // TODO: Set the weight using set_weight() (typically 1-4)

  // TODO: Set the gold value using set_value()

  return;
}
