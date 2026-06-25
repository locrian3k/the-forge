/*
  ex02_chat_spells.c
  YourName YYMMDD
  Exercise 17.2 — Chat and Spells (Complex Monster)
  Create a complex monster with a multi-spell attack system,
  combat chat, and idle chat. Uses /obj/complex_monster.
*/

#pragma strong_types
#include "../defs.h"

inherit "obj/complex_monster";

void create()
{
  ::create();

  // TODO: Set identity (name, aliases, race, short, long)
  //       Same pattern as a basic monster.

  // TODO: Set combat properties (level, alignment, aggressive)

  // TODO: Set spell attack messages seen by the room.
  //       $N$ is replaced with the target's name.
  //       Use set_spell_mess1() with an array of message strings.

  // TODO: Set spell attack messages seen by the target (use "you").
  //       Must have the same number of entries as spell_mess1.
  //       Use set_spell_mess2() with an array of message strings.

  // TODO: Set damage types, one per spell.
  //       Use set_spell_type() with an array of type strings.

  // TODO: Set base damage values. Negative means level-scaled.
  //       Use set_spell_dam() with an array of integers.

  // TODO: Set spell probabilities (relative weights).
  //       Higher number = more frequent.
  //       Use set_spell_probabilities() with an array of integers.

  // TODO: Load combat chat using load_a_chat(chance, array)
  //       These messages appear during combat.

  // TODO: Load idle chat using load_chat(chance, array)
  //       These messages appear when the monster is idle.

  return;
}

// extra_look() can check query_attack() to vary the description
// based on whether the monster is currently fighting.
string extra_look()
{
  // TODO: Return different descriptions based on combat state.
  //       Use query_attack() to check if the monster is fighting.
  //       Return one string if in combat, another if idle.

  return "";
}
