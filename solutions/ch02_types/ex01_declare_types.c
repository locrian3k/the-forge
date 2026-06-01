#pragma strong_types
#include "defs.h"

// Exercise 2.1, Type Declaration Drill
// Demonstrates every basic LPC type with query functions.

inherit "obj/treasure";

// Global variables, one of each basic type
int score;
status active;
string label;
float ratio;
object self;
mixed wildcard;

void create()
{
  ::create();

  // Identity
  set_name("type sampler");
  set_alias(({"sampler", "type sampler"}));
  set_short("a type sampler");
  set_long(
    "A crystalline cube with six faces, each glowing a different "
    "color. Each face represents one of the fundamental types of "
    "LPC: int, status, string, float, object, and mixed."
  );
  set_value(1);
  set_weight(1);

  // Assign initial values to each typed variable
  score = 42;
  active = 1;
  label = "Hello from The Forge";
  ratio = 3.14;
  self = this_object();
  wildcard = "I could be anything";

  return;
}

// Query functions, one per variable, matching its type

int query_score() { return score; }

status query_active() { return active; }

string query_label() { return label; }

float query_ratio() { return ratio; }

object query_self() { return self; }

mixed query_wildcard() { return wildcard; }
