/*
  ex02_nosave_varargs.c
  Exercise 8.2 — Nosave and Varargs
  Demonstrate nosave (transient data), varargs (optional arguments),
  and nomask (override protection) modifiers.
*/
#pragma strong_types
#include "../defs.h"

// TODO: Declare a nosave int variable called visit_count.
//   Syntax: nosave type varname;
//   nosave means it resets to 0 on reload (transient runtime data).

// TODO: Declare a regular string variable called location.
//   This one persists normally through save/restore (for contrast).

void create()
{
  // TODO: Initialize visit_count to 0
  // TODO: Initialize location to "The Forge Training Grounds"

  return;
}

//
// do_announce - Allows callers to provide 1, 2, or 3 arguments.
//
// TODO: Add the correct modifier so this function accepts
//       fewer arguments than declared.
//
// Parameters:
//   string who    - required: who is arriving
//   string msg    - optional: defaults to "has arrived"
//   int volume    - optional: defaults to 1
//
// Returns: who + " " + msg + ". [volume: " + volume + "]"
//
// Example calls:
//   do_announce("Gandalf")              -> "Gandalf has arrived. [volume: 1]"
//   do_announce("Gandalf", "returns")   -> "Gandalf returns. [volume: 1]"
//   do_announce("Gandalf", "shouts", 3) -> "Gandalf shouts. [volume: 3]"
//

//
// do_visit - Increments the transient visit counter.
//
// TODO: Implement. Increment visit_count and return the new value.
//

//
// query_visit_count - Returns current visit count.
//
// TODO: Implement as a simple one-line query function.
//

//
// query_location - Returns the saved location string.
//
// TODO: Implement as a simple one-line query function.
//

//
// query_id - Returns a fixed identifier that children cannot override.
//
// TODO: Add the correct modifier so no child can override this,
//       then return "forge_visitor".
//
// Hint: Which modifier prevents children from overriding?
//
