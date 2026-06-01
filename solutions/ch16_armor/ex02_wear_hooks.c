#pragma strong_types
#include "defs.h"
inherit "obj/armour";

// Exercise 16.2 - Wear/Remove Hooks
// An enchanted cloak that requires level 10+ to wear.
// Displays thematic messages on wear and remove.

void create()
{
  ::create();
  set_creator("mimic");
  set_name("enchanted cloak");
  set_alias(({"cloak","enchanted cloak","shadow cloak",
    "dark cloak"}));
  set_short("An Enchanted Shadow Cloak");
  set_long(
    "A sweeping cloak woven from fabric so dark it seems to "
    "drink in the surrounding light. Faint silver runes "
    "shimmer along the hem, flickering in and out of "
    "visibility. The clasp is fashioned from black iron in "
    "the shape of a crescent moon.");
  set_type("cloak");

  // Protection: strong vs mind/energy, moderate physical
  // ({edged, blunt, fire, ice, acid, elec, mind, energy, poison, rad})
  set_ac(({1, 1, 0, 1, 0, 0, 3, 2, 0, 0}));

  set_weight(2);
  set_value(400);

  // Register wear and remove hook functions
  set_wear_func(TO);
  set_remove_func(TO);
  return;
}

// Called when a player tries to wear this cloak.
// Requires level 10 or higher.
status do_wear()
{
  if ((int)TP->query_level() < 10)
  {
    notify_fail(
      "As you swing the cloak over your shoulders, the silver "
      "runes flare white-hot and the fabric writhes away from "
      "you. You are not yet strong enough to command its "
      "power.\n");
    return 0;
  }

  write(
    "You clasp the shadow cloak around your shoulders. The "
    "silver runes pulse once and the fabric settles against "
    "you like a second skin. Shadows gather at the edges of "
    "your vision, and you feel strangely lighter.\n");
  say(sprintf(
    "Shadows coil around %s as a dark cloak settles over "
    "their shoulders.\n",
    capitalize((string)TP->query_name())));
  return 1;
}

// Called when a player removes this cloak.
// Always succeeds (return 1).
status do_remove()
{
  write(
    "You unclasp the shadow cloak and the silver runes dim. "
    "The gathered shadows dissipate, and the ordinary light "
    "of the world rushes back in.\n");
  say(sprintf(
    "The shadows around %s scatter as they remove their "
    "dark cloak.\n",
    capitalize((string)TP->query_name())));
  return 1;
}
