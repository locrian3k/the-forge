# Object Creation — Quick Reference

## Basic Object

```lpc
#pragma strong_types
#include "../defs.h"

inherit "obj/object";

void create()
{
  ::create();
  set_creator("mimic");
  set_name("crystal");
  set_alias(({"gem", "blue crystal"}));
  set_short("A shimmering blue crystal");
  set_long(
    "This crystal pulses with a faint blue light, warm to "
    "the touch."
  );
  set_value(150);
  set_weight(1);
  return;
}
```

## Treasure Object

```lpc
#pragma strong_types
#include "../defs.h"

inherit "obj/treasure";

void create()
{
  ::create();
  set_creator("mimic");
  set_name("goblin coin");
  set_alias(({"coin", "gold coin"}));
  set_short("A crudely stamped goblin coin");
  set_long("A misshapen gold coin with a goblin face on it.");
  set_value(50);
  set_weight(1);
  return;
}
```

## Core Functions

| Function | Description | Example |
|----------|-------------|---------|
| `set_creator(str)` | Builder name | `set_creator("mimic")` |
| `set_name(str)` | Primary id | `set_name("sword")` |
| `set_alias(arr)` | Additional ids | `set_alias(({"blade", "weapon"}))` |
| `set_short(str)` | Inventory listing | `set_short("A rusty sword")` |
| `set_long(str)` | Examine text | `set_long("Detailed description.")` |
| `set_value(n)` | Coin value | `set_value(200)` |
| `set_weight(n)` | Weight units | `set_weight(3)` |

## add_item (Examinable Details)

```lpc
add_item("runes",
  "Strange runes are etched along the blade."
);
add_item(({"hilt", "handle"}),
  "The hilt is wrapped in worn leather."
);
```

## id() Function

The driver calls `id(str)` to check if an object matches a name. The inherited `set_name` and `set_alias` handle this automatically. Override for special behavior:

```lpc
status id(string arg)
{
  if (arg == "special_token")
    return 1;
  return ::id(arg);
}
```

## Moving Objects

```lpc
// Clone and move to a room
object ob = clone_object(OBJ + "gem");
ob->move(room);

// Clone and move to a player
object ob = clone_object(OBJ + "potion");
ob->move(TP);
```

## Destroying Objects

```lpc
destruct(this_object());  // destroy self
destruct(ob);             // destroy another object
```

## Checking Object Properties

```lpc
string name = (string)ob->query_name();
int val = (int)ob->query_value();
string desc = (string)ob->query_short();
object env = environment(ob);
```

## Container Pattern

```lpc
// Check if something is inside an object
object item = present("gem", container_ob);
if (item)
  write("Found it!\n");

// List everything inside
object *contents = all_inventory(container_ob);
```

## Common Gotchas

- Always call `set_creator()` for proper attribution.
- `set_name()` is the primary `id()` match. Keep it simple (one word).
- Use `set_alias()` for alternative names players might type.
- `set_short()` appears in inventory lists, keep it brief.
- `set_long()` appears on `examine`, be descriptive.
- Uninitialized objects have no name and cannot be picked up or referenced.
