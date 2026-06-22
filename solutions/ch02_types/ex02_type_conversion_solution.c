#pragma strong_types
#include "../defs.h"

// Exercise 2.2, Type Conversion
// Utility functions demonstrating explicit type conversion in LPC.

inherit "obj/treasure";

void create()
{
  ::create();

  set_name("type converter");
  set_alias(({"converter", "type converter"}));
  set_short("a type converter");
  set_long(
    "A strange prism that refracts not light, but meaning itself. "
    "Feed it a number and it gives you words. Feed it words and "
    "it gives you a number."
  );
  set_value(5);
  set_weight(1);

  return;
}

// Convert an integer to its string representation.
// Uses explicit (string) cast.
string int_to_string(int n)
{
  return (string)n;
}

// Convert a string to an integer.
// Non-numeric strings return 0 by default.
int string_to_int(string s)
{
  return (int)s;
}

// Return 1 if n is positive, 0 otherwise.
// Demonstrates producing a clean status from an int.
status status_check(int n)
{
  if (n > 0)
    return 1;
  return 0;
}

// Identify the type of an arbitrary value using type-check efuns.
string describe_type(mixed val)
{
  if (intp(val))
    return "int";
  if (stringp(val))
    return "string";
  if (floatp(val))
    return "float";
  if (objectp(val))
    return "object";
  return "unknown";
}
