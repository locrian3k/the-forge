/*
  ex02_readable_object.c
  Exercise 14.2 — Readable Object
  A scroll or journal that players can read using add_action().
*/
#pragma strong_types
#include "../defs.h"
inherit "obj/treasure";

void create()
{
  ::create();

  // TODO: Set the creator using set_creator()

  // TODO: Set the internal name using set_name()

  // TODO: Set aliases with at least 3 alternate names using set_alias()

  // TODO: Set a short description using set_short()

  // TODO: Set a long description (hint that it can be read)
  //   The description should mention that the scroll has
  //   legible writing and suggest the player read it.

  // TODO: Set weight and value

  return;
}

void init()
{
  ::init();

  // TODO: Register the "read" command using add_action()
  //   Syntax: add_action("handler_function", "verb");

  return;
}

// TODO: Implement the read handler.
//   Return type: status (1 if handled, 0 if not)
//
//   Steps:
//   1. Return 0 if str is missing or doesn't match this object.
//      Use id(str) to check if the string matches our name/aliases.
//   2. Display the scroll's contents using write().
//      Include at least 5 lines of multi-line text.
//   3. Return 1 to indicate the command was handled.
