/* ex02_rm3.c / Mimic 260316 / Central chamber */

#pragma strong_types
#include "defs.h"

// Exercise 21.2, Area Layout: Room 3
// Central chamber connecting the corridor to the dead end.

inherit TRAINING_ROOM + "ex01_droom";

void create()
{
  ::create();

  set_short("A Central Chamber");
  set_long(
    "The corridor opens into a broad chamber with a vaulted "
    "ceiling. Four thick stone pillars support the roof, their "
    "surfaces carved with faded geometric patterns. The floor "
    "is paved with flat stones fitted tightly together. A "
    "passage leads west to the torchlit corridor, and a narrow "
    "opening to the north disappears into shadow."
  );

  add_item(
    ({"pillars", "stone pillars", "columns"}),
    "Four pillars of grey stone rise from floor to ceiling. "
    "Faded carvings of interlocking geometric shapes spiral "
    "up their surfaces, hinting at the skill of the original "
    "builders."
  );
  add_item(
    ({"floor", "stones", "paving"}),
    "The floor is paved with flat stones fitted so tightly "
    "that barely a seam shows between them. The craftsmanship "
    "is far superior to the rough corridors nearby."
  );

  add_exit(TRAINING_ROOM + "ex02_rm2", "west");
  add_exit(TRAINING_ROOM + "ex02_rm4", "north");

  return;
}
