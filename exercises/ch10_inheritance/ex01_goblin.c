/*
  ex01_goblin.c
  Exercise 10.1 — Basic Inheritance, Child Class
  Goblin inherits base_creature and customizes the creature name.
  Demonstrates ::create(), inherited functions, and child-specific additions.
*/
#pragma strong_types
#include "defs.h"

// TODO: Inherit the base creature file (ex01_base_creature)
//   Use __DIR__ + "filename" to build the path.

void create()
{
  // TODO: Call the parent's create first to initialize creature_name

  // TODO: Customize: change the default "creature" to "goblin"
  //   Use set_creature_name() inherited from the parent.

  return;
}

// TODO: Implement query_battle_cry()
//   Returns a goblin war cry string, e.g. "Grak! Smash!"
//   This is a goblin-specific function not in the parent.

// TODO: Implement query_description()
//   Build a description string that uses query_creature_name()
//   inherited from the parent class.
