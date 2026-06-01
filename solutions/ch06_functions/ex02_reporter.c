#pragma strong_types
#include "defs.h"

//
// Exercise 6.2: Cross-Object Calls, Reporter
// Loads the scoreboard object and calls its functions to demonstrate
// cross-object communication. Stores the result for verification.
//

// Path to the scoreboard object, adjust to match your file location
#define SCOREBOARD (SOLUTIONS + "ch06_functions/ex02_scoreboard")

// Stores the result of our cross-object query
int result;

void create()
{
  object scoreboard;

  // Load the scoreboard object (find it if already loaded, else load it)
  scoreboard = find_object(SCOREBOARD);
  if (!scoreboard)
    scoreboard = load_object(SCOREBOARD);

  // Register a test kill via cross-object call
  scoreboard->add_kill("test");

  // Query the kill count back and store it
  result = (int)scoreboard->query_kills("test");
  return;
}

//
// query_result - Returns the stored result from the cross-object call.
// The validator uses this to confirm the communication worked.
//
int query_result()
{
  return result;
}
