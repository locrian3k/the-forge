#pragma strong_types
#include "defs.h"

// Iron Sentinel - a construct monster that shifts into
// an electrified combat mode when damaged below half HP.

inherit "obj/monster";

// Battle cries spoken during combat
string *battle_cries;

// Whether the sentinel has entered its enraged attack mode
status attack_mode;

// Function prototypes
void create();
void init();
status do_inspect(string arg);
void heart_beat();
string query_battle_cry();

// Set up the sentinel's base stats, chat lines, and combat.
void create()
{
  ::create();
  set_name("iron sentinel");
  set_short("An iron sentinel");
  set_long(
    "A towering construct of riveted iron plates and "
    "grinding gears, the sentinel stands motionless "
    "until a threat enters its patrol zone. Sparks "
    "crackle between the joints of its massive arms.");
  set_race("construct");
  set_level(18);
  set_hp(400);
  set_al(-200);
  set_gender("neuter");
  set_body_type("human");
  set_wielding_limbs( ({ "right hand", "left hand" }) );
  set_damage_type("bludgeon");
  set_chat_chance(15);
  set_chat( ({
    "The sentinel's eyes flare with a dull red glow.",
    "Gears grind and click inside the sentinel's chest.",
    "The sentinel swivels its head, scanning the area.",
    "Steam hisses from vents along the sentinel's back.",
  }) );
  battle_cries = ({
    "INTRUDER DETECTED.",
    "ENGAGING THREAT PROTOCOL.",
    "YOU WILL BE NEUTRALIZED.",
  });
  attack_mode = 0;
  return;
}

// Allow players to inspect the sentinel for status clues.
void init()
{
  ::init();
  add_action("do_inspect", "inspect");
  return;
}

// Describe the sentinel's current combat state.
status do_inspect(string arg)
{
  if (!arg || arg != "sentinel")
    return 0;
  if (attack_mode)
    write(
      "The sentinel is in full combat mode. Its eyes "
      "burn bright red and its fists crackle with "
      "energy.");
  else
    write(
      "The sentinel stands in patrol mode. Its eyes "
      "glow a dim amber as it watches for intruders.");
  return 1;
}

// When damaged below half HP, switch to electricity mode.
void heart_beat()
{
  ::heart_beat();
  if (query_hp() < 200 && !attack_mode)
  {
    attack_mode = 1;
    set_damage_type("electricity");
    say("The iron sentinel roars as arcs of "
      "electricity surge across its frame!");
  }
  return;
}

// Return a random battle cry from the list.
string query_battle_cry()
{
  return battle_cries[random(sizeof(battle_cries))];
}
