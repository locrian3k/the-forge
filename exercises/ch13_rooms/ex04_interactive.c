/*
  ex04_interactive.c
  Exercise 13.4 — Interactive Room
  A room with a custom command (e.g. "dig") that clones a hidden
  treasure into the player's inventory.
*/
#pragma strong_types
#include "../defs.h"
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
  //   Syntax: add_action("handler_function", "verb");
  //   This means when a player types "verb <anything>", the
  //   handler function is called with the argument string.

  return;
}

// TODO: Implement the command handler function.
//   Return type: int (return 1 if handled, 0 if not)
//
//   Steps:
//   1. Check if str is missing or doesn't match valid keywords — return 0
//   2. Check for duplicates using present() in TP and TO — prevent farming
//   3. Clone the hidden item object and move it to the player
//   4. Print messages to the player with write() and the room with say()
//   5. Return 1 on success
//
//   Useful efuns: present(), clone_object(), move_object(),
//   write(), say(), capitalize()
