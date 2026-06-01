/*
  ex03_readable.c
  Exercise 13.3 — Readable Items
  A room with a readable inscription using add_read() and a named
  callback function. Includes SCREENREAD support.
*/
#pragma strong_types
#include "../defs.h"
inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  // TODO: Set a short description

  // TODO: Set a long description that mentions a readable feature
  //   (e.g. a stone tablet, sign, or inscription)

  // TODO: Add an add_item() for the readable feature so players
  //   can examine it. Hint in the description that it can be read.

  // TODO: Add other add_item() entries for room features

  // TODO: Use add_read() with a callback reference to a function
  //   in this object. The @ prefix tells the driver to call the
  //   named function.
  //   Syntax: add_read(({"keywords"}), "@function_name");

  // TODO: Optionally add a search_item and an exit

  return;
}

// TODO: Implement the read callback function.
//   It takes no arguments and returns a string.
//
//   Include a SCREENREAD check:
//     if (TP && TP->query_property("SCREENREAD"))
//       return a plain text version (no ASCII art borders)
//     else
//       return a decorated version with borders
//
//   The returned string should be multi-line (at least 3 lines
//   of actual content).
