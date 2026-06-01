#pragma strong_types
#include "defs.h"
inherit "room/room";

// Exercise 13.3 - Readable Items
// A room with a readable inscription using add_read()
// and a named callback function. Includes SCREENREAD support.

void create()
{
  ::create();
  set_light(1);
  set_short("A Shrine Antechamber");

  set_long(
    "A small antechamber opens before you, its walls lined with "
    "faded mosaic tiles. An arched doorway to the north leads "
    "deeper into the shrine. A stone tablet mounted on the west "
    "wall bears a lengthy inscription, still mostly legible "
    "despite the passage of time.");

  add_item(({"tablet","stone tablet","inscription","writing"}),
    "A flat slab of polished grey stone mounted on the west "
    "wall. Lines of text have been carefully chiseled into its "
    "surface. You could read it for the full text.");

  add_item(({"mosaic","tiles","walls","mosaics"}),
    "Faded mosaic tiles depict scenes of robed figures tending "
    "an eternal flame. Many tiles have cracked or fallen away, "
    "leaving gaps in the narrative.");

  add_item(({"doorway","arch","arched doorway"}),
    "A graceful stone arch leads north into deeper chambers. "
    "Faint warmth radiates from beyond.");

  // The @read_tablet syntax calls our read_tablet() function
  add_read(({"tablet","stone tablet","inscription"}),
    "@read_tablet");

  add_search_item(({"tiles","mosaic","walls"}),
    "Behind a loose tile you find a small clay vial, long since "
    "empty. It smells faintly of incense.");

  add_exit(SOLUTIONS + "ch13_rooms/ex03_readable", "north");
  return;
}

// Callback for add_read(). Returns different text depending
// on whether the player uses a screenreader.
string read_tablet()
{
  if (TP && TP->query_property("SCREENREAD"))
    return
      "Inscription on the Stone Tablet:\n"
      "Traveler, heed well these words.\n"
      "Beyond this threshold lies the Shrine of the Eternal Flame.\n"
      "Only those who carry light within may pass unharmed.\n"
      "Leave your weapons sheathed and your heart open.\n"
      "The Flame sees all, and judges all.\n";
  return
    "+==========================================+\n"
    "|                                          |\n"
    "|   Traveler, heed well these words.       |\n"
    "|                                          |\n"
    "|   Beyond this threshold lies the         |\n"
    "|   Shrine of the Eternal Flame.           |\n"
    "|                                          |\n"
    "|   Only those who carry light within      |\n"
    "|   may pass unharmed. Leave your          |\n"
    "|   weapons sheathed and your heart open.  |\n"
    "|                                          |\n"
    "|   The Flame sees all, and judges all.    |\n"
    "|                                          |\n"
    "+==========================================+\n";
}
