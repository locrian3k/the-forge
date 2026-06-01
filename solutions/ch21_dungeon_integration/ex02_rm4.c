/* ex02_rm4.c / Mimic 260316 / Dead end alcove */

#pragma strong_types
#include "defs.h"

// Exercise 21.2, Area Layout: Room 4
// A dead-end alcove at the northern end of the dungeon.

inherit TRAINING_ROOM + "ex01_droom";

void create()
{
  ::create();

  set_short("A Dead-End Alcove");
  set_long(
    "The passage terminates in a small alcove choked with "
    "fallen rubble. It looks like the ceiling partially "
    "collapsed here long ago, sealing off whatever lay beyond. "
    "Strange carvings are visible on the one intact wall. The "
    "only way out is south, back to the central chamber."
  );

  add_item(
    ({"rubble", "rocks", "debris"}),
    "A heap of broken stone and dust fills the far end of the "
    "alcove. Some pieces are massive, suggesting a significant "
    "collapse. Digging through would take serious effort."
  );
  add_item(
    ({"carvings", "wall", "strange carvings"}),
    "The one intact wall bears a series of carved symbols that "
    "might be a warning, a map, or simple decoration. Time has "
    "worn them too smooth to read clearly."
  );

  add_exit(TRAINING_ROOM + "ex02_rm3", "south");

  return;
}
