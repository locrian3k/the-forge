#pragma strong_types
#include "../defs.h"

// Exercise 18.2, Area Layout: Entrance
// The outdoor entrance to the Training Grounds area.

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  set_short("Outside the Training Grounds");
  set_long(
    "A well-worn dirt path leads to a stone archway set into "
    "the hillside. Carved runes frame the entrance, their edges "
    "softened by years of wind and rain. A wooden sign post "
    "stands beside the path."
  );

  // Examinable scenery
  add_item(
    ({"archway", "arch", "entrance", "stone archway"}),
    "A sturdy stone archway marks the entrance to the Training "
    "Grounds. The runes carved into it read: 'Enter. Learn. Survive.'"
  );
  add_item(
    ({"sign", "sign post", "post", "wooden sign"}),
    "A weathered wooden sign reads: 'Training Grounds — Level 5. "
    "Beginners welcome. Survivors optional.'"
  );
  add_item(
    ({"runes", "carvings"}),
    "Ancient runes of protection line the archway, though some "
    "have faded to mere scratches in the stone."
  );

  // Exit north into the area
  add_exit(TRAINING_ROOM + "rm2", "north");

  return;
}
