/*
  ex03_boss.c
  YourName YYMMDD
  Exercise 17.3 — Boss Monster (Super Monster)
  Create a boss using /obj/super_monster with damage reduction,
  a death narrative, a death message for slain players, loot drop,
  and spell attacks.
*/

#pragma strong_types
#include "../defs.h"

inherit "obj/super_monster";

void create()
{
  ::create();

  // TODO: Set boss identity (name, aliases, race, short, long)

  // TODO: Set combat properties (level, alignment, aggressive)
  //       Bosses are typically high level (15+).

  // TODO: Set boss-specific properties:
  //       - Prevent players from using "peace" with add_property()
  //       - Enable the monster_died() callback with set_dead_ob()

  // TODO: Set loot using add_clone().
  //       When the boss dies, monster_died() should move
  //       inventory to the room.

  // TODO: Set spell attacks (spell_mess1, spell_mess2, spell_type,
  //       spell_dam, spell_probabilities) — same as complex_monster.

  // TODO: Load combat chat with load_a_chat(chance, array)

  // TODO: Load idle chat with load_chat(chance, array)

  return;
}

// modify_damage() is called for every hit the boss takes.
// Use it to reduce incoming damage (damage reduction / armor).
//   dam      - the raw damage amount
//   dam_type - the damage type string ("edged", "blunt", "fire", etc.)
//   att_wc   - the attacker's weapon class array
// Return the modified (reduced) damage value.
int modify_damage(int dam, string dam_type, int *att_wc)
{
  // TODO: Implement damage reduction. For example:
  //       - Reduce physical damage (edged/blunt) to 25%: dam / 4
  //       - Reduce other damage types to 50%: dam / 2
  //       Check for !dam_type as well (untyped damage is physical).

  return dam;
}

// monster_died() is called when the boss reaches 0 HP.
// Use it to narrate the death and handle loot.
void monster_died()
{
  // TODO: Narrate the boss's death to everyone in the room.
  //       Syntax: tell_room(environment(TO), "message");

  // TODO: Move all inventory (loot) from the boss to the room.
  //       Hint: Use map() with all_inventory(TO), #'move_object,
  //       and environment(TO) to move all items at once.

  return;
}

// query_death_message() returns the message shown to a player
// killed by this boss. The for_who argument is the dying player.
string query_death_message(object for_who)
{
  // TODO: Return a thematic death message. Use for_who->query_real_name()
  //       to include the player's name. Include \n at start and end.

  return "";
}

// extra_look() — room description when looking at the boss.
string extra_look()
{
  // TODO: Return different descriptions based on combat state.
  //       Use query_attack() to check.

  return "";
}
