/*
  ex01_declare_types.c
  YourName YYMMDD
  Exercise 2.1 — Type Declaration Drill
  Create a treasure object that declares one global variable of each
  basic LPC type and provides query functions to read them.
*/
#pragma strong_types
#include "../defs.h"

inherit "obj/treasure";

// TODO: Declare six global variables, one of each basic type:
//   int, status, string, float, object, mixed
//   Give each a descriptive name.

void create()
{
  ::create();

  // TODO: Set the object identity using set_name(), set_alias(),
  //   set_short(), set_long(), set_value(), and set_weight().

  // TODO: Assign a meaningful value to each global variable.
  //   Use a value appropriate for each type.

  return;
}

// TODO: Write six one-line query functions, one per variable.
//   Each returns the matching type. Use the single-line format:
//   type query_varname() { return varname; }
