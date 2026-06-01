/*
  ex02_type_conversion.c
  Exercise 2.2 — Type Conversion
  Utility functions demonstrating explicit type conversion in LPC.
*/
#pragma strong_types
#include "defs.h"

inherit "obj/treasure";

void create()
{
  ::create();

  // TODO: Set the object identity:
  //   name  -> "type converter"
  //   alias -> ({"converter", "type converter"})
  //   short -> "a type converter"
  //   long  -> a description of your choice
  //   value -> 5
  //   weight -> 1

  return;
}

// TODO: Convert an integer to its string representation.
//   Use an explicit (string) cast on n.
//   Example: int_to_string(42) returns "42"
//
// string int_to_string(int n)

// TODO: Convert a string to an integer.
//   Use an explicit (int) cast on s.
//   Non-numeric strings return 0 by default.
//   Example: string_to_int("7") returns 7
//
// int string_to_int(string s)

// TODO: Return 1 if n is positive, 0 otherwise.
//   Demonstrates producing a clean status from an int.
//   Example: status_check(5) returns 1, status_check(-3) returns 0
//
// status status_check(int n)

// TODO: Identify the type of an arbitrary value using type-check efuns.
//   Check intp(), stringp(), floatp(), objectp() in order.
//   Return "int", "string", "float", "object", or "unknown".
//
// string describe_type(mixed val)
