/*
  ex02_type_conversion.c
  YourName YYMMDD
  Exercise 2.2 — Type Conversion
  A die reader that interprets and displays die properties.
*/
#pragma strong_types
#include "../defs.h"

inherit "obj/treasure";

void create()
{
  ::create();

  // TODO: Set the object identity:
  //   name  -> "die reader"
  //   alias, short, long, value, weight of your choice

  return;
}

// EXAMPLE: Here is a complete function that takes a float and
// returns it as a string. Notice how the (string) cast converts
// the float value into text:
//
// string float_to_label(float f) { return (string)f; }
//
// If someone called float_to_label(1.25), it would return "1.25".
// Use this pattern for the functions below.

// TODO: Convert number of sides (int) to a display label (string).
//   Use an explicit (string) cast on n.
//   If the body is just a single return, use the one-line format.
//
// string sides_to_label(int n)

// TODO: Convert a label string back to a number of sides (int).
//   Use an explicit (int) cast on s.
//   Non-numeric strings return 0 by default.
//   If the body is just a single return, use the one-line format.
//
// int label_to_sides(string s)

// TODO: Take a roll result (int) and return a display message (string).
//   Concatenate a string with the cast int.
//   Example: describe_roll(6) returns "You rolled: 6"
//
// string describe_roll(int n)

// TODO: Take the number of sides (int) and return the odds of rolling
//   any one side as a float. Cast n to float first.
//   Example: sides_to_odds(6) returns roughly 0.166667
//
// float sides_to_odds(int n)

// TODO: Take the luck bonus (float) and return a formatted string.
//   Concatenate a string with the cast float.
//   Example: luck_report(1.25) returns "Luck modifier: 1.25"
//
// string luck_report(float bonus)
