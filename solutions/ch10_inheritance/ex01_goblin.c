#pragma strong_types
#include "defs.h"

//
// Exercise 10.1: Basic Inheritance, Child Class
// Goblin inherits base_creature and customizes the creature name.
// Demonstrates ::create(), inherited functions, and child-specific additions.
//

inherit __DIR__ + "ex01_base_creature";

void create()
{
  // Call the parent's create first to initialize creature_name
  ::create();

  // Now customize: change the default "creature" to "goblin"
  set_creature_name("goblin");
  return;
}

//
// query_battle_cry - Goblin-specific function not in the parent.
// Only goblin objects have a battle cry.
//
string query_battle_cry() { return "Grak! Smash!"; }

//
// query_description - Builds a description using the inherited
// query_creature_name() from the parent class. This demonstrates
// that inherited functions are available as if they were local.
//
string query_description()
{
  return "A fierce " + query_creature_name() +
    " snarls and brandishes a rusty blade.";
}
