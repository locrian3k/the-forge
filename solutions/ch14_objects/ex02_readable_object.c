#pragma strong_types
#include "../defs.h"
inherit "obj/treasure";

// Exercise 14.2 - Readable Object
// A tattered scroll that can be read using add_action().

void create()
{
  ::create();
  set_creator("mimic");
  set_name("scroll");
  set_alias(({"tattered scroll","old scroll","parchment",
    "ancient scroll"}));
  set_short("A Tattered Scroll");
  set_long(
    "A rolled-up piece of ancient parchment, its edges brown "
    "and crumbling. The scroll is tied with a faded red ribbon. "
    "Despite its age, the ink within appears still legible. "
    "Perhaps you should read it.");
  set_weight(1);
  set_value(30);
  return;
}

void init()
{
  ::init();
  add_action("do_read", "read");
  return;
}

// Handle the "read" command. Displays the scroll's contents
// if the player is referring to this object.
status do_read(string str)
{
  if (!str || !id(str))
    return 0;

  write(
    "You carefully unroll the brittle parchment and read:\n"
    "\n"
    "  Let it be known that the Keeper of the Eastern Gate\n"
    "  has failed in his sacred charge. The wards are broken.\n"
    "  Three seals remain, hidden where shadow meets stone.\n"
    "  Seek the first beneath the Watchful Eye, the second\n"
    "  in the Drowned Hall, and the third where no light\n"
    "  has ever reached.\n"
    "\n"
    "  May the next reader fare better than I.\n"
    "\n"
    "The rest of the text is too faded to decipher.\n");
  return 1;
}
