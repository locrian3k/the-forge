/*
  ex04_interactive.c
  Exercise 13.4 — Interactive Room
  A room with a custom command (e.g. "dig") that clones a hidden
  treasure into the player's inventory.
*/
#pragma strong_types
#include "defs.h"
inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  // TODO: Set a short description

  // TODO: Set a long description that hints at something hidden
  //   or interactable (e.g. rubble that can be dug through,
  //   a fountain that can be searched, etc.)

  // TODO: Add add_item() entries for examinable features
  //   that reinforce the interactive element

  // TODO: Optionally add a search_item that hints at the
  //   custom command

  // TODO: Add at least one exit

  return;
}

void init()
{
  ::init();

  // TODO: Register a custom command verb using add_action().
  //   Example: add_action("do_dig", "dig");
  //   This means when a player types "dig <anything>", the
  //   function do_dig(string str) is called.

  return;
}

// TODO: Implement the command handler function.
//   Return type: int (return 1 if handled, 0 if not)
//
// int do_dig(string str)
// {
//   object item;
//
//   // Return 0 if no argument or argument doesn't match
//   if (!str)
//     return 0;
//   if (member(({"rubble","rocks","debris","pile"}), str) == -1)
//     return 0;
//
//   // Check for duplicates: prevent farming unlimited copies
//   // Use present("item_name", TP) to check player inventory
//   // and present("item_name", TO) to check room
//   if (present("amulet", TP) || present("amulet", TO))
//   {
//     write("You dig again but find nothing else.\n");
//     return 1;
//   }
//
//   // Clone the treasure object and move it to the player
//   item = clone_object(EXERCISES + "ch13_rooms/ex04_hidden_item");
//   if (item)
//   {
//     move_object(item, TP);
//     write("You dig and find something!\n");
//     say(capitalize((string)TP->query_name()) +
//       " digs through the rubble.\n");
//     return 1;
//   }
//
//   return 0;
// }
