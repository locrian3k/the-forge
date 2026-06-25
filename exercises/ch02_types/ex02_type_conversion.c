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

// TODO: Check if a die has a valid number of sides (greater than 0).
//   Return 1 if valid, 0 otherwise.
//   This one needs multiple lines, so use Allman brackets.
//
// status is_valid_die(int n)

// TODO: Identify the type of any die property.
//   Check intp(), stringp(), floatp(), objectp() in order.
//   Return "int", "string", "float", "object", or "unknown".
//   This one needs multiple lines, so use Allman brackets.
//
// string identify_property(mixed val)
