/*
  ex01_hello.c
  Mimic 260315
  Exercise 1.1 — Hello Mud
  A simple training stone: the most basic LPC object.
*/
#pragma strong_types
#include "../defs.h"

inherit "obj/treasure";

void create()
{
  ::create();

  // Set the object's identity
  set_name("training stone");
  set_alias(({"stone", "training stone"}));

  // Set descriptions visible to players
  set_short("a training stone");
  set_long(
    "A smooth grey stone etched with the symbol of The Forge. "
    "It hums faintly with latent potential, as though waiting "
    "for its creator to learn more."
  );

  // Set economic and physical properties
  set_value(10);
  set_weight(1);

  return;
}
