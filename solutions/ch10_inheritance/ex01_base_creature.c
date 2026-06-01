#pragma strong_types
#include "defs.h"

//
// Exercise 10.1: Basic Inheritance, Base Class
// A simple creature base class that provides name management.
// Children inherit this to get creature_name for free.
//

string creature_name;

void create()
{
  creature_name = "creature";
  return;
}

//
// query_creature_name - Returns the creature's name.
// Children inherit this getter without needing to rewrite it.
//
string query_creature_name() { return creature_name; }

//
// set_creature_name - Sets the creature's name.
// Children call this in their create() to customize the name.
//
void set_creature_name(string s)
{
  creature_name = s;
  return;
}
