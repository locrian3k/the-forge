#pragma strong_types
#include "../defs.h"

// Exercise 4.3, Bitwise Flags
// A permission system using bitwise operators.

inherit "obj/treasure";

// Permission bit constants
#define READ    1
#define WRITE   2
#define EXECUTE 4

void create()
{
  ::create();

  set_name("flag register");
  set_alias(({"register", "flag register"}));
  set_short("a flag register");
  set_long(
    "A flat metal plate with three toggle switches labeled R, W, "
    "and X. Each switch can be flipped independently, and the "
    "plate displays the combined state as a single number."
  );
  set_value(20);
  set_weight(1);

  return;
}

// Turn on a specific bit using bitwise OR
int set_flag(int flags, int bit)
{
  return flags | bit;
}

// Turn off a specific bit using bitwise AND with complement
int clear_flag(int flags, int bit)
{
  return flags & ~bit;
}

// Check whether a specific bit is set.
// The & result is nonzero if set; compare to produce a clean status.
status has_flag(int flags, int bit)
{
  if (flags & bit)
    return 1;
  return 0;
}

// Build a human-readable string of active permission flags.
string describe_flags(int flags)
{
  string result;

  result = "";

  if (flags & READ)
    result += "READ";
  if (flags & WRITE)
  {
    if (result != "")
      result += " ";
    result += "WRITE";
  }
  if (flags & EXECUTE)
  {
    if (result != "")
      result += " ";
    result += "EXECUTE";
  }

  if (result == "")
    return "none";
  return result;
}
