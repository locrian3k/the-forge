#pragma strong_types
#include "../defs.h"

//
// Exercise 6.2: Cross-Object Calls, Scoreboard
// Maintains a mapping of player names to kill counts.
// Other objects call add_kill() and query_kills() on this object.
//

// Global mapping: player_name -> kill_count
mapping kills;

void create()
{
  kills = ([]);
  return;
}

//
// add_kill - Increments the kill count for a given name.
// Creates the entry with a count of 1 if it does not exist.
//
void add_kill(string name)
{
  if (kills[name])
    kills[name] += 1;
  else
    kills[name] = 1;
  return;
}

//
// query_kills - Returns the kill count for a name, or 0 if not found.
//
int query_kills(string name)
{
  return kills[name];
}
