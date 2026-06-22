/*
  ex01_basic_weapon.c
  Exercise 15.1 — Basic Weapon
  Create a simple weapon with a type, damage class, and descriptions.
  Inherit from /obj/weapon and configure it entirely in create().
*/

#pragma strong_types
#include "../defs.h"

inherit "obj/weapon";

void create()
{
  ::create();

  // TODO: Set the creator to "mimic" using set_creator()

  // TODO: Set the weapon's internal name using set_name() (lowercase)

  // TODO: Set at least 3 aliases using set_alias() with an array
  //       e.g. set_alias(({"alias1", "alias2", "alias3"}));

  // TODO: Set the short description using set_short()

  // TODO: Set the long description using set_long()
  //       Make it at least two sentences describing the weapon's
  //       appearance.

  // TODO: Set the weapon type using set_type()
  //       Must be one of: "sword", "axe", "club", "knife",
  //       "staff", "whip"

  // TODO: Set the weapon class (damage) using set_wc()
  //       This is a single integer, typical range 5-20

  // TODO: Set the weight using set_weight() (typically 2-5)

  // TODO: Set the coin value using set_value()

  return;
}
