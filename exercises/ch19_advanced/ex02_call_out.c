/*
  ex02_call_out.c
  Exercise 19.2 — Call Out Trap
  Create a room with a delayed trap that fires a few seconds
  after a player enters. The trap can be avoided by leaving
  before it triggers. Uses call_out() for the delay.
*/

#pragma strong_types
#include "defs.h"

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
  //       if (!living(TP))
  //         return;

  // TODO: Prevent duplicate call_outs if a trap is already pending.
  //       if (find_call_out("trigger_trap") != -1)
  //         return;

  // TODO: Schedule the trap to fire after a delay:
  //       call_out("trigger_trap", 3);
  //       The 3 means 3 seconds.

  // TODO: Add actions on exit directions so do_leave() can cancel
  //       the trap when the player moves to leave:
  //       add_action("do_leave", "north");
  //       add_action("do_leave", "south");

  return;
}

// The trap fires after the call_out delay.
void trigger_trap()
{
  object *victims;

  // TODO: Find all living objects still in the room.
  //       victims = filter(all_inventory(TO), #'living);
  //       if (!sizeof(victims))
  //         return;

  // TODO: Describe the trap going off using tell_room().

  // TODO: Damage each victim in the room:
  //       foreach (object victim : victims)
  //       {
  //         tell_object(victim, "A dart strikes you!\n");
  //         victim->hit_player(20, 0, "blunt");
  //       }

  return;
}

// Cancel the trap when a player moves to leave.
// Return 0 so normal exit processing still continues.
status do_leave(string arg)
{
  // TODO: Cancel the pending trap:
  //       remove_call_out("trigger_trap");

  return 0;
}
