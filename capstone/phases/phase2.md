# Phase 2: Atmosphere

**Prerequisite:** Chapters 10-14 completed, Phase 1 complete
**Goal:** Fill the mine with interactive details, searchable items,
readable objects, and treasure.

## Background

A dungeon is more than rooms and monsters. The details are what make a
place feel real. In this phase you add the sensory layer: things players
can search, read, and pick up. By the end, even without combat, a player
walking through the mine should feel the atmosphere of a haunted,
abandoned place.

## Requirements

### 1. Create 2+ Treasure Objects in `obj/`

Create at least two simple treasure objects. These are items players can
find and pick up.

**Example: `obj/silver_nugget.c`**
- Inherit `"obj/treasure"`
- `set_short()`, `set_long()`, `set_name()`, `set_alias()`, `set_weight()`
- `set_value()`, what it sells for
- Thematic to a mine (ore samples, old coins, gemstones, tools)

**Example: `obj/old_journal.c`**
- Inherit `"obj/treasure"` (or `"obj/object"`)
- Must be readable, implement `init()` with `add_action("do_read", "read")`
  and a `do_read()` function that prints journal entries
- Content should hint at the mine's backstory (the foreman, the collapse,
  the trapped miners)

### 2. Add `add_search_item()` to at Least 2 Rooms

Go back to your existing rooms and add searchable details. When a player
types `search <thing>`, they get a hidden detail.

Requirements:
- At least 2 different rooms must have `add_search_item()` calls
- Search results should reveal lore, atmosphere, or hint at secrets
- At least one search should clone a treasure into the room:
  ```lpc
  add_search_item("rubble",
    "Digging through the rubble, you find a glint of silver!",
    HM_ITEM + "silver_nugget");
  ```

### 3. Create 1 Readable Object or Room Feature

Implement a readable element using `add_read()`. This can be:
- A room feature (writing on a wall, a posted notice, carved runes)
- A portable object (the old journal, a crumpled note)

For room-based readables:
```lpc
add_item("sign", "An old wooden sign hangs crookedly on the wall.");
add_read("sign", "@read_sign");
```
Then define a `read_sign()` function returning the text.

The readable content should develop the mine's story, who worked here,
what happened, why they never came back.

### 4. Enrich Room Descriptions

Every room should now have at least 3 `add_item()` calls providing
examinable details. Go back through your Phase 1 rooms and add more if
needed.

Good mine atmosphere items:
- Support timbers, pit props, ceiling braces
- Mine cart tracks, ore carts, rusted rails
- Lanterns, candles, sconces (extinguished or flickering)
- Water (dripping, pooling, flowing)
- Air quality (stale, dusty, cold drafts)
- Evidence of the miners (tools, clothing, lunch pails)
- Evidence of the haunting (cold spots, whispers, shadows)

## Deliverables

- [ ] `obj/silver_nugget.c` (or similar treasure), loads, can be picked up
- [ ] `obj/old_journal.c` (or similar), loads, is readable
- [ ] At least 1 additional treasure object
- [ ] `add_search_item()` in at least 2 rooms
- [ ] At least 1 search that clones a treasure into the room
- [ ] `add_read()` on at least 1 room feature or object
- [ ] Every room has 3+ `add_item()` calls
- [ ] Readable content develops the mine's backstory

## Self-Check

Review your work against these criteria:

1. `search` calls have atmospheric or lore text
2. At least one `add_search_item()` has a third argument (file path) to clone treasure
3. `add_read()` calls have associated functions that return story content
4. All `add_item()` keywords have descriptions (no "You see nothing special")
5. Treasure objects have proper short/long/value/weight

When you become a wizard, you can test in-game with `search`, `read`,
and `exa` commands. For now, focus on getting the code right.

## Hints

- `add_search_item()` with a third argument (file path) will clone that
  object into the room when the player searches
- The `@function_name` syntax in `add_read()` calls a local function —
  define it to return a string
- Keep readable text interesting but concise; 3-5 sentences is ideal
  for a journal entry or wall inscription
- Think about what details a screenreader user would want, make sure
  your text descriptions are strong even without ASCII art
