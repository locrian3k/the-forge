#pragma strong_types
#include "../defs.h"

//
// Exercise 10.3: Multiple Inheritance, Parent 2 (Trackable)
// Provides location tracking. Any object that inherits this gains
// the ability to store and return a location string.
//

string location;

void create()
{
  location = "unknown";
  return;
}

//
// query_location - Returns the current location.
//
string query_location() { return location; }

//
// set_location - Updates the location string.
//
void set_location(string s)
{
  location = s;
  return;
}
