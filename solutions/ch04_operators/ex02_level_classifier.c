#pragma strong_types
#include "defs.h"

// Exercise 4.2, Level Classifier
// Uses comparison operators and if/else to classify player levels.

inherit "obj/treasure";

void create()
{
  ::create();

  set_name("level classifier");
  set_alias(({"classifier", "level classifier"}));
  set_short("a level classifier");
  set_long(
    "A thin crystal lens mounted in a bronze frame. Peer through "
    "it at an adventurer and it reveals their standing in the "
    "world: newbie, adventurer, veteran, hero, or legend."
  );
  set_value(10);
  set_weight(1);

  return;
}

// Classify a player level into a title string.
// Checks from highest to lowest so each branch is clean.
string classify_level(int level)
{
  if (level >= 100)
    return "legend";
  else if (level >= 61)
    return "hero";
  else if (level >= 31)
    return "veteran";
  else if (level >= 11)
    return "adventurer";
  else if (level >= 1)
    return "newbie";
  return "unknown";
}
