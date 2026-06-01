# Armor Creation — Quick Reference

## Basic Armor

```lpc
#pragma strong_types
#include "../defs.h"

inherit "obj/armour";

void create()
{
  ::create();
  set_creator("mimic");
  set_name("chainmail");
  set_alias(({"mail", "chain mail", "armor"}));
  set_short("A suit of chainmail");
  set_long("Interlocking iron rings form this sturdy armor.");
  set_weight(5);
  set_value(200);
  set_ac(({ 0, 0, 0, 0, 8, 0, 0, 0, 0, 0 }));
  set_type("body armour");
  return;
}
```

## Core Functions

| Function | Description | Example |
|----------|-------------|---------|
| `set_ac(arr)` | Armor class (10-element array) | `set_ac(({0,0,0,0,8,0,0,0,0,0}))` |
| `set_type(str)` | Armor slot type | `set_type("helmet")` |
| `set_wear_func(str)` | Wear callback name | `set_wear_func("do_wear")` |
| `set_remove_func(str)` | Remove callback name | `set_remove_func("do_remove")` |

## AC Array (10 Elements)

The AC array provides protection against different damage types:

```lpc
set_ac(({
  0,   // [0] slash
  0,   // [1] pierce
  0,   // [2] bludgeon
  0,   // [3] unused
  8,   // [4] general AC (most common to set)
  0,   // [5] magic
  0,   // [6] fire
  0,   // [7] cold
  0,   // [8] electric
  0,   // [9] poison/acid
}));
```

For simple armor, set element [4] (general AC). For specialized armor, set specific resistances.

```lpc
// Simple: just general AC
set_ac(({ 0, 0, 0, 0, 5, 0, 0, 0, 0, 0 }));

// Fire-resistant armor
set_ac(({ 0, 0, 0, 0, 5, 0, 4, 0, 0, 0 }));

// Magic-resistant cloak
set_ac(({ 0, 0, 0, 0, 2, 6, 0, 0, 0, 0 }));
```

## Armor Types

| Type | Slot | Example |
|------|------|---------|
| `"body armour"` | Torso | Chainmail, plate, robe |
| `"helmet"` | Head | Helm, crown, hood |
| `"glove"` | Hands | Gauntlets, gloves |
| `"boot"` | Feet | Boots, sandals |
| `"cloak"` | Back | Cloak, cape |
| `"shield"` | Off-hand | Buckler, tower shield |
| `"ring"` | Finger | Ring of protection |
| `"amulet"` | Neck | Amulet, necklace |

Only one item per slot. Shields conflict with two-handed weapons.

## Wear / Remove Functions

```lpc
status do_wear()
{
  if ((int)TP->query_level() < 5)
  {
    write("You lack the skill to wear this armor.\n");
    return 0;  // prevent wearing
  }
  write("The chainmail settles over your shoulders.\n");
  return 1;    // allow wearing
}

status do_remove()
{
  write("You remove the chainmail with a rattle of rings.\n");
  return 1;    // allow removing
  // return 0 to prevent removal (cursed armor!)
}
```

### Cursed Armor Example

```lpc
status do_remove()
{
  write("The armor tightens around you! It won't come off!\n");
  return 0;  // cannot remove
}
```

## Full Example with Effects

```lpc
#pragma strong_types
#include "../defs.h"

inherit "obj/armour";

void create()
{
  ::create();
  set_creator("mimic");
  set_name("frost helm");
  set_alias(({"helm", "helmet", "frost helmet"}));
  set_short("A frost-rimed helmet");
  set_long(
    "Ice crystals coat this steel helmet, radiating a "
    "supernatural chill."
  );
  set_weight(2);
  set_value(350);
  set_ac(({ 0, 0, 0, 0, 4, 0, 0, 3, 0, 0 }));
  set_type("helmet");
  set_wear_func("do_wear");
  set_remove_func("do_remove");
  return;
}

status do_wear()
{
  write("A biting cold seeps into your skull as you don the helm.\n");
  say((string)TP->query_name() + " puts on a frost-rimed helmet.\n");
  return 1;
}

status do_remove()
{
  write("Warmth floods back as you remove the helm.\n");
  return 1;
}
```
