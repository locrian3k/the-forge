#pragma strong_types
#include "../defs.h"
inherit "obj/treasure";

// Exercise 14.1 - Treasure Object
// A gold signet ring with examinable details.

void create()
{
  ::create();
  set_creator("mimic");
  set_name("gold ring");
  set_alias(({"ring","gold ring","signet","signet ring","band"}));
  set_short("A Gold Signet Ring");
  set_long(
    "A heavy gold ring bearing an ornate signet on its face. "
    "The band is thick and slightly scratched from years of "
    "use, but the gold still gleams warmly in the light. A "
    "tiny inscription runs along the inside of the band.");

  add_item(({"signet","seal","face","crest"}),
    "The signet depicts a rearing griffin clutching a sword "
    "in its talons, surrounded by a laurel wreath. It was "
    "once used to seal important correspondence.");

  add_item(({"inscription","writing","inside","band"}),
    "Tiny letters inscribed inside the band read: 'Duty Above "
    "All.' The engraving is worn but still legible.");

  set_value(250);
  set_weight(1);
  return;
}
