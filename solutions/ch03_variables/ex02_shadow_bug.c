#pragma strong_types
#include "../defs.h"

// Exercise 3.2, Shadow Bug Fix (corrected)
//
// Fix: Removed the local `int counter;` declaration from
// do_increment() that was shadowing the global variable.
// Now counter++ modifies the global as intended.

inherit "obj/treasure";

int counter;

void create()
{
  ::create();

  set_name("shadow counter");
  set_alias(({"counter", "shadow counter"}));
  set_short("a shadow counter");
  set_long("A counting device, no longer plagued by shadows.");
  set_value(1);
  set_weight(1);

  counter = 0;

  return;
}

// Fixed: no local declaration, so counter refers to the global
void do_increment()
{
  counter++;

  return;
}

int query_counter() { return counter; }
