#pragma strong_types
#include "../defs.h"

// Exercise 2.2, Type Conversion
// A die reader that interprets and displays die properties.

inherit "obj/treasure";

void create()
{
  ::create();

  set_name("die reader");
  set_alias(({"reader", "die reader"}));
  set_short("a die reader");
  set_long(
    "A small magnifying lens etched with runes. Hold it over a "
    "die to read its properties - it can translate numbers to "
    "labels, labels back to numbers, and identify any property."
  );
  set_value(5);
  set_weight(1);

  return;
}

// Convert number of sides to a display label.
string sides_to_label(int n) { return (string)n; }

// Convert a label string back to a number of sides.
int label_to_sides(string s) { return (int)s; }

// Check if a die has a valid number of sides (greater than 0).
status is_valid_die(int n)
{
  if (n > 0)
    return 1;
  return 0;
}

// Identify the type of any die property.
string identify_property(mixed val)
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
