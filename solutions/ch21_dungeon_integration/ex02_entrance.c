/* ex02_entrance.c / Mimic 260316 / Outdoor entrance to the dungeon */

#pragma strong_types
#include "defs.h"

// Exercise 21.2, Area Layout: Entrance
// The entrance room is outdoors and uses /room/room, not the
// dungeon base room. Dungeon rooms are only for the interior.

inherit "room/room";

void create()
{
  ::create();

  set_light(1);
  set_short("Outside the Training Dungeon");
  set_long(
    "A well-worn path ends at the mouth of a cave set into a "
    "low hillside. The entrance is framed by rough-cut stone "
    "blocks, suggesting this was once a more formal structure. "
    "Weeds and moss have reclaimed the stonework, and a cool "
    "draft seeps from the darkness within. A faded sign is "
    "nailed to a post beside the entrance."
  );

  add_item(
    ({"path", "trail"}),
    "A dirt path, packed hard by many boots, leads up to the "
    "cave entrance from the south."
  );
  add_item(
    ({"trees", "forest"}),
    "Gnarled oaks and thick underbrush crowd the hillside on "
    "either side of the path."
  );
  add_item(
    ({"entrance", "cave", "mouth"}),
    "The cave entrance is wide enough for two people to walk "
    "abreast. Beyond the threshold, torchlight flickers against "
    "the walls."
  );
  add_item(
    ({"sign", "post"}),
    "A weathered wooden sign reads: 'Training Dungeon - Enter "
    "at your own risk.'"
  );

  // North leads into the dungeon proper
  add_exit(TRAINING_ROOM + "ex02_rm2", "north");

  return;
}
