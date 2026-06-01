/*
  ex01_hello.c
  YourName YYMMDD
  Exercise 1.1 — Hello Mud
  A simple training stone: the most basic LPC object.
*/
#pragma strong_types
#include "defs.h"

inherit "obj/treasure";

void create()
{
  ::create();

  // TODO: Set the object's internal name to "training stone"
  //   set_name("training stone");

  // TODO: Set alternate names players can use
  //   set_alias(({"stone", "training stone"}));

  // TODO: Set the one-line description shown in room inventories
  //   set_short("a training stone");

  // TODO: Set the full description shown when a player examines
  //       the object. Write a sentence or two of your own.
  //   set_long("Your description here.");

  // TODO: Set the gold value to 10
  //   set_value(10);

  // TODO: Set the weight to 1
  //   set_weight(1);

  return;
}
