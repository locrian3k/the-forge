#pragma strong_types
#include "../defs.h"
inherit "obj/treasure";

// Exercise 13.4 - Hidden Amulet (companion treasure object)
// Cloned by the interactive room when a player digs rubble.

void create()
{
  ::create();
  set_name("amulet");
  set_alias(({"bronze amulet","tarnished amulet","old amulet"}));
  set_short("A Tarnished Bronze Amulet");
  set_long(
    "A small amulet cast in bronze, its surface darkened with "
    "age and grime. A faint design on the face depicts a coiled "
    "serpent encircling a single eye. It feels oddly warm to the "
    "touch.");
  set_weight(1);
  set_value(75);
  return;
}
