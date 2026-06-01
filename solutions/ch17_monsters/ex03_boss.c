#pragma strong_types
#include "defs.h"

// Exercise 17.3, Boss Monster
// An iron golem boss with damage reduction and death narrative.

inherit "obj/super_monster";

void create()
{
  ::create();

  // Boss identity
  set_name("the Iron Warden");
  set_alias(({
    "warden", "iron warden", "golem", "iron golem",
    "the iron warden",
  }));
  set_race("golem");
  set_short("the Iron Warden");
  set_long(
    "A towering construct of riveted iron plates and grinding "
    "gears, the Iron Warden stands nearly eight feet tall. Its "
    "eyes burn with a dull crimson light, and steam hisses from "
    "the joints of its massive fists. Ancient runes of binding "
    "are etched across its chest plate."
  );

  // Combat properties
  set_level(20);
  set_al(-800);
  set_aggressive(1);

  // Boss-specific properties
  add_property("NOPEACE");
  set_dead_ob(TO);

  // Loot drop, a weapon cloned into the boss's inventory
  add_clone("/obj/weapon");

  // Spell attacks, the golem has physical and fire abilities
  set_spell_mess1(({
    "The Iron Warden slams a massive fist into $N$!\n",
    "The Iron Warden vents a gout of superheated steam at $N$!\n",
    "The Iron Warden charges forward and body-slams $N$!\n",
  }));
  set_spell_mess2(({
    "The Iron Warden slams a massive fist into you!\n",
    "The Iron Warden vents a gout of superheated steam at you!\n",
    "The Iron Warden charges forward and body-slams you!\n",
  }));
  set_spell_type(({"blunt", "fire", "blunt"}));
  set_spell_dam(({-80, -80, -80}));
  set_spell_probabilities(({3, 2, 1}));

  // Combat chat
  load_a_chat(
    10,
    ({
      "The Iron Warden's gears grind ominously as it advances.\n",
      "Steam erupts from the Iron Warden's joints with a piercing whistle.\n",
      "The Iron Warden's eyes flare brighter as it locks onto its target.\n",
    })
  );

  // Idle chat
  load_chat(
    6,
    ({
      "The Iron Warden stands motionless, its eyes tracking movement.\n",
      "Gears click and whir inside the Iron Warden's iron frame.\n",
      "A low rumble emanates from deep within the Iron Warden's chest.\n",
      "The Iron Warden's head swivels slowly, scanning the room.\n",
    })
  );

  return;
}

// Reduce all incoming damage, the golem's iron hide absorbs blows.
// Physical damage is reduced to 25%, other types to 50%.
int modify_damage(int dam, string dam_type, int *att_wc)
{
  if (!dam_type || dam_type == "edged" || dam_type == "blunt")
    return dam / 4;

  return dam / 2;
}

// Called when the boss dies, narrate the death and drop loot
void monster_died()
{
  // Tell the room the boss's death story
  tell_room(
    environment(TO),
    "\nThe Iron Warden staggers, its crimson eyes flickering. "
    "Cracks spread across its iron frame as the binding runes "
    "shatter one by one.\n\n"
    "With a tremendous crash, the construct collapses into a "
    "heap of twisted metal and spent gears. A final wisp of "
    "steam rises from the wreckage.\n"
  );

  // Move all inventory (loot) from the boss to the room
  map(all_inventory(TO), #'move_object, environment(TO));

  return;
}

// Message shown to a player killed by this boss
string query_death_message(object for_who)
{
  return sprintf(
    "\nThe Iron Warden looms over %s's broken body. Its eyes "
    "pulse once, then it resumes its endless vigil, as though "
    "nothing happened.\n",
    (string)for_who->query_real_name()
  );
}

// Room description appended when looking at the boss
string extra_look()
{
  if (query_attack())
    return
      "The Iron Warden is here, gears screaming as it "
      "pummels its target!\n";

  return
    "The Iron Warden stands here, a silent sentinel of "
    "riveted iron.\n";
}
