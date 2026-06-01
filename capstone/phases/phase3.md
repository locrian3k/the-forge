# Phase 3: Combat

**Prerequisite:** Chapters 15-17 completed, Phases 1-2 complete
**Goal:** Populate the mine with enemies, weapons, and armor.

## Background

The Haunted Mine has atmosphere, but no danger. In this phase you bring
the mine to life (or unlife) with monsters, equippable loot, and combat
encounters. You will create a base monster inheritable, specific enemy
types, and equipment for players to find.

## Requirements

### 1. Create `mon/hm_mob.c`, Base Monster Inheritable

A shared base file that all Haunted Mine monsters inherit from. This
keeps common setup in one place.

Requirements:
- Inherit `"obj/monster"`
- In `create()`, set baseline properties that all mine monsters share:
  - `set_race()`, a default race (can be overridden by children)
  - `set_alignment()`, evil or chaotic
  - `set_gender()`, random or fixed
  - `set_chance()` and `set_spell_dam()` if desired
- Include a helper function or shared `load_chat()` messages that
  children can extend

### 2. Create 2+ Monster Types

Create at least two distinct monster files that inherit from `hm_mob.c`.

**Example: `mon/ghost_miner.c`**
- Inherit `"hm_mob"`
- `set_name("ghost miner")`, `set_short()`, `set_long()`
- `set_level()` appropriate for a level 8 dungeon (6-10 range)
- `load_chat(3, ...)` with at least 3 atmospheric chat messages
  (ghostly moans, whispered warnings, rattling chains)
- `set_alias()` with multiple keywords (`({"ghost", "miner", "spirit"})`)

**Example: `mon/cave_spider.c`**
- Inherit `"hm_mob"`
- Different theme, a natural hazard rather than undead
- Its own `load_chat()` messages (skittering, hissing, web-spinning)
- Different level than the ghost miner (variety in difficulty)

Each monster must have:
- Unique name, short, long description
- `load_chat()` with 3+ messages
- `set_alias()` with multiple keywords
- A level appropriate for the dungeon

### 3. Create 1 Weapon and 1 Armor in `obj/`

**Weapon example: `obj/rusty_pickaxe.c`**
- Inherit `"obj/weapon"`
- `set_short()`, `set_long()`, `set_name()`, `set_alias()`, `set_weight()`
- `set_class()`, damage class appropriate for the dungeon level
- `set_type()`, weapon type ("club", "axe", etc.)
- `set_value()`

**Armor example: `obj/miners_helmet.c`**
- Inherit `"obj/armour"`
- `set_short()`, `set_long()`, `set_name()`, `set_alias()`, `set_weight()`
- `set_ac()`, armor class appropriate for the dungeon level
- `set_type()`, armor slot ("helmet", "armour", "shield", etc.)
- `set_value()`

### 4. Spawn Monsters in Rooms via `reset()`

Update your dungeon rooms to spawn monsters when the room resets.

In `droom.c` or individual rooms, add `reset()` with `add_clone()`:
```lpc
void reset()
{
  ::reset();
  add_clone(HM_MOBS + "ghost_miner", 1, 0, 1);
  return;
}
```

Or create helper functions in `droom.c` (like the Horde's `addc()`):
```lpc
varargs object *addc(string x, int y)
{
  return add_clone(sprintf("%s%s", HM_MOBS, x), (y ? y : 1), 0, 1);
}
```

Requirements:
- At least 2 rooms should spawn monsters on reset
- Different rooms can spawn different monster types
- Use the 4th argument to `add_clone()` (set to 1) to prevent duplicates

## Deliverables

- [ ] `mon/hm_mob.c`, compiles, sets shared monster properties
- [ ] `mon/ghost_miner.c`, loads, has name/short/long/chat/level
- [ ] `mon/cave_spider.c` (or similar), loads, distinct from ghost_miner
- [ ] `obj/rusty_pickaxe.c` (or similar weapon), equippable, correct type
- [ ] `obj/miners_helmet.c` (or similar armor), equippable, correct slot
- [ ] At least 2 rooms spawn monsters via `reset()`/`add_clone()`
- [ ] All monsters have `load_chat()` with 3+ messages

## Self-Check

Review your work against these criteria:

1. Every monster has `set_name()`, `set_alias()`, `set_short()`, `set_long()`, `set_level()`
2. Every monster has `load_chat()` with 3+ messages
3. Monster levels are in the 6-10 range for a level 8 dungeon
4. Weapon has `set_class()` and `set_type()`
5. Armor has `set_ac()` and `set_type()`
6. At least 2 rooms call `add_clone()` in `reset()`

When you become a wizard, you can test in-game with `update`, `goto`,
`kill`, and `reset` commands. For now, focus on getting the code right.

## Hints

- The `load_chat(chance, ({...}))` function takes a 1-in-N chance and an
  array of message strings, messages display during combat rounds
- `add_clone(path, count, 0, 1)`, the last argument (1) means "only
  clone if not already present," preventing monster stacking on reset
- Keep monster levels in the 6-10 range for a level 8 dungeon; the
  dungeon scaling will adjust them for the player
- Chat messages are a great place for lore: a ghost miner might whisper
  about the foreman, the collapse, or beg players to leave
