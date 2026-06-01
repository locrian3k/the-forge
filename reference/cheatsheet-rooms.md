# Room Creation — Quick Reference

## Basic Room

```lpc
#pragma strong_types
#include "../defs.h"

inherit "room/room";

void create()
{
  ::create();
  set_short("A dusty corridor");
  set_long(
    "A narrow stone corridor stretches before you, dust motes "
    "drifting lazily in the dim light. Cobwebs cling to the "
    "corners of the low ceiling."
  );
  set_light(1);
  add_exit("north", ROOMS + "rm2");
  add_exit("south", ROOMS + "rm1");
  return;
}
```

## Dungeon Room

```lpc
#pragma strong_types
#include "../defs.h"

inherit DROOM;

void create()
{
  ::create();
  set_short("A goblin den");
  set_long("A filthy den where goblins gather.");
  set_light(1);
  set_dungeon(DNAME, 8, 1, 1, 1);
  // args: name, level, scale_hp, scale_damage, scale_exp
  add_exit("east", ROOMS + "rm3");
  return;
}
```

## Core Room Functions

| Function | Description | Example |
|----------|-------------|---------|
| `set_short(str)` | One-line room name | `set_short("A dark cave")` |
| `set_long(str)` | Full description | `set_long("Detailed text...")` |
| `set_light(n)` | Light level (0=dark, 1=lit) | `set_light(1)` |
| `add_exit(dir, path)` | Add an exit | `add_exit("north", ROOMS+"rm2")` |
| `set_dungeon(name, lvl, h, d, x)` | Dungeon scaling | `set_dungeon(DNAME, 8, 1, 1, 1)` |

## Items (Examinable Details)

```lpc
add_item("cobwebs",
  "Thick cobwebs stretch between the pillars, suggesting "
  "nothing has disturbed this place in years."
);
add_item(({"walls", "stone walls"}),
  "The walls are rough-hewn granite, slick with moisture."
);
```

Array of aliases lets multiple words show the same description.

## Search Items

```lpc
add_search_item("rubble", 1,
  "You search through the rubble and find a glinting gem!",
  0,  // search function (0 for none)
  OBJ + "gem"  // object to clone on success
);
```

Args: id, searches_allowed, success_message, search_func, clone_path

## Read Items

```lpc
add_read("sign",
  "The sign reads: 'Beware! Goblins beyond this point.'"
);
```

Player uses `read sign` to see the text.

## Spawning Monsters

```lpc
void reset()
{
  ::reset();
  add_clone(MON + "goblin");      // one goblin
  add_clone(MON + "goblin", 3);   // up to 3 goblins
  return;
}
```

`add_clone` only spawns if the room has fewer than the specified count.

> **Note:** Common macros like `TP`, `TO`, `ETO`, `ROOMS`, `MON`, `OBJ` are
> defined in `defs.h` -- see the Preprocessor cheatsheet for the full list.

## Interactive Features (add_action)

```lpc
void init()
{
  ::init();
  add_action("do_pull", "pull");
  return;
}

status do_pull(string arg)
{
  if (arg != "lever")
    return 0;
  write("You pull the lever. A hidden door opens!\n");
  say((string)TP->query_name() + " pulls a lever.\n");
  // do something
  return 1;
}
```

## Exits with Conditions

```lpc
add_exit("north", ROOMS + "rm_secret", 0, "check_access");

status check_access()
{
  if (!present("gold_key", TP))
  {
    write("The door is locked. You need a key.\n");
    return 1;  // 1 = blocked
  }
  return 0;  // 0 = allowed
}
```

## Common Patterns

```lpc
// Room with everything
void create()
{
  ::create();
  set_short("A forge room");
  set_long("A blazing forge dominates the room.");
  set_light(1);
  set_dungeon(DNAME, 8, 1, 1, 1);
  add_item("forge", "The forge burns with intense heat.");
  add_item("anvil", "A heavy iron anvil sits near the forge.");
  add_exit("south", ROOMS + "rm1");
  add_exit("east", ROOMS + "rm3");
  return;
}

void init()
{
  ::init();
  add_action("do_forge", "forge");
  return;
}

void reset()
{
  ::reset();
  add_clone(MON + "blacksmith");
  return;
}
```
