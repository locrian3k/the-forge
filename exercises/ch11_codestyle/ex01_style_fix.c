/*
  ex01_style_fix.c
  YourName YYMMDD
  Exercise 11.1 — Style Correction
  This room file compiles but violates 3K codestyle in many ways.
  Find and fix all 9+ violations listed in the chapter.

  Violations to find:
    1. Missing #pragma strong_types as the very first line
    2. Tab characters used for indentation (should be 2-space indent)
    3. K&R bracket style (opening { on same line as statement)
    4. Missing return; at the end of void functions
    5. int used where status would be correct (true/false value)
    6. camelCase variable names instead of lowercase_underscore
    7. Lines exceeding 80 characters
    8. Missing ::create() call in create()
    9. Double-spacing between sentences in strings (should be single)
*/
#include "../defs.h"

inherit "room/room";

int isLit;
string longDescription;

void create() {
	set_short("A dusty storeroom");
	longDescription = "You stand in a cramped storeroom.  Dusty shelves line the walls from floor to ceiling, packed with jars of preserved herbs and bundles of dried mushrooms.  A single lantern flickers on a hook near the low doorway to the north.";
	set_long(longDescription);
	isLit = 1;
	set_exits( ([ "north" : ROOMS + "hallway" ]) );
	add_item("shelves", "Rough wooden shelves sag under the weight of countless jars and bundles.  They look like they have been here for decades.");
	add_item("lantern", "A battered brass lantern.  Its flame dances behind a cracked glass pane.");
}

int query_lit() {
	return isLit;
}

void do_extinguish() {
	if (isLit == 1) {
		isLit = 0;
		write("You snuff out the lantern.  The room plunges into darkness.");
	} else {
		write("The lantern is already out.");
	}
}
