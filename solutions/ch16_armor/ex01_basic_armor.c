#pragma strong_types
#include "../defs.h"
inherit "obj/armour";

// Exercise 16.1 - Basic Armor
// A steel helmet with physical and minor elemental protection.

void create()
{
  ::create();
  set_creator("mimic");
  set_name("steel helmet");
  set_alias(({"helmet","helm","steel helm","iron helmet"}));
  set_short("A Polished Steel Helmet");
  set_long(
    "A well-crafted helmet of polished steel with a nose guard "
    "and cheek plates. The metal is thick enough to turn a solid "
    "blow, and the interior is lined with padded leather for "
    "comfort. A faint dent on the left side suggests it has "
    "already saved someone's life at least once.");
  set_type("helmet");

  // Protection: good vs edged/blunt, minor fire/ice resistance
  // ({edged, blunt, fire, ice, acid, elec, mind, energy, poison, rad})
  set_ac(({2, 3, 1, 1, 0, 0, 0, 0, 0, 0}));

  set_weight(2);
  set_value(200);
  return;
}
