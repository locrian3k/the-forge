#pragma strong_types
#include "defs.h"

// Exercise 17.2, Chat and Spells
// A dark mage with a multi-spell attack system.

inherit "obj/complex_monster";

void create()
{
  ::create();

  // Identity
  set_name("a shadow mage");
  set_alias(({"mage", "shadow mage", "dark mage"}));
  set_race("human");
  set_short("a shadow mage");
  set_long(
    "A gaunt figure wrapped in tattered black robes, its face "
    "hidden beneath a deep cowl. Wisps of dark energy crackle "
    "between its bony fingers, and the air around it feels "
    "unnaturally cold."
  );

  // Combat properties
  set_level(12);
  set_al(-500);
  set_aggressive(1);

  // Spell attack messages seen by the room ($N$ = target name)
  set_spell_mess1(({
    "The shadow mage hurls a bolt of dark fire at $N$!\n",
    "The shadow mage gestures and a wave of frost crashes into $N$!\n",
    "The shadow mage whispers a curse and $N$ writhes in agony!\n",
  }));

  // Spell attack messages seen by the target (use "you")
  set_spell_mess2(({
    "The shadow mage hurls a bolt of dark fire at you!\n",
    "The shadow mage gestures and a wave of frost crashes into you!\n",
    "The shadow mage whispers a curse and you writhe in agony!\n",
  }));

  // Damage types, one per spell
  set_spell_type(({"fire", "ice", "mind"}));

  // Base damage values, negative means level-scaled
  set_spell_dam(({-80, -80, -80}));

  // Relative weights, fire is most common
  set_spell_probabilities(({3, 2, 1}));

  // Combat chat, taunts during battle
  load_a_chat(
    12,
    ({
      "The shadow mage cackles: 'Your soul will feed the void!'\n",
      "The shadow mage hisses: 'You cannot escape the darkness!'\n",
      "The shadow mage intones words of power under its breath.\n",
    })
  );

  // Idle chat, ambient behavior out of combat
  load_chat(
    8,
    ({
      "The shadow mage traces arcane symbols in the air.\n",
      "The shadow mage mutters an incantation to itself.\n",
      "Dark energy flickers between the shadow mage's fingers.\n",
      "The shadow mage stares into the darkness, unblinking.\n",
    })
  );

  return;
}

// Intimidating description appended to room look
string extra_look()
{
  if (query_attack())
    return "A shadow mage is here, wreathed in crackling dark energy!\n";

  return "A shadow mage is here, brooding in silence.\n";
}
