/*
  ex01_base_creature.c
  Exercise 10.1 — Basic Inheritance, Base Class
  A simple creature base class that provides name management.
  Children inherit this to get creature_name for free.
*/
#pragma strong_types
#include "defs.h"

// TODO: Declare a global string variable: creature_name

void create()
{
  // TODO: Set creature_name to a default value: "creature"

  return;
}

// TODO: Implement query_creature_name()
//   Returns creature_name.
//   Children inherit this getter without needing to rewrite it.

// TODO: Implement set_creature_name(string s)
//   Sets creature_name to s.
//   Children call this in their create() to customize the name.
