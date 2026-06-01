/*
  ex02_guard.c
  Exercise 10.2 — Override and Extend, Guard (Child)
  Inherits base_npc and overrides extra_look() and query_greeting()
  using :: to extend the parent's behavior rather than replace it.
*/
#pragma strong_types
#include "defs.h"

// TODO: Inherit the base NPC file (ex02_base_npc)
//   Use __DIR__ + "filename" to build the path.

// TODO: Declare a global string variable: post

void create()
{
  // TODO: Call the parent's create first

  // TODO: Set post to a location string, e.g. "the north gate"

  return;
}

// TODO: Implement extra_look() — OVERRIDE
//   Call ::extra_look() first to get the parent's description text.
//   Store it in a local variable.
//   Then return the parent text concatenated with guard-specific
//   details about armor, weapons, and the post location.

// TODO: Implement query_greeting() — OVERRIDE
//   Call ::query_greeting() first to get the parent's greeting.
//   Store it in a local variable.
//   Then return the parent greeting concatenated with guard dialogue.

// TODO: Implement query_post()
//   Guard-specific function not in the parent.
//   Returns the post string.
