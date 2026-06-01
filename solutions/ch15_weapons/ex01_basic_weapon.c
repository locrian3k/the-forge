#pragma strong_types
#include "../defs.h"
inherit "obj/weapon";

// Exercise 15.1 - Basic Weapon
// A simple iron battleaxe with standard weapon properties.

void create()
{
  ::create();
  set_creator("mimic");
  set_name("iron battleaxe");
  set_alias(({"axe","battleaxe","iron axe","battle axe"}));
  set_short("An Iron Battleaxe");
  set_long(
    "A sturdy battleaxe forged from dark iron. The broad, "
    "double-edged blade is pitted and scarred from heavy use, "
    "but its edge remains keen. The haft is wrapped in strips "
    "of worn leather for a sure grip.");
  set_type("axe");
  set_wc(15);
  set_weight(4);
  set_value(300);
  return;
}
