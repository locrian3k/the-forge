/*
  ex02_base_npc.c
  Exercise 10.2 — Override and Extend, Parent NPC
  A base NPC class with look and greeting functions that children
  can override and extend using the :: operator.
*/
#pragma strong_types
#include "../defs.h"

// TODO: Declare a global string variable: npc_type

void create()
{
  // TODO: Set npc_type to "generic"

  return;
}

// TODO: Implement extra_look()
//   Returns a base description for this NPC.
//   Example: "This is a generic NPC."
//   Children should call ::extra_look() to include this text
//   when they override with their own additions.

// TODO: Implement query_greeting()
//   Returns a base greeting string.
//   Example: "Hello there."
//   Children can extend this with ::query_greeting() to preserve
//   the base greeting while adding their own dialogue.

// TODO: Implement query_npc_type()
//   Returns the npc_type string.
