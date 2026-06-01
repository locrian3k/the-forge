#pragma strong_types
#include "defs.h"

//
// Exercise 10.2: Override and Extend, Guard (Child)
// Inherits base_npc and overrides extra_look() and query_greeting()
// using :: to extend the parent's behavior rather than replace it.
//

inherit __DIR__ + "ex02_base_npc";

string post;

void create()
{
  // Always call parent create first
  ::create();

  post = "the north gate";
  return;
}

//
// extra_look - OVERRIDE: Extends the parent's description by calling
// ::extra_look() first, then appending guard-specific details.
// The player sees the base NPC text plus the guard additions.
//
string extra_look()
{
  string base_text;

  // Get the parent's description
  base_text = ::extra_look();

  // Extend it with guard-specific details
  return base_text +
    "\nThis guard wears polished plate armor and carries a halberd." +
    "\nThey are stationed at " + post + ".";
}

//
// query_greeting - OVERRIDE: Extends the parent's greeting by calling
// ::query_greeting() first, then appending a guard-specific line.
//
string query_greeting()
{
  string base_greeting;

  base_greeting = ::query_greeting();

  return base_greeting +
    " Move along, citizen. Nothing to see here.";
}

//
// query_post - Guard-specific function, not in the parent.
// Returns the location this guard is assigned to.
//
string query_post() { return post; }
