/*
  ex02_guard.c
  Exercise 10.2 — Override and Extend, Guard (Child)
  Inherits base_npc and overrides extra_look() and query_greeting()
  using :: to extend the parent's behavior rather than replace it.
*/
#pragma strong_types
#include "defs.h"

// TODO: Inherit the base NPC file
//   inherit __DIR__ + "ex02_base_npc";

// TODO: Declare a global string variable: post

void create()
{
  // TODO: Call the parent's create first
  //   ::create();

  // TODO: Set post to a location string, e.g. "the north gate"

  return;
}

// TODO: Implement extra_look() — OVERRIDE
//   Call ::extra_look() first to get the parent's description text.
//   Store it in a local variable.
//   Then return the parent text concatenated with guard-specific
//   details about armor, weapons, and the post location.
//
//   Example structure:
//     string base_text;
//     base_text = ::extra_look();
//     return base_text +
//       "\nThis guard wears polished plate armor..." +
//       "\nThey are stationed at " + post + ".";

// TODO: Implement query_greeting() — OVERRIDE
//   Call ::query_greeting() first to get the parent's greeting.
//   Store it in a local variable.
//   Then return the parent greeting concatenated with guard dialogue.
//
//   Example: base_greeting + " Move along, citizen. Nothing to see here."

// TODO: Implement query_post()
//   Guard-specific function not in the parent.
//   Returns the post string.
