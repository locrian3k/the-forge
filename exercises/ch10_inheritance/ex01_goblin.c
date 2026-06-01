/*
  ex01_goblin.c
  Exercise 10.1 — Basic Inheritance, Child Class
  Goblin inherits base_creature and customizes the creature name.
  Demonstrates ::create(), inherited functions, and child-specific additions.
*/
#pragma strong_types
#include "defs.h"

// TODO: Inherit the base creature file
//   inherit __DIR__ + "ex01_base_creature";

void create()
{
  // TODO: Call the parent's create first to initialize creature_name
  //   ::create();

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
//   Example: "A fierce " + query_creature_name() +
//     " snarls and brandishes a rusty blade."
