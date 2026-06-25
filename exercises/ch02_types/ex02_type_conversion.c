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

// TODO: Convert number of sides (int) to a display label (string).
//   Use an explicit (string) cast on n.
//
// string sides_to_label(int n)

// TODO: Convert a label string back to a number of sides (int).
//   Use an explicit (int) cast on s.
//   Non-numeric strings return 0 by default.
//
// int label_to_sides(string s)

// TODO: Check if a die has a valid number of sides (greater than 0).
//   Return 1 if valid, 0 otherwise.
//
// status is_valid_die(int n)

// TODO: Identify the type of any die property.
//   Check intp(), stringp(), floatp(), objectp() in order.
//   Return "int", "string", "float", "object", or "unknown".
//
// string identify_property(mixed val)
