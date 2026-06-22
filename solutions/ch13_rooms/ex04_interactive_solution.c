#pragma strong_types
#include "../defs.h"
inherit "room/room";

// Exercise 13.4 - Interactive Room
// A room with a custom "dig" command that clones a hidden
// treasure into the player's inventory.

void create()
{
  ::create();
  set_light(1);
  set_short("A Cave-In");

  set_long(
    "The tunnel ends abruptly here in a pile of loose rubble "
    "and broken timber. Chunks of rock and earth are heaped "
    "against the far wall where the ceiling collapsed long ago. "
    "Something glints faintly in the debris. A passage leads "
    "back to the south.");

  add_item(({"rubble","rocks","debris","pile"}),
    "A heap of broken stone, splintered timber, and packed "
    "earth. It looks like the ceiling gave way some time ago. "
    "You might be able to dig through some of it.");

  add_item(({"timber","wood","beams"}),
    "Splintered support beams jutting from the rubble at odd "
    "angles. Whatever held this tunnel up failed spectacularly.");

  add_item(({"glint","something","shine"}),
    "Something catches the light from within the rubble. You "
    "would need to dig to reach it.");

  add_search_item(({"rubble","debris","rocks"}),
    "You push some loose rocks aside and spot a metallic glint "
    "deeper in the pile. You might need to dig to get to it.");

  add_exit(SOLUTIONS + "ch13_rooms/ex04_interactive", "south");
  return;
}

void init()
{
  ::init();
  add_action("do_dig", "dig");
  return;
}

// Handler for the "dig" command. Clones a hidden amulet into
// the player's inventory if they dig through the rubble.
int do_dig(string str)
{
  object item;

  // Only respond to rubble-related arguments
  if (!str)
    return 0;
  if (member(({"rubble","rocks","debris","pile"}), str) == -1)
    return 0;

  // Prevent duplicates, check player and room
  if (present("amulet", TP) || present("amulet", TO))
  {
    write(
      "You dig through the rubble again but find nothing "
      "else of interest.\n");
    return 1;
  }

  // Clone the hidden item and move it to the player
  item = clone_object(SOLUTIONS + "ch13_rooms/ex04_hidden_item");
  if (item)
  {
    move_object(item, TP);
    write(
      "You heave aside chunks of rock and dig through the "
      "loose earth. Your fingers close around something cold "
      "and metallic -- a tarnished bronze amulet! You brush "
      "it off and pocket it.\n");
    say(sprintf(
      "%s digs through the rubble and pulls out something "
      "shiny.\n",
      capitalize((string)TP->query_name())));
    return 1;
  }

  return 0;
}
