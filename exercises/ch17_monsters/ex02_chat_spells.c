/*
  ex02_chat_spells.c
  Exercise 17.2 — Chat and Spells (Complex Monster)
  Create a complex monster with a multi-spell attack system,
  combat chat, and idle chat. Uses /obj/complex_monster.
*/

#pragma strong_types
#include "defs.h"

inherit "obj/complex_monster";

void create()
{
  ::create();

  // TODO: Set identity (name, aliases, race, short, long)
  //       Same pattern as a basic monster.

  // TODO: Set combat properties (level, alignment, aggressive)

  // TODO: Set spell attack messages seen by the room.
  //       $N$ is replaced with the target's name.
  //       set_spell_mess1(({
  //         "The mage hurls fire at $N$!\n",
  //         "The mage blasts $N$ with ice!\n",
  //         "The mage curses $N$!\n",
  //       }));

  // TODO: Set spell attack messages seen by the target (use "you").
  //       Must have the same number of entries as spell_mess1.
  //       set_spell_mess2(({
  //         "The mage hurls fire at you!\n",
  //         "The mage blasts you with ice!\n",
  //         "The mage curses you!\n",
  //       }));

  // TODO: Set damage types, one per spell.
  //       set_spell_type(({"fire", "ice", "mind"}));

  // TODO: Set base damage values. Negative means level-scaled.
  //       set_spell_dam(({-80, -80, -80}));

  // TODO: Set spell probabilities (relative weights).
  //       Higher number = more frequent.
  //       set_spell_probabilities(({3, 2, 1}));

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
  //       if (query_attack())
  //         return "combat description\n";
  //       return "idle description\n";

  return "";
}
