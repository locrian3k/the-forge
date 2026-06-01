#pragma strong_types
#include "defs.h"

//
// Exercise 8.2: Nosave and Varargs
// Demonstrates nosave (transient data), varargs (optional arguments),
// and nomask (override protection) modifiers.
//

// nosave: visit_count resets to 0 on reload, it is transient runtime
// data that should not persist across object reloads or saves.
nosave int visit_count;

// Regular global: location persists normally through save/restore.
string location;

void create()
{
  visit_count = 0;
  location = "The Forge Training Grounds";
  return;
}

//
// do_announce - VARARGS: Allows callers to provide 1, 2, or 3 args.
// This is useful for announcement functions where most calls only
// need to specify who is arriving, with message and volume being
// optional refinements.
//
// Usage:
//   do_announce("Gandalf")              -> "Gandalf has arrived. [volume: 1]"
//   do_announce("Gandalf", "returns")   -> "Gandalf returns. [volume: 1]"
//   do_announce("Gandalf", "shouts", 3) -> "Gandalf shouts. [volume: 3]"
//
varargs string do_announce(string who, string msg, int volume)
{
  // Default msg if not provided (will be 0/null)
  if (!msg)
    msg = "has arrived";

  // Default volume if not provided (will be 0)
  if (!volume)
    volume = 1;

  return who + " " + msg + ". [volume: " + volume + "]";
}

//
// do_visit - Increments the transient visit counter.
// Returns the new count after incrementing.
//
int do_visit()
{
  visit_count++;
  return visit_count;
}

//
// query_visit_count - Returns current visit count.
//
int query_visit_count() { return visit_count; }

//
// query_location - Returns the saved location string.
//
string query_location() { return location; }

//
// query_id - NOMASK: This function cannot be overridden by any child
// object. We use nomask to guarantee that every instance of this object
// (and any child) always returns the same reliable identifier. This is
// critical for systems that depend on a consistent ID for lookups.
//
nomask string query_id() { return "forge_visitor"; }
