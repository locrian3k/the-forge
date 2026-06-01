/*
  ex02_reformat.c
  Exercise 11.2 — Reformat from Scratch
  This monster file compiles and works correctly but uses horrible
  formatting. Reformat it entirely to match 3K codestyle.

  Do NOT change any game behavior (same name, level, stats, chats).

  Issues to fix:
    - Mixed tabs/spaces: convert everything to 2-space indentation
    - Inconsistent indentation depths (4, 8, and random levels)
    - K&R brackets: convert all to Allman style
    - Lines over 80 characters: wrap long strings and statements
    - Missing comments: add function-level comments and section headers
    - int used for boolean attack_mode: should be status
    - int return type on do_inspect: should be status
    - void on a separate line from function name in heart_beat
    - Multiple statements crammed onto single lines: split them
    - Double-spacing between sentences: convert to single spacing
    - Single-statement if/else should not have brackets
    - Add proper variable declarations section with comments
    - Add proper file structure order
*/
#pragma strong_types
#include "../defs.h"
inherit "obj/monster";

string *battle_cries;int attack_mode;

void create(){
        ::create();
        set_name("iron sentinel");
        set_short("An iron sentinel");
        set_long("A towering construct of riveted iron plates and grinding gears, the sentinel stands motionless until a threat enters its patrol zone. Sparks crackle between the joints of its massive arms.");
  set_race("construct");
        set_level(18);set_hp(400);set_al(-200);
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
     battle_cries = ({ "INTRUDER DETECTED.", "ENGAGING THREAT PROTOCOL.", "YOU WILL BE NEUTRALIZED." });
   attack_mode = 0;
}

void init(){
  ::init();
  add_action("do_inspect", "inspect");
}

int do_inspect(string arg) {
    if (!arg || arg != "sentinel") return 0;
    if (attack_mode) {write("The sentinel is in full combat mode.  Its eyes burn bright red and its fists crackle with energy."); }
else { write("The sentinel stands in patrol mode.  Its eyes glow a dim amber as it watches for intruders."); }
return 1;
}

void
heart_beat()
{
  ::heart_beat();
  if (query_hp() < 200 && !attack_mode)
  {
          attack_mode = 1;
          set_damage_type("electricity");
      say("The iron sentinel roars as arcs of electricity surge across its frame!");
  }
}

string query_battle_cry(){
  return battle_cries[random(sizeof(battle_cries))];
}
