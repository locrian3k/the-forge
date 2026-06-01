/*
  ex02_reporter.c
  Exercise 6.2 — Cross-Object Calls (Reporter)
  Loads the scoreboard object and calls its functions to demonstrate
  cross-object communication. Stores the result for verification.
*/
#pragma strong_types
#include "../defs.h"

// TODO: Define a path to the scoreboard object.
//   Adjust this to match where your scoreboard file lives.
//   Use EXERCISES + "ch06_functions/ex02_scoreboard" as the path.

// TODO: Declare a global int variable named "result"

void create()
{
  // TODO: Declare a local object variable named "scoreboard"

  // TODO: Load the scoreboard object:
  //   1. Try find_object(SCOREBOARD) first (returns 0 if not loaded)
  //   2. If not found, use load_object(SCOREBOARD) to load it

  // TODO: Register a test kill via cross-object call.
  //   Use the -> operator to call add_kill() on the scoreboard.

  // TODO: Query the kill count back and store it in result.
  //   Use the -> operator to call query_kills() on the scoreboard.
  //   Cast the result to (int) since cross-object calls return mixed.

  return;
}

// TODO: Implement int query_result()
//   Return the stored result from the cross-object call.
//   The validator uses this to confirm the communication worked.
