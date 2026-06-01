/*
  ex01_declare_types.c
  Exercise 2.1 — Type Declaration Drill
  Create a treasure object that declares one global variable of each
  basic LPC type and provides query functions to read them.
*/
#pragma strong_types
#include "defs.h"

inherit "obj/treasure";

// TODO: Declare six global variables, one of each basic type:
//   int score;
//   status active;
//   string label;
//   float ratio;
//   object self;
//   mixed wildcard;

void create()
{
  ::create();

  // TODO: Set the object identity:
  //   name   -> "type sampler"
  //   alias  -> ({"sampler", "type sampler"})
  //   short  -> "a type sampler"
  //   long   -> a description of your choice
  //   value  -> 1
  //   weight -> 1

  // TODO: Assign a meaningful value to each global variable:
  //   score    = 42
  //   active   = 1
  //   label    = "Hello from The Forge"
  //   ratio    = 3.14
  //   self     = this_object()
  //   wildcard = "I could be anything"

  return;
}

// TODO: Write six one-line query functions, one per variable.
//   Each returns the matching type. Use the single-line format:
//
//   int query_score() { return score; }
//   status query_active() { return active; }
//   string query_label() { return label; }
//   float query_ratio() { return ratio; }
//   object query_self() { return self; }
//   mixed query_wildcard() { return wildcard; }
