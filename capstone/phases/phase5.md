# Phase 5: Polish

**Prerequisite:** All chapters completed, Phases 1-4 complete
**Goal:** Tie everything together into a complete, polished dungeon area
with branching paths, a disease mechanic, full monster spawning, and
clean code.

## Background

You have built the pieces. Now you connect them into a whole. This phase
is about finishing the area: filling in the remaining rooms, creating
two distinct paths to the boss, adding a disease effect, ensuring every
room spawns appropriately, and cleaning up your code to pass codestyle
checks.

## Requirements

### 1. Minimum 8 Rooms Total

Your area must have at least 8 rooms:
- `entrance.c`, outdoor entrance (already built)
- `rooms/rm2.c`, Mine Entrance Hall (already built)
- `rooms/rm3.c`, The Junction (already built)
- `rooms/rm4.c`, Flooded Tunnel (west path)
- `rooms/rm5.c`, Collapsed Gallery (east path)
- `rooms/rm6.c`, The Deep Shaft (paths converge)
- `rooms/rm7.c`, The Foreman's Office / boss room (already built)
- 1+ additional room(s), your choice

Each new room needs: short, long, 3+ add_item, exits, and atmospheric
details consistent with its theme.

**rm4, Flooded Tunnel:**
- Water-themed: ankle-deep water, dripping ceiling, slippery footing
- Natural hazards: cave spiders, slime

**rm5, Collapsed Gallery:**
- Rubble-themed: fallen timbers, crushed ore carts, unstable ceiling
- Undead hazards: ghost miners, cold spots, whispers

**rm6, The Deep Shaft:**
- Where both paths meet. A vertical shaft descending into darkness.
- Transition room before the boss: ominous, foreboding

### 2. Two Branching Paths to the Boss

From rm3 (The Junction), there must be two distinct routes to reach
rm6 (The Deep Shaft):
- **West path:** rm3 -> rm4 -> rm6
- **East path:** rm3 -> rm5 -> rm6

Each path should have a different feel and different enemies. Players
can choose their route. You may add extra rooms to either branch to
extend the dungeon.

### 3. At Least 1 Disease/Status Effect

Create a disease object in `obj/disease/`.

**Example: `obj/disease/mine_dust.c`**
- Inherit `"obj/disease"` (or your MUD's disease base)
- `set_name()`, `set_short()`, `set_alias()`
- `set_filename()` pointing to the actual file path
- Periodic damage or stat reduction (coughing, wheezing, reduced vision)
- `set_heal_msg()`, `set_catch_msg()`, `set_damage()`
- Applied by a monster attack, room hazard, or search result

The disease should be thematic: mine dust in the lungs, ghostly chill,
spider venom, cave damp.

Apply the disease through one of:
- A monster's attack (in `heart_beat()` or spell)
- A room hazard (searching something dangerous)
- An environmental trigger (entering a specific room)

### 4. `reset()` Spawning in All Combat Rooms

Every room that should have monsters must spawn them via `reset()`.

Requirements:
- At least 4 rooms spawn monsters on reset
- Use `add_clone(path, count, 0, 1)` to prevent duplicate spawning
- Different rooms should spawn different monster types where appropriate:
  - Flooded tunnel: cave spiders
  - Collapsed gallery: ghost miners
  - Deep shaft: mix of both
  - Boss room: the Foreman only

### 5. All Files Pass 3K Codestyle

Review every file in your area for codestyle compliance:

- [ ] `#pragma strong_types` as the first line of every `.c` file
- [ ] `#include "defs.h"` (with correct relative path for subdirs)
- [ ] Spaces only, no tabs, 2-space indentation
- [ ] Allman bracket style (opening `{` on its own line)
- [ ] `void` functions end with explicit `return;`
- [ ] `status` type for boolean values
- [ ] `lowercase_underscore` naming throughout
- [ ] Lines under 80 characters where possible
- [ ] Comments explaining non-obvious logic
- [ ] File structure: pragma, include, defines, inherit, globals,
      prototypes, create(), init(), reset(), other functions

### 6. Area README

Write a brief description of your area that could be shown to other
players. Include:
- The theme/story (2-3 sentences)
- Recommended level range
- Number of rooms
- Notable features (boss, unique loot, branching paths)

This can be a comment block at the top of `entrance.c` or a separate
text file.

## Final Checklist

### Structure
- [ ] `defs.h` with correct include chain and all path defines
- [ ] `entrance.c`, outdoor room, no dungeon scaling
- [ ] `rooms/droom.c`, base inheritable, dungeon level 8
- [ ] 7+ dungeon rooms (rm2 through rm7+)
- [ ] 2 branching paths converging at the boss

### Objects
- [ ] 2+ treasure objects in `obj/`
- [ ] 1+ readable object or room feature
- [ ] 1 regular weapon in `obj/`
- [ ] 1 regular armor in `obj/`
- [ ] 1 unique boss drop with special feature
- [ ] 1 disease in `obj/disease/`

### Monsters
- [ ] `mon/hm_mob.c` base inheritable
- [ ] 2+ regular monster types with `load_chat()`
- [ ] 1 boss (super_monster) with modify_damage, monster_died,
      extra_look, spells, timed mechanic

### Rooms
- [ ] 8+ total rooms
- [ ] Every room: short, long, 3+ add_item
- [ ] 2+ rooms with add_search_item
- [ ] 1+ room with add_read
- [ ] 4+ rooms spawn monsters via reset()
- [ ] Boss room has interactive add_action mechanic

### Code Quality
- [ ] All files follow 3K codestyle
- [ ] No compilation errors
- [ ] No runtime errors during play
- [ ] Area README/description written

## Self-Check

Final review of your complete area:

1. All rooms have short, long, and 3+ `add_item()` calls
2. Exits form two complete paths: entrance -> rm2 -> rm3 -> rm4 -> rm6 -> rm7
   and entrance -> rm2 -> rm3 -> rm5 -> rm6 -> rm7
3. At least 4 rooms spawn monsters via `reset()`/`add_clone()`
4. The disease object has `set_filename()` pointing to its actual file path
5. All files follow 3K codestyle (pragma, includes, Allman braces, etc.)
6. No compilation errors in any file

When you become a wizard, do a full playthrough: walk both paths,
search items, read features, fight monsters, contract the disease,
defeat the Foreman, and check the game log for errors.

## Congratulations

You have built a complete dungeon area from scratch, rooms, atmosphere,
combat, a boss encounter, and polish. This is everything a 3Kingdoms
area needs to be playable and enjoyable. You now have the skills to
build any area you can imagine.

Welcome to the ranks of 3Kingdoms area builders.
