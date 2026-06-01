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

// TODO: Declare an int counter variable to track heartbeat cycles.

// TODO: Declare a string array of ambient message strings.
//       Include at least 3-5 atmospheric messages, each ending with \n.

void create()
{
  ::create();
  set_light(1);

  // TODO: Set short and long descriptions for an atmospheric room
  //       (e.g. a dripping cavern, a haunted chamber).

  // TODO: Add examinable items.

  // TODO: Add at least one exit.

  // TODO: Initialize the heartbeat counter to 0.

  // TODO: Start the heartbeat using set_heart_beat().

  return;
}

// heart_beat() is called approximately every 2 seconds by the driver.
void heart_beat()
{
  // TODO: Increment the beat counter.

  // TODO: Every N beats (e.g. every 5 beats = ~10 seconds),
  //       display a random ambient message to the room.
  //       Hint: Use modulo (%) to check intervals, random() to
  //       pick a message, and tell_room() to display it.

  // TODO: If the room is empty (no living objects), stop the
  //       heartbeat to save CPU.
  //       Hint: Use filter() with #'living to find living objects,
  //       and sizeof() to check if the result is empty.

  return;
}

// Restart the heartbeat when a living object enters the room.
void init()
{
  ::init();

  // TODO: Restart the heartbeat.

  return;
}
