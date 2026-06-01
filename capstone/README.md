# The Forge: Capstone Project

## Overview

The capstone is your chance to build a complete area from scratch, bringing
together everything you have learned across the curriculum. You will create
rooms, monsters, objects, a boss encounter, and interactive mechanics.

There are two tracks to choose from. Both follow the same 5 phases and
produce a fully playable area.

## Capstone Tracks

### Standard Area (capstone/standard/)

The standard track uses `/room/room` for all rooms and works on any LPC MUD.
You write a `base_room.c` inheritable that your interior rooms inherit from,
giving you shared descriptions, a direction blocker, and a clean foundation
to build on.

Choose this track if you have completed Chapters 1 through 19.

### Dungeon Area (capstone/dungeon/)

The dungeon track uses `/room/dungeon/dr.c` with `set_dungeon()` scaling,
which auto-adjusts monster stats and loot to the area's level. You write a
`droom.c` inheritable that your interior rooms inherit from, with dungeon
registration, shared descriptions, and helper functions for spawning.

Choose this track if you have completed Chapters 1 through 21 (Ch 20-21
cover dungeon scaling). This track is 3K-specific.

## The 5 Phases

Both tracks follow the same phases. The focus of each phase shifts slightly
depending on which track you chose.

| Phase | Name           | After Chapters | Standard Focus                        | Dungeon Focus                          |
|-------|----------------|----------------|---------------------------------------|----------------------------------------|
| 1     | The Foundation | Ch 1-9         | defs.h, entrance, base_room, layout   | defs.h, entrance, droom, layout        |
| 2     | Atmosphere     | Ch 10-14       | Items, searches, readables            | Items, searches, readables             |
| 3     | Combat         | Ch 15-17       | Monsters, weapons, armor              | Monsters, weapons, armor               |
| 4     | The Boss       | Ch 18-19       | Boss fight, unique drop, mechanics    | Boss fight, unique drop, mechanics     |
| 5     | Polish         | All chapters   | Integration, disease, paths, testing  | Integration, disease, paths, testing   |

## Area Requirements

A completed capstone area should have:

- 8+ rooms with distinct descriptions and atmosphere
- 2 branching paths that converge at the boss
- 3+ examinable items per room
- Searchable items and readable objects
- Multiple monster types that spawn on reset
- A boss with special mechanics (narrative death, timed abilities, or
  damage modification)
- A unique boss-drop item
- At least 1 disease or status effect
- Clean 3K codestyle throughout
- A playable, thematic experience

## Getting Started

1. Pick your track (standard or dungeon)
2. Read `phases/phase1.md` to begin
3. Use the starter templates in your chosen track folder as your foundation
4. Build, test, iterate, each phase builds on the last
5. Refer back to your chapter exercises whenever you need a refresher
