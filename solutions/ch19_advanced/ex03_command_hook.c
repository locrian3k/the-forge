#pragma strong_types
#include "../defs.h"

// Exercise 19.3, Command Hook
// A forge room where players can craft a sword from an iron bar.

inherit "room/room";

void create()
{
  ::create();
  set_light(1);

  set_short("The Forge");
  set_long(
    "A sweltering workshop dominated by a roaring forge. "
    "Coals glow white-hot in the stone hearth, and an anvil "
    "of blackened iron stands nearby, its surface pitted from "
    "countless hammer blows. Racks of tongs and hammers line "
    "the walls."
  );

  add_item(
    ({"forge", "hearth", "coals", "fire"}),
    "A massive stone forge filled with white-hot coals. The "
    "heat radiating from it is almost unbearable."
  );
  add_item(
    ({"anvil", "iron anvil"}),
    "A heavy iron anvil, its flat surface scarred and pitted "
    "from years of use. This is where raw metal becomes weapons."
  );
  add_item(
    ({"tools", "tongs", "hammers", "racks"}),
    "Racks of forging tools hang on the walls: heavy hammers, "
    "long-handled tongs, and chisels of various sizes."
  );

  add_exit("/room/entrance", "south");

  return;
}

void init()
{
  ::init();

  // Register the "forge" command for players in this room
  add_action("do_forge", "forge");

  return;
}

// Handle the "forge" command.
// Usage: forge sword
// Requires an "iron bar" in the player's inventory.
int do_forge(string arg)
{
  object bar, sword;

  // Check for valid syntax
  if (!arg || arg != "sword")
  {
    notify_fail("Usage: forge sword\n");
    return 0;
  }

  // Check if the player has the required material
  bar = present("iron bar", TP);
  if (!bar)
  {
    notify_fail(
      "You need an iron bar to forge a sword. Find one and "
      "bring it here.\n"
    );
    return 0;
  }

  // Consume the iron bar
  destruct(bar);

  // Create the result weapon and give it to the player
  sword = clone_object("/obj/weapon");
  move_object(sword, TP);

  // Success messages
  write(
    "You thrust the iron bar into the coals and hammer it "
    "into shape on the anvil. Sparks fly as the metal sings "
    "under your blows. After much sweat and effort, you hold "
    "up a newly forged sword!\n"
  );

  // Room message, exclude the player who is forging
  tell_room(
    TO,
    sprintf(
      "%s works the forge with focused intensity, hammering "
      "an iron bar into a gleaming sword.\n",
      (string)TP->query_cap_name()
    ),
    ({TP})
  );

  return 1;
}
