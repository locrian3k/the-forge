# Phase 4: The Boss

**Prerequisite:** Chapters 18-19 completed, Phases 1-3 complete
**Goal:** Create a boss encounter with special mechanics, a unique drop,
and an interactive boss room.

## Background

Every dungeon needs a climax. The Haunted Mine's boss is the **Foreman** —
the ghost of the mine's cruel overseer, bound to the deepest shaft by his
own greed and rage. This phase is about making a memorable fight with
mechanics that go beyond "kill monster, get loot."

## Requirements

### 1. Create `mon/foreman.c`, Boss Monster

The Foreman inherits from `/obj/super_monster` (or `/obj/complex_monster`
at minimum). This is the area's final challenge.

Requirements:
- Inherit `"obj/super_monster"`
- `set_name("the Foreman")`, `set_short()`, `set_long()`
- `set_level()`, higher than regular monsters (12-15 range)
- `set_alias()` with multiple keywords

**Special mechanics (implement at least 3):**

- **`modify_damage()`**, reduce incoming damage, add flavor text
  (e.g., "Your blade passes through the Foreman's spectral form!")
- **`monster_died()`**, narrative death sequence instead of just dropping
  dead. Tell a story: the ghost wails, the mine shakes, the spirit fades
- **`extra_look()`**, dynamic description that changes based on the
  Foreman's health (full health vs wounded vs near death)
- **Spells/special attacks**, `set_chance()`, `set_spell_dam()`,
  and/or `set_spell_mess1()`/`set_spell_mess2()` for themed attacks
  (ghostly chains, mine collapse, spectral pickaxe)
- **`load_chat()`**, boss-specific combat dialogue (threats, lore drops,
  taunts referencing the mine's history)

### 2. Create a Timed Mechanic

Implement at least one timed element using `call_out()` or `heart_beat()`.

Examples:
- The Foreman becomes invulnerable for 5 seconds, then drops his guard
  (use `call_out` to toggle a flag checked in `modify_damage`)
- The room periodically shakes (environmental messages via `heart_beat`)
- The boss enrages after a time limit, dealing increased damage
- A cave-in mechanic that blocks the exit temporarily

### 3. Create the Boss Room with Interactive Mechanics

The boss room (`rm7` or wherever you place the Foreman) should have an
interactive element using `add_action()` in `init()`.

Examples:
- A **lever** that must be pulled to weaken the Foreman's shield
- A **lantern** that must be lit to make the ghost vulnerable
- **Mine supports** that can be collapsed onto the boss
- A **ritual circle** that must be activated before the boss can be killed

Implementation pattern:
```lpc
void init()
{
  ::init();
  add_action("do_pull_lever", "pull");
  return;
}

status do_pull_lever(string arg)
{
  if (arg != "lever") return 0;
  // ... mechanic logic ...
  return 1;
}
```

The mechanic should affect the fight in a meaningful way, not just
flavor text, but an actual gameplay impact.

### 4. Create a Unique Boss Drop

The Foreman drops a unique weapon or armor when killed.

**Example: `obj/foreman_lantern.c`**
- Inherit `"obj/weapon"` or `"obj/armour"`
- Unique name, short, long description with lore
- Higher stats than the regular pickaxe/helmet from Phase 3
- At least one special feature:
  - `weapon_hits()`, bonus effects on hit (cold damage messages,
    chance to terrify, life drain flavor)
  - `wear_func()` / `remove_func()`, effects when equipped/removed
  - A custom ability via `add_action()` in `init()`

The boss drop should feel rewarding and thematic, a trophy from the
mine's final challenge.

### 5. Boss Spawning

The boss should spawn in its room via `reset()`. Since it is a super_monster,
make sure only one spawns at a time (use the `add_clone` duplicate
prevention flag).

## Deliverables

- [ ] `mon/foreman.c`, compiles, inherits super_monster
- [ ] Foreman has `modify_damage()` with flavor text
- [ ] Foreman has `monster_died()` with narrative death
- [ ] Foreman has `extra_look()` with health-based descriptions
- [ ] Foreman has spells or special attacks
- [ ] At least 1 timed mechanic (`call_out` or `heart_beat`)
- [ ] Boss room has `add_action()` interactive mechanic
- [ ] Interactive mechanic affects the fight meaningfully
- [ ] `obj/foreman_lantern.c` (or similar), unique boss drop with a
      special feature
- [ ] Boss spawns in its room via `reset()`

## Self-Check

Review your work against these criteria:

1. The Foreman inherits from `"obj/super_monster"`
2. `modify_damage()` uses the correct signature: `int modify_damage(int dam, string dam_type, int *att_wc)`
3. `monster_died()` uses `tell_room()` to narrate the death
4. `extra_look()` returns different strings based on health
5. The boss room has an `add_action()` mechanic in `init()`
6. At least one `call_out()` or `heart_beat()` timed mechanic exists
7. The unique boss drop has a special feature (`weapon_hits()`, `wear_func()`, etc.)
8. The boss spawns via `add_clone()` in `reset()` with duplicate prevention

When you become a wizard, you can test the full boss fight in-game
with `update`, `goto`, `kill`, and `exa` commands. For now, focus on
getting the code right.

## Hints

- `super_monster` gives you `int modify_damage(int dam, string dam_type, int *att_wc)`.
  Return the modified damage value. Return 0 to block all damage.
- `monster_died()` is called when the monster reaches 0 HP. Use
  `tell_room()` to narrate the death to everyone present.
- `extra_look()` should return a string that gets appended to the
  monster's look description.
- For timed invulnerability: set a status flag, check it in
  `modify_damage()`, use `call_out("end_invulnerable", 5)` to clear it.
- `weapon_hits()` is called every time the weapon deals damage, keep
  the special effect chance reasonable (1 in 3 or 1 in 5).
- Test the boss fight at the intended dungeon level to make sure it is
  challenging but not impossible.
