/*
  ex02_weapon_hits.c
  Exercise 15.2 — Weapon Hits (Super Weapon)
  Create a super weapon with a weapon_hits() callback that fires
  every combat round. Implement at least two special procs
  (e.g. elemental burst, life steal) with combat messages.
*/

#pragma strong_types
#include "../defs.h"

inherit "obj/super_weapon";

void create()
{
  ::create();

  // TODO: Set creator, name, aliases, short, long, type, weight, value
  //       (same as a basic weapon)

  // TODO: Register this object as its own hits callback.
  //       This tells the combat system to call weapon_hits() on
  //       this object every combat round.

  return;
}

// weapon_hits() is called every combat round by the combat system.
// It receives the object being attacked as its argument.
// It must return a 10-element damage array:
//   ({edged, blunt, fire, ice, acid, elec, mind, energy, poison, rad})
// Each element is bonus damage of that type added on top of base wc.
// Return all zeros for no bonus damage.
int *weapon_hits(object target)
{
  int roll;

  roll = random(100);

  // TODO: Implement at least two special procs using the roll value.
  //
  //   For each proc:
  //     - Check if the roll falls within a probability range
  //     - Print a message to the wielder with write()
  //     - Print a message to the room with say()
  //     - Return a 10-element damage array with bonus damage
  //       in the appropriate element position

  // Default: no bonus damage (base wc still applies)
  return ({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
}
