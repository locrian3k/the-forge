#pragma strong_types
#include "defs.h"

//
// Exercise 6.1: Function Basics
// Demonstrates void, int, and string return types, plus calling
// one function from another (composition).
//

void create()
{
  // Nothing to initialize for this exercise.
  return;
}

//
// do_greet - A void function that writes a greeting to the player.
// Void functions must end with an explicit return; per 3K codestyle.
//
void do_greet()
{
  write("Hello, adventurer! Welcome to the Forge.\n");
  return;
}

//
// do_add - Returns the sum of two integers.
//
int do_add(int a, int b)
{
  return a + b;
}

//
// query_title - Returns a title string.
//
string query_title()
{
  return "Apprentice of the Forge";
}

//
// do_combo - Demonstrates calling other functions within a function.
// Computes the sum via do_add() and fetches the title via query_title(),
// then combines them into a single descriptive string.
//
string do_combo(int a, int b)
{
  int sum;
  string title;

  sum = do_add(a, b);
  title = query_title();
  return title + " reports: " + a + " + " + b + " = " + sum;
}
