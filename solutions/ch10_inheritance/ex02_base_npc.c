#pragma strong_types
#include "defs.h"

//
// Exercise 10.2: Override and Extend, Parent NPC
// A base NPC class with look and greeting functions that children
// can override and extend using the :: operator.
//

string npc_type;

void create()
{
  npc_type = "generic";
  return;
}

//
// extra_look - Returns a base description for this NPC.
// Children should call ::extra_look() to include this text
// when they override with their own additions.
//
string extra_look()
{
  return "This is a generic NPC.";
}

//
// query_greeting - Returns a base greeting.
// Children can extend this with ::query_greeting() to preserve
// the base greeting while adding their own dialogue.
//
string query_greeting()
{
  return "Hello there.";
}

//
// query_npc_type - Returns the NPC type string.
//
string query_npc_type() { return npc_type; }
