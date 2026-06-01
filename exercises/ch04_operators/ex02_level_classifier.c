/*
  ex02_level_classifier.c
  Exercise 4.2 — Level Classifier
  Uses comparison operators and if/else to classify player levels
  into title strings.
*/
#pragma strong_types
#include "defs.h"

inherit "obj/treasure";

void create()
{
  ::create();

  // TODO: Set the object identity:
  //   name  -> "level classifier"
  //   alias -> ({"classifier", "level classifier"})
  //   short -> "a level classifier"
  //   long  -> a description of your choice
  //   value -> 10
  //   weight -> 1

  return;
}

// TODO: Implement string classify_level(int level)
//   Map level ranges to title strings using if/else:
//
//   Level range     Return value
//   -----------     ------------
//   100 or more     "legend"
//   61 to 99        "hero"
//   31 to 60        "veteran"
//   11 to 30        "adventurer"
//   1 to 10         "newbie"
//   0 or below      "unknown"
//
//   Hint: Check from highest to lowest so each branch is clean.
