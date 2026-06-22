#pragma strong_types
#include "../defs.h"

// Exercise 19.1, Heartbeat Timer
// A room with periodic ambient messages driven by heart_beat().

inherit "room/room";

// Track heartbeat cycles
int beat_counter;

// Ambient messages displayed periodically
string *ambient_messages = ({
  "A cold draft whistles through a crack in the stone.\n",
  "Water drips steadily from the ceiling into a shallow pool.\n",
  "Loose stones shift somewhere in the darkness above.\n",
  "The torchlight flickers, and shadows dance on the walls.\n",
  "A faint groaning sound echoes from deep within the earth.\n",
});

void create()
{
  ::create();
  set_light(1);

  set_short("The Dripping Cavern");
  set_long(
    "A damp cavern with a low ceiling that weeps moisture. "
    "Stalactites hang overhead like stone teeth, and shallow "
    "pools of water dot the uneven floor. The air is cold "
    "and smells of wet stone."
  );

  add_item(
    ({"stalactites", "ceiling", "stone teeth"}),
    "Sharp stalactites hang from the ceiling, some dripping "
    "steadily into the pools below."
  );
  add_item(
    ({"pools", "water", "puddles"}),
    "Shallow pools of clear water collect in depressions in "
    "the stone floor, fed by drips from above."
  );

  add_exit("/room/entrance", "south");

  // Initialize heartbeat tracking
  beat_counter = 0;
  set_heart_beat(1);

  return;
}

// Called approximately every 2 seconds by the driver
void heart_beat()
{
  beat_counter++;

  // Every 5 beats (~10 seconds), show an ambient message
  if (beat_counter % 5 == 0)
    tell_room(
      TO,
      ambient_messages[random(sizeof(ambient_messages))]
    );

  // If the room is empty, stop the heartbeat to save CPU
  if (!sizeof(filter(all_inventory(TO), #'living)))
    set_heart_beat(0);

  return;
}

// Restart the heartbeat when a living object enters the room
void init()
{
  ::init();
  set_heart_beat(1);

  return;
}
