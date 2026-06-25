#pragma strong_types
#include "../defs.h"

// Exercise 2.1, Type Declaration Drill
// A six-sided die where each side represents a basic LPC type.

inherit "obj/treasure";

// Global variables, one of each basic type (one per side of the die)
int sides;
status is_loaded;
string inscription;
float weight_oz;
object owner;
mixed enchantment;

void create()
{
  ::create();

  // Identity
  set_name("type die");
  set_alias(({"die", "type die", "dice"}));
  set_short("a six-sided type die");
  set_long(
    "A polished six-sided die carved from dark stone. Each face "
    "is etched with a glowing rune representing one of the "
    "fundamental types of LPC: int, status, string, float, "
    "object, and mixed."
  );
  set_value(5);
  set_weight(1);

  // Assign initial values to each typed variable
  sides = 6;
  is_loaded = 0;
  inscription = "Roll for initiative";
  weight_oz = 1.25;
  owner = TO;
  enchantment = "lucky";

  return;
}

// Query functions, one per variable, matching its type

int query_sides() { return sides; }

status query_is_loaded() { return is_loaded; }

string query_inscription() { return inscription; }

float query_weight_oz() { return weight_oz; }

object query_owner() { return owner; }

mixed query_enchantment() { return enchantment; }
