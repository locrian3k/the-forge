/*
  ex01_basic_monster.c
  Exercise 17.1 — Basic Monster
  Create a simple monster using /obj/monster with combat stats,
  idle chat messages, and an extra_look() function.
*/

#pragma strong_types
#include "defs.h"

inherit "obj/monster";

void create()
{
  ::create();

  // TODO: Set the monster's identity
  //       - set_name() with its name (lowercase)
  //       - set_alias() with an array of aliases
  //       - set_race() with a race string (e.g. "goblin", "orc")

  // TODO: Set descriptions visible to players
  //       - set_short() with a brief description
  //       - set_long() with a detailed appearance (2+ sentences)

  // TODO: Set combat properties
  //       - set_level() to set the monster's difficulty (e.g. 5)
  //       - set_al() for alignment (negative = evil, positive = good)
  //       - set_aggressive(1) to make it attack on sight (or 0 for passive)

  // TODO: Load idle chat messages using load_chat()
  //       load_chat(chance, array_of_strings)
  //       - chance: percentage chance per heartbeat (e.g. 10)
  //       - array: ({}) of strings, each ending with \n
  //       These messages appear when the monster is idle (not fighting).

  return;
}

// extra_look() is appended to the room description when players
// look and this monster is present. Return a string ending with \n.
string extra_look()
{
  // TODO: Return a one-line description of the monster's presence
  //       in the room, e.g. "A goblin is here, watching you.\n"

  return "";
}
