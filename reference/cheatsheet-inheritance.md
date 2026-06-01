# LPC Inheritance — Quick Reference

## Basic Inherit

```lpc
#pragma strong_types
#include "defs.h"

inherit "obj/weapon";

void create()
{
  ::create();
  set_name("sword");
  return;
}
```

## :: Operator (Call Parent)

```lpc
void create()
{
  ::create();          // call the inherited create()
  // your setup here
  return;
}

void init()
{
  ::init();            // always call parent init
  add_action("do_pull", "pull");
  return;
}
```

## Multiple Inheritance

```lpc
inherit "std/object";
inherit "std/container";

void create()
{
  "/std/object"::create();
  "/std/container"::create();
  return;
}
```

When multiple parents define the same function, specify which to call with `"path"::func()`.

## Overriding Functions

```lpc
inherit "obj/monster";

// Override the parent's monster_died
void monster_died()
{
  // custom death behavior
  tell_room(ETO, "The beast explodes!\n");
  ::monster_died();  // optionally call parent version
  return;
}
```

## nomask — Prevent Override

```lpc
// In parent:
nomask int query_level() { return level; }

// In child: COMPILE ERROR if you try to override
```

## virtual Inheritance

Solves the diamond problem, ensures only one copy of a shared ancestor:

```lpc
virtual inherit "std/base";
```

```
    /std/base
    /       \
  /obj/a   /obj/b     <-- both virtual inherit /std/base
    \       /
    my_object          <-- only ONE copy of /std/base
```

## Common Inheritance Paths

| Object type     | Inherit from                  |
|-----------------|-------------------------------|
| Room            | `/room/room`                  |
| Dungeon room    | `/room/dungeon/dr`            |
| Weapon          | `/obj/weapon`                 |
| Super weapon    | `/obj/super_weapon`           |
| Armor           | `/obj/armour`                 |
| Monster         | `/obj/monster`                |
| Complex monster | `/obj/complex_monster`        |
| Super monster   | `/obj/super_monster`          |
| Generic object  | `/obj/object`                 |
| Treasure        | `/obj/treasure`               |

## Checking Inheritance

```lpc
// From outside
if (ob->id("weapon"))
  write("It's a weapon.\n");

// Check if an object inherits a specific file
if (inherits("/obj/weapon", ob))
  write("It inherits weapon.\n");
```

## Gotchas

- Always call `::create()` first in your `create()`.
- Always call `::init()` first in your `init()`.
- If you forget `::create()`, the parent's setup never runs.
- `private` functions in the parent cannot be called with `::`.
- `protected` functions can be called with `::` from children.
- Multiple inheritance with conflicting function names requires explicit `"path"::func()` calls.
