# Weapon Creation — Quick Reference

## Basic Weapon (/obj/weapon)

```lpc
#pragma strong_types
#include "../defs.h"

inherit "obj/weapon";

void create()
{
  ::create();
  set_creator("mimic");
  set_name("shortsword");
  set_alias(({"sword", "short sword"}));
  set_short("A steel shortsword");
  set_long("A well-forged shortsword with a leather grip.");
  set_weight(3);
  set_value(100);
  set_class(12);  // weapon class (damage)
  set_type("sword");
  return;
}
```

## Super Weapon (/obj/super_weapon)

For weapons with special hit effects:

```lpc
#pragma strong_types
#include "../defs.h"

inherit "obj/super_weapon";

void create()
{
  ::create();
  set_creator("mimic");
  set_name("flame blade");
  set_alias(({"blade", "sword", "flame sword"}));
  set_short("A flame-wreathed blade");
  set_long("Fire dances along the edge of this blade.");
  set_weight(4);
  set_value(500);
  set_class(18);
  set_type("sword");
  set_wield_func("do_wield");
  set_unwield_func("do_unwield");
  set_hit_func("weapon_hits");
  return;
}
```

## Core Functions

| Function | Description | Example |
|----------|-------------|---------|
| `set_class(n)` | Weapon class (damage) | `set_class(15)` |
| `set_type(str)` | Weapon type | `set_type("sword")` |
| `set_hit_func(str)` | Hit callback name | `set_hit_func("weapon_hits")` |
| `set_wield_func(str)` | Wield callback name | `set_wield_func("do_wield")` |
| `set_unwield_func(str)` | Unwield callback | `set_unwield_func("do_unwield")` |
| `set_two_handed(n)` | Two-handed toggle | `set_two_handed(1)` |
| `query_two_handed()` | Check two-handed | `if (query_two_handed())` |

## Weapon Types

`"sword"`, `"axe"`, `"mace"`, `"staff"`, `"dagger"`, `"polearm"`,
`"whip"`, `"knife"`, `"club"`, `"flail"`, `"hands"`

## weapon_hits() — Hit Function

Returns a 10-element array. Called each combat round.

```lpc
mixed *weapon_hits(object target)
{
  return ({
    0,                     // [0] extra damage (int)
    "",                    // [1] damage type (string)
    0,                     // [2] TP message override
    0,                     // [3] target message override
    0,                     // [4] room message override
    0,                     // [5] unused
    0,                     // [6] unused
    0,                     // [7] unused
    0,                     // [8] unused
    0,                     // [9] unused
  });
}
```

### Hit Function Examples

```lpc
// Simple extra fire damage
mixed *weapon_hits(object target)
{
  if (random(100) < 25)  // 25% chance
  {
    tell_object(TP, "Your blade erupts in flame!\n");
    tell_object(target, "You are scorched by fire!\n");
    return ({ 20 + random(30), "fire", 0, 0, 0, 0, 0, 0, 0, 0 });
  }
  return ({ 0, "", 0, 0, 0, 0, 0, 0, 0, 0 });
}

// Life steal
mixed *weapon_hits(object target)
{
  if (random(100) < 15)
  {
    int heal = 10 + random(20);
    TP->heal_self(heal);
    tell_object(TP, "Dark energy flows into you!\n");
    return ({ heal, "shadow", 0, 0, 0, 0, 0, 0, 0, 0 });
  }
  return ({ 0, "", 0, 0, 0, 0, 0, 0, 0, 0 });
}
```

## Wield / Unwield Functions

```lpc
status do_wield()
{
  if ((int)TP->query_level() < 10)
  {
    write("You are too inexperienced to wield this weapon.\n");
    return 0;  // prevent wielding
  }
  write("The blade hums as you grip the hilt.\n");
  return 1;    // allow wielding
}

status do_unwield()
{
  write("The blade falls silent.\n");
  return 1;    // allow unwielding
}
```

## Two-Handed Weapons

```lpc
set_two_handed(1);  // requires both hands, no shield
```

## Damage Type Strings

Common damage types for the hits array element [1]:
`"fire"`, `"ice"`, `"lightning"`, `"shadow"`, `"holy"`,
`"poison"`, `"acid"`, `"physical"`, `"energy"`
