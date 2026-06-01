/*
  ex03_command_hook.c
  Exercise 19.3 — Command Hook
  Create a forge room where players can use a custom command
  to craft an item. Uses add_action() in init() to register
  a command and a handler function to process it.
*/

#pragma strong_types
#include "defs.h"

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  // TODO: Set short and long descriptions for a forge/workshop room.

  // TODO: Add examinable items (forge, anvil, tools, etc.)

  // TODO: Add at least one exit.

  return;
}

void init()
{
  ::init();

  // TODO: Register a custom command for players in this room.
  //       add_action("do_forge", "forge");
  //       This means when a player types "forge <arg>", the
  //       function do_forge(arg) will be called.

  return;
}

// Handle the custom "forge" command.
// Usage: forge sword
// Requires an "iron bar" in the player's inventory.
// Return 1 on success, 0 on failure (with notify_fail message).
int do_forge(string arg)
{
  object bar, sword;

  // TODO: Check for valid syntax. If arg is missing or wrong:
  //       notify_fail("Usage: forge sword\n");
  //       return 0;

  // TODO: Check if the player has the required material.
  //       bar = present("iron bar", TP);
  //       If not found:
  //       notify_fail("You need an iron bar to forge a sword.\n");
  //       return 0;

  // TODO: Consume the material: destruct(bar);

  // TODO: Create the result and give it to the player:
  //       sword = clone_object("/obj/weapon");
  //       move_object(sword, TP);

  // TODO: Print a success message to the player with write().

  // TODO: Print a room message (excluding the player) with
  //       tell_room(TO, message, ({TP}));
  //       The ({TP}) array excludes the player from the message.

  return 1;
}
