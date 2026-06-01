#pragma strong_types
#include "defs.h"

// Exercise 3.1, Scope Matters
// Demonstrates the difference between global and local variable scope.

inherit "obj/treasure";

// Global variable, persists across all function calls
int counter;

void create()
{
  ::create();

  set_name("scope stone");
  set_alias(({"stone", "scope stone"}));
  set_short("a scope stone");
  set_long(
    "A polished stone with two faces. One face has a number that "
    "grows each time you touch it. The other face always shows "
    "the same number, no matter what."
  );
  set_value(1);
  set_weight(1);

  // Initialize the global counter
  counter = 0;

  return;
}

// Each call increments the global counter but always returns the
// same local value. This shows that locals are temporary while
// globals persist.
int do_increment()
{
  // Local variable, freshly created every call
  int local_val;

  local_val = 100;

  // Modify the global
  counter++;

  // Return the local (always 100)
  return local_val;
}

// Query the persistent global counter
int query_counter() { return counter; }
