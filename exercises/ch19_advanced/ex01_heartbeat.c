/*
  ex01_heartbeat.c
  Exercise 19.1 — Heartbeat Timer
  Create a room with periodic ambient messages driven by
  heart_beat(). The heartbeat should stop when the room is
  empty and restart when a player enters.
*/

#pragma strong_types
#include "defs.h"

inherit "room/room";

// TODO: Declare a counter variable to track heartbeat cycles.
//       int beat_counter;

// TODO: Declare an array of ambient message strings.
//       string *ambient_messages = ({
//         "A cold draft whistles through a crack in the stone.\n",
//         "Water drips from the ceiling.\n",
//         // ... add at least 3-5 messages
//       });

void create()
{
  ::create();
  set_light(1);

  // TODO: Set short and long descriptions for an atmospheric room
  //       (e.g. a dripping cavern, a haunted chamber).

  // TODO: Add examinable items.

  // TODO: Add at least one exit.

  // TODO: Initialize the heartbeat counter to 0.

  // TODO: Start the heartbeat with set_heart_beat(1);

  return;
}

// heart_beat() is called approximately every 2 seconds by the driver.
void heart_beat()
{
  // TODO: Increment the beat counter.

  // TODO: Every N beats (e.g. every 5 beats = ~10 seconds),
  //       display a random ambient message to the room using
  //       tell_room(TO, message).
  //       Use beat_counter % 5 == 0 to check.
  //       Pick a random message with random(sizeof(ambient_messages)).

  // TODO: If the room is empty (no living objects), stop the
  //       heartbeat to save CPU: set_heart_beat(0);
  //       Use filter(all_inventory(TO), #'living) to find living
  //       objects, and sizeof() to check if the result is empty.

  return;
}

// Restart the heartbeat when a living object enters the room.
void init()
{
  ::init();

  // TODO: Restart the heartbeat: set_heart_beat(1);

  return;
}
