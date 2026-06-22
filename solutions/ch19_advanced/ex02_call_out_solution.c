#pragma strong_types
#include "../defs.h"

// Exercise 19.2, Call Out Trap
// A room with a delayed trap that fires 3 seconds after entry.

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  set_short("A Suspicious Corridor");
  set_long(
    "A narrow stone corridor with a slightly uneven floor. "
    "Several of the flagstones appear loose, and small holes "
    "are drilled into the walls at ankle height. The air "
    "carries a faint metallic scent."
  );

  add_item(
    ({"flagstones", "floor", "stones", "loose stones"}),
    "Several flagstones sit slightly higher than the rest, "
    "as though they are pressure plates waiting to be stepped on."
  );
  add_item(
    ({"holes", "walls", "wall holes"}),
    "Small round holes are drilled into the walls at regular "
    "intervals. They look just wide enough for a dart."
  );

  add_exit("/room/entrance", "south");
  add_exit("/room/entrance", "north");

  return;
}

void init()
{
  ::init();

  // Only trigger for living objects (players, monsters)
  if (!living(TP))
    return;

  // Prevent duplicate call_outs if another player is already in the room
  if (find_call_out("trigger_trap") != -1)
    return;

  // Schedule the trap to fire in 3 seconds
  call_out("trigger_trap", 3);

  // Add a cancel action for when the player leaves
  add_action("do_leave", "north");
  add_action("do_leave", "south");

  return;
}

// The trap fires after the delay
void trigger_trap()
{
  object *victims;

  // Find all living objects still in the room
  victims = filter(all_inventory(TO), #'living);
  if (!sizeof(victims))
    return;

  // Describe the trap going off
  tell_room(
    TO,
    "A flagstone shifts underfoot with a click! Darts shoot "
    "from the walls with a sharp hiss!\n"
  );

  // Damage each victim in the room
  foreach (object victim : victims)
  {
    tell_object(victim, "A dart strikes you! Ouch!\n");
    victim->hit_player(20, 0, "blunt");
  }

  return;
}

// Cancel the trap when a player moves to leave
status do_leave(string arg)
{
  // Cancel pending trap, the player is escaping
  remove_call_out("trigger_trap");

  // Return 0 to allow normal exit processing to continue
  return 0;
}
