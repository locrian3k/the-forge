/*
  ex02_readable_object.c
  Exercise 14.2 — Readable Object
  A scroll or journal that players can read using add_action().
*/
#pragma strong_types
#include "defs.h"
inherit "obj/treasure";

void create()
{
  ::create();

  // TODO: Set the creator
  //   set_creator("mimic");

  // TODO: Set the internal name
  //   set_name("scroll");

  // TODO: Set aliases with at least 3 alternate names
  //   set_alias(({"tattered scroll","old scroll","parchment",
  //     "ancient scroll"}));

  // TODO: Set a short description
  //   set_short("A Tattered Scroll");

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
  //   add_action("do_read", "read");

  return;
}

// TODO: Implement the read handler.
//   Return type: status (1 if handled, 0 if not)
//
// status do_read(string str)
// {
//   // Return 0 if str is missing or doesn't match this object.
//   // Use id(str) to check if the string matches our name/aliases.
//   if (!str || !id(str))
//     return 0;
//
//   // Display the scroll's contents using write().
//   // Include at least 5 lines of multi-line text.
//   write(
//     "You carefully unroll the brittle parchment and read:\n"
//     "\n"
//     "  Line one of the scroll text...\n"
//     "  Line two...\n"
//     "  Line three...\n"
//     "\n"
//     "The rest of the text is too faded to decipher.\n");
//   return 1;
// }
