#pragma strong_types
#include "../defs.h"

// Exercise 17.1, Basic Monster
// A simple cave goblin using /obj/monster.

inherit "obj/monster";

void create()
{
  ::create();

  // Set the monster's identity
  set_name("a cave goblin");
  set_alias(({"goblin", "cave goblin"}));
  set_race("goblin");

  // Set descriptions visible to players
  set_short("a cave goblin");
  set_long(
    "A scrawny goblin crouches here, its yellowish skin smeared "
    "with grime and old blood. Beady red eyes dart about nervously, "
    "and it clutches a crude stone knife in one clawed hand."
  );

  // Set combat properties
  set_level(5);
  set_al(-200);
  set_aggressive(1);

  // Load idle chat messages, the goblin mutters and fidgets
  load_chat(
    10,
    ({
      "The cave goblin sniffs the air suspiciously.\n",
      "The cave goblin gnaws on a bone it found somewhere.\n",
      "The cave goblin mutters something in a guttural tongue.\n",
      "The cave goblin scratches behind its ear with a dirty claw.\n",
    })
  );

  return;
}

// extra_look() is appended when players look at the monster
string extra_look()
{
  return "A cave goblin is here, watching you with hungry eyes.\n";
}
