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

// Take a roll result and return a display message.
string describe_roll(int n) { return "You rolled: " + (string)n; }

// Take the number of sides and return the odds of rolling any one side.
float sides_to_odds(int n) { return 1.0 / (float)n; }

// Take the luck bonus and return a formatted string.
string luck_report(float bonus) { return "Luck modifier: " + (string)bonus; }
