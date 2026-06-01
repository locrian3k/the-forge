/*
  ex03_bitwise_flags.c
  Exercise 4.3 — Bitwise Flags
  A permission system using bitwise operators.
*/
#pragma strong_types
#include "defs.h"

inherit "obj/treasure";

// Permission bit constants
#define READ    1
#define WRITE   2
#define EXECUTE 4

void create()
{
  ::create();

  // TODO: Set the object identity:
  //   name  -> "flag register"
  //   alias -> ({"register", "flag register"})
  //   short -> "a flag register"
  //   long  -> a description of your choice
  //   value -> 20
  //   weight -> 1

  return;
}

// TODO: Implement int set_flag(int flags, int bit)
//   Turn ON a specific bit using bitwise OR.
//   Return: flags | bit

// TODO: Implement int clear_flag(int flags, int bit)
//   Turn OFF a specific bit using bitwise AND with complement.
//   Return: flags & ~bit

// TODO: Implement status has_flag(int flags, int bit)
//   Check whether a specific bit is set.
//   Return 1 if set, 0 if not.
//   Hint: (flags & bit) is nonzero if the bit is set.

// TODO: Implement string describe_flags(int flags)
//   Build a human-readable string of active permission flags.
//   Check each flag (READ, WRITE, EXECUTE) and build a string
//   with space-separated names, e.g. "READ WRITE" or "READ EXECUTE".
//   Return "none" if no flags are set.
//
//   Hint: Start with result = "", check each flag, append the name
//   with a space separator if result is not empty.
