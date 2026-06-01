#pragma strong_types
#include "defs.h"

//
// Exercise 10.3: Multiple Inheritance, Parent 1 (Describable)
// Provides description management. Any object that inherits this
// gains the ability to store and return a description string.
//

string description;

void create()
{
  description = "An unremarkable object.";
  return;
}

//
// query_description - Returns the current description.
//
string query_description() { return description; }

//
// set_description - Updates the description string.
//
void set_description(string s)
{
  description = s;
  return;
}
