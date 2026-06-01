#pragma strong_types
#include "../defs.h"

// A dusty storeroom - corrected to 3K codestyle.
// Fixes applied:
//   1. Added #pragma strong_types as first line
//   2. Replaced all tabs with 2-space indentation
//   3. Allman bracket style (opening { on its own line)
//   4. Added return; at end of all void functions
//   5. Changed int is_lit to status is_lit (boolean value)
//   6. Renamed camelCase to lowercase_underscore
//   7. Wrapped long lines to stay under 80 characters
//   8. Added ::create() call in create()
//   9. Single spacing between sentences in all strings

inherit "room/room";

// Room state: is the lantern lit?
status is_lit;

// Room description stored for reference
string long_description;

void create()
{
  ::create();
  set_short("A dusty storeroom");
  long_description =
    "You stand in a cramped storeroom. Dusty shelves "
    "line the walls from floor to ceiling, packed with "
    "jars of preserved herbs and bundles of dried "
    "mushrooms. A single lantern flickers on a hook "
    "near the low doorway to the north.";
  set_long(long_description);
  is_lit = 1;
  set_exits( ([ "north" : ROOMS + "hallway" ]) );
  add_item("shelves",
    "Rough wooden shelves sag under the weight of "
    "countless jars and bundles. They look like they "
    "have been here for decades.");
  add_item("lantern",
    "A battered brass lantern. Its flame dances "
    "behind a cracked glass pane.");
  return;
}

// Query whether the lantern is currently lit.
status query_lit()
{
  return is_lit;
}

// Extinguish the lantern, plunging the room into darkness.
void do_extinguish()
{
  if (is_lit)
  {
    is_lit = 0;
    write("You snuff out the lantern. The room "
      "plunges into darkness.");
  }
  else
    write("The lantern is already out.");
  return;
}
