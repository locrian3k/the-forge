/*
  ex02_call_out.c
  Exercise 19.2 — Call Out Trap
  Create a room with a delayed trap that fires a few seconds
  after a player enters. The trap can be avoided by leaving
  before it triggers. Uses call_out() for the delay.
*/

#pragma strong_types
#include "../defs.h"

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  // TODO: Set short and long descriptions for a trapped corridor.
  //       Hint at the trap with details like loose flagstones,
  //       holes in the walls, etc.

  // TODO: Add examinable items (flagstones, holes, etc.)

  // TODO: Add exits (at least 2, so the player can escape).

  return;
}

void init()
{
  ::init();

  // TODO: Only trigger for living objects (players, monsters).
  //       Use living(TP) to check.

  // TODO: Prevent duplicate call_outs if a trap is already pending.
  //       Use find_call_out() to check if one exists (-1 means none).

  // TODO: Schedule the trap to fire after a delay.
  //       Syntax: call_out("function_name", seconds);

  // TODO: Add actions on exit directions so do_leave() can cancel
  //       the trap when the player moves to leave.

  return;
}

// The trap fires after the call_out delay.
void trigger_trap()
{
  object *victims;

  // TODO: Find all living objects still in the room.
  //       Use filter() with all_inventory(TO) and #'living.
  //       Return early if no victims remain.

  // TODO: Describe the trap going off using tell_room().

  // TODO: Damage each victim in the room.
  //       Loop through victims, tell each one about the hit,
  //       and call victim->hit_player(damage, 0, type) on each.

  return;
}

// Cancel the trap when a player moves to leave.
// Return 0 so normal exit processing still continues.
status do_leave(string arg)
{
  // TODO: Cancel the pending trap using remove_call_out().

  return 0;
}
