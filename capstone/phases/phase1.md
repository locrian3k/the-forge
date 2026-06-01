# Phase 1: The Foundation

**Prerequisite:** Chapters 1-9 completed
**Goal:** Create the area skeleton, defines, entrance, base room, and 2
connected dungeon rooms.

## Background

Every area starts with its bones: the include chain, the entrance, and the
base inheritable room. In this phase you will set up the Haunted Mine's
directory structure and create the first rooms a player walks through.

## Requirements

### 1. Create `haunted_mine/defs.h`

Your area's header file wires into the global include chain and defines
path shortcuts used by every file in the area.

- Include the parent `defs.h` with `#include "../defs.h"`
- Define these path macros:
  - `HM`, base area path (e.g., `AREAS + "haunted_mine/"`)
  - `HM_ROOM`, rooms subdirectory (`HM + "rooms/"`)
  - `HM_ITEM`, objects subdirectory (`HM + "obj/"`)
  - `HM_MOBS`, monsters subdirectory (`HM + "mon/"`)
  - `DNAME`, dungeon name string: `"Haunted Mine"`

### 2. Create `haunted_mine/entrance.c`

The entrance is an outdoor room, the abandoned minehead on a hillside.
It does NOT use dungeon scaling (no `set_dungeon` call).

Requirements:
- `#pragma strong_types` as the first line
- `#include "defs.h"` and `inherit "room/dungeon/dr.c";`
- `set_light(1)`, it is outdoors
- `set_short()`, a brief room title
- `set_long()`, 2-3 sentences describing the abandoned mine entrance
- At least 3 `add_item()` calls for examinable details (the mine entrance,
  the hillside, old equipment, etc.)
- One exit going south to `HM_ROOM + "rm2"` (into the mine)

### 3. Create `haunted_mine/rooms/droom.c`

The base dungeon room that all mine rooms will inherit. This sets the
dungeon scaling and default atmosphere.

Requirements:
- `#pragma strong_types`, `#include "../defs.h"`, inherit dungeon room
- `set_dungeon(DNAME, 8, 1, 1, 1)`, level 8 dungeon
- `set_light(1)`
- At least 2 default `add_item()` calls that apply to every mine room
  (e.g., "tunnel", "walls", "floor", "darkness")
- A `set_block_message()` for invalid directions

### 4. Create `haunted_mine/rooms/rm2.c` and `rooms/rm3.c`

Two basic dungeon rooms that inherit from `droom.c`.

**rm2.c, Mine Entrance Hall:**
- Inherits `"droom"` (local inherit)
- `set_short()`, `set_long()`, describe the first room inside the mine
- At least 3 `add_item()` calls (old rails, support beams, dust, etc.)
- Exits: north to `entrance.c`, south to `rm3`

**rm3.c, The Junction:**
- Inherits `"droom"` (local inherit)
- `set_short()`, `set_long()`, a room where the tunnel splits
- At least 3 `add_item()` calls
- Exits: north to `rm2`, west (to future rm4), east (to future rm5)
  - For now, west and east can point to placeholder comments or simply
    be omitted until Phase 5

## Deliverables

- [ ] `haunted_mine/defs.h`, compiles without errors
- [ ] `haunted_mine/entrance.c`, loads, has short/long/items/exit
- [ ] `haunted_mine/rooms/droom.c`, compiles, sets dungeon scaling
- [ ] `haunted_mine/rooms/rm2.c`, loads, connects to entrance and rm3
- [ ] `haunted_mine/rooms/rm3.c`, loads, connects to rm2

## Self-Check

Before moving on, review your work against these criteria:

1. Each room has a `set_short()` and `set_long()` description
2. Every `add_item()` keyword has a description (no "You see nothing special")
3. Exits connect correctly (entrance -> rm2 -> rm3 and back)
4. rm2 and rm3 inherit from `droom.c` which sets dungeon scaling

When you become a wizard, you can test in-game with commands like
`update`, `goto`, and `exa`. For now, focus on getting the code right.

## Hints

- Look at the starter templates in the `standard/` and `dungeon/` capstone
  directories for scaffolding
- The entrance does NOT inherit droom, it inherits `"room/dungeon/dr.c"`
  directly (no dungeon scaling for the outdoor room)
- rm2 and rm3 inherit from the local `"droom"` file, not the full path
- For word-wrapped long descriptions, you can define helper macros in
  your defs.h: `#define str_f(str) sprintf("%-=72s\n", str)` and
  `#define set_long_f(str) set_long(str_f(str))` — these wrap text to
  72 columns so it reads well on any terminal
