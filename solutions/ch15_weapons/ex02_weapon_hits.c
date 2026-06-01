#pragma strong_types
#include "../defs.h"
inherit "obj/super_weapon";

// Exercise 15.2 - Weapon Hits
// A frost-enchanted sword with special combat procs:
//   10% - Frost Burst (ice damage + message)
//    5% - Life Steal (heals wielder + edged damage)
//   85% - Normal hit (no bonus damage)

void create()
{
  ::create();
  set_creator("mimic");
  set_name("frost blade");
  set_alias(({"blade","frost blade","sword","icy sword",
    "frozen blade"}));
  set_short("A Frost-Rimed Blade");
  set_long(
    "A slender longsword coated in a perpetual sheen of frost. "
    "Tiny ice crystals form along the edge and drift away like "
    "frozen sparks when the blade is moved. The crossguard is "
    "fashioned from pale blue steel, and the grip is wrapped in "
    "white leather that is always cold to the touch.");
  set_type("sword");
  set_weight(3);
  set_value(500);

  // Register this object as its own hits callback
  set_hits_func(TO);
  return;
}

// Called every combat round by the driver. Returns a 10-element
// damage array: ({edged,blunt,fire,ice,acid,elec,mind,energy,poison,rad})
int *weapon_hits(object target)
{
  int roll;

  roll = random(100);

  // 10% - Frost Burst: bonus ice damage
  if (roll < 10)
  {
    write(sprintf(
      "Your frost blade erupts in a blast of frigid air! "
      "Ice shards rake across %s!\n",
      (string)target->query_name()));
    say(sprintf(
      "%s's sword explodes with icy fury!\n",
      capitalize((string)TP->query_name())));
    return ({0, 0, 0, 18, 0, 0, 0, 0, 0, 0});
  }

  // 5% - Life Steal: heal the wielder and deal edged damage
  if (roll < 15)
  {
    write(
      "The frost blade glows with a pale light as it drains "
      "warmth from your enemy, mending your wounds!\n");
    say(sprintf(
      "A pale glow surrounds %s's blade as it strikes!\n",
      capitalize((string)TP->query_name())));
    TP->heal_self(15);
    return ({12, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  }

  // 85% - Normal hit: no bonus damage (base wc still applies)
  return ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
}
