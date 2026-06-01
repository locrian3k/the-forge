# Monster Creation — Quick Reference

## Monster Tiers

| Inherit | Use for | Features |
|---------|---------|----------|
| `/obj/monster` | Basic mobs | Chat, spells, simple behavior |
| `/obj/complex_monster` | Mid-tier | Extra attacks, conditions |
| `/obj/super_monster` | Bosses | Multi-life, modify_damage, full control |

## Basic Monster (/obj/monster)

```lpc
#pragma strong_types
#include "../defs.h"

inherit "obj/monster";

void create()
{
  ::create();
  set_name("goblin");
  set_alias(({"green goblin", "mob"}));
  set_short("A snarling goblin");
  set_long("A small green-skinned goblin with beady eyes.");
  set_level(8);
  set_race("goblin");
  set_aggressive(1);
  set_gender(1);       // 0=neuter, 1=male, 2=female
  set_alignment(-50);  // negative=evil, positive=good
  load_chat(20, ({
    "The goblin snarls at you.\n",
    "The goblin picks its nose.\n",
  }));
  load_a_chat(30, ({
    "The goblin shrieks a battle cry!\n",
  }));
  return;
}
```

## Core Functions

| Function | Description | Example |
|----------|-------------|---------|
| `set_level(n)` | Monster level | `set_level(12)` |
| `set_race(str)` | Race name | `set_race("orc")` |
| `set_aggressive(n)` | Auto-attack (0/1) | `set_aggressive(1)` |
| `set_gender(n)` | 0=neuter,1=M,2=F | `set_gender(2)` |
| `set_alignment(n)` | Evil(-) to Good(+) | `set_alignment(-100)` |
| `set_hp(n)` | Set current HP | `set_hp(500)` |
| `set_max_hp(n)` | Set max HP | `set_max_hp(500)` |

## Chat Messages

```lpc
// Idle chat: percentage chance per heartbeat, array of messages
load_chat(15, ({
  "The guard yawns.\n",
  "The guard adjusts his helmet.\n",
}));

// Combat chat: fires during combat
load_a_chat(25, ({
  "The guard shouts: Take that!\n",
  "The guard parries your blow!\n",
}));
```

## Spell System

```lpc
set_spell_mess1("The mage hurls a fireball at you!");
set_spell_mess2("The mage hurls a fireball at $N!");
// $N = target name in mess2
set_spell_dam(40);       // spell damage
set_spell_type("fire");  // damage type
set_chance(30);          // % chance per round
```

## Monster Equipment

```lpc
void create()
{
  ::create();
  // ... basic setup ...

  // Give monster equipment
  object weapon = clone_object(OBJ + "rusty_sword");
  weapon->move(this_object());
  command("wield sword");

  object armor = clone_object(OBJ + "leather");
  armor->move(this_object());
  command("wear leather");
  return;
}
```

## Super Monster (Boss)

```lpc
#pragma strong_types
#include "../defs.h"

inherit "obj/super_monster";

nosave int lives;

void create()
{
  ::create();
  set_name("dragon");
  set_alias(({"red dragon", "beast"}));
  set_short("A massive red dragon");
  set_long("A towering red dragon with scales like shields.");
  set_level(25);
  set_race("dragon");
  set_aggressive(1);
  lives = 2;
  return;
}
```

## modify_damage (Super Monster)

Intercept and modify incoming damage:

```lpc
int modify_damage(int dam, string dam_type, int *att_wc)
{
  // Damage reduction
  if (dam > 50)
    dam = 50 + (dam - 50) / 2;

  // Counter-attack
  if (random(100) < 20)
  {
    object attacker = (object)this_object()->query_attacker();
    tell_object(attacker, "The dragon breathes fire at you!\n");
    attacker->do_damage("fire", 30 + random(20));
  }

  return dam;  // return modified damage
}
```

## monster_died

Called when the monster reaches 0 HP:

```lpc
void monster_died()
{
  tell_room(ETO, "The beast lets out a final roar!\n");

  // Drop loot
  object loot = clone_object(OBJ + "dragon_scale");
  loot->move(ETO);

  // Spawn next phase
  object phase2 = clone_object(MON + "dragon_spirit");
  phase2->move(ETO);

  return;
}
```

## Multi-Life Boss Pattern

```lpc
int modify_damage(int dam, string dam_type, int *att_wc)
{
  if ((int)this_object()->query_hp() - dam <= 0 && lives > 1)
  {
    lives--;
    this_object()->set_hp((int)this_object()->query_max_hp());
    tell_room(ETO, "The dragon roars and regenerates!\n");
    return 0;  // negate killing blow
  }
  return dam;
}
```

## Spawning in Rooms

```lpc
// In room's reset():
void reset()
{
  ::reset();
  add_clone(MON + "goblin");       // max 1
  add_clone(MON + "goblin", 3);    // up to 3
  return;
}
```

## extra_look

Add text when players look at the monster:

```lpc
string extra_look()
{
  if (lives > 1)
    return "It looks barely wounded.\n";
  return "It is breathing heavily.\n";
}
```
