# LPC / MUD Glossary

## Object Model

**Blueprint**, The master copy of an object loaded from a `.c` file. There is only one blueprint per file. You get it with `find_object()` or `load_object()`.

**Clone**, A copy of a blueprint created with `clone_object()`. Each clone is independent. Weapons, armor, monsters are clones. Rooms are usually blueprints.

**Living**, Any object that has been set as a "living" thing (monsters, players). Can engage in combat, have HP, carry inventory. Test with `living(ob)`.

**Non-living**, Objects that are not living: weapons, armor, treasures, rooms. They exist but do not fight or act autonomously.

**Environment**, The object that contains another object. A player's environment is the room they are in. A sword's environment is the player carrying it. Get with `environment(ob)`.

**Inventory**, The objects contained within an object. A room's inventory includes players and items on the ground. A player's inventory is everything they carry. Get with `all_inventory(ob)`.

**this_object()**, The object that is executing the current code. Abbreviated `TO` in 3K defines.

**this_player()**, The player who triggered the current action chain. Abbreviated `TP` in 3K defines.

## Function Types

**efun** (external function), Built into the driver. Available everywhere. Examples: `write()`, `clone_object()`, `tell_room()`, `random()`.

**lfun** (local function), Defined in your `.c` file. Only directly callable within that object (or via `->` / `call_other` from outside).

**sefun** (simulated efun), Defined in the mudlib but available everywhere like an efun. Examples: `capitalize()`, various utility functions.

**apply**, A function the driver calls on objects at specific times. You define them; the driver invokes them. Examples: `create()`, `init()`, `reset()`, `heart_beat()`.

## Architecture

**Driver**, The C program (LDMud) that runs the MUD. Handles networking, memory, compiling LPC, calling applies, scheduling.

**Mudlib**, The LPC code library that defines how the MUD world works. Includes base objects, rooms, combat system, commands.

**Realm**, A builder's assigned area within the MUD. Contains rooms, objects, monsters that form a thematic zone.

**Daemon**, A persistent object that provides services (login daemon, combat daemon, mail daemon). Usually a blueprint, not cloned.

## Combat Terms

**WC** (Weapon Class), A weapon's damage rating. Set with `set_class()`. Higher = more damage.

**AC** (Armor Class), An armor's protection rating. Set with `set_ac()`. Higher = more protection.

**HP** (Hit Points), Health. When a living reaches 0 HP, it dies.

**SP** (Spell Points), Mana/magic energy used to cast spells.

**GP** (Guild Points), Energy used for guild-specific abilities.

## Object Properties

**Short description**, One-line text shown in room listings and inventory. Set with `set_short()`.

**Long description**, Full text shown when a player examines something. Set with `set_long()`.

**Name**, The primary identifier used by `id()` checks. Set with `set_name()`.

**Alias**, Additional names an object responds to. Set with `set_alias()`.

**Value**, Coin worth for selling. Set with `set_value()`.

**Weight**, Encumbrance units. Set with `set_weight()`.

## Room Terms

**Exit**, A connection from one room to another. Added with `add_exit()`.

**Item**, An examinable detail in a room or object description (not a physical object). Added with `add_item()`.

**Light level**, Whether a room is visible. 0 = dark (cannot see), 1+ = lit.

## MUD Concepts

**Heartbeat**, A periodic function call (~2 seconds) on objects with `set_heart_beat(1)`. Used for ongoing effects.

**Reset**, A periodic function call (~60 minutes) by the driver. Used to respawn monsters, restock items.

**call_out**, A one-shot delayed function call. Like `setTimeout` in JavaScript.

**Alignment**, A numeric value from negative (evil) to positive (good). Affects interactions, guilds, some game mechanics.

**Aggressive**, A monster with `set_aggressive(1)` attacks players on sight when they enter the room.

**Dungeon**, A scaled area where monster stats adjust to a target level. Set up with `set_dungeon()`.

## Data Types

**Mapping**, LPC's associative array / dictionary. Created with `([ key: value ])`.

**Pointer/Array**, Ordered list. Created with `({ element, element })`. Called "pointer" in some driver docs.

**Closure**, A function reference that can be stored in a variable and called later. Created with `#'func` or `(: expression :)`.

**Mixed**, A variable that can hold any type. Use when the type is not known at compile time.

**Status**, A boolean type (0 or 1). Preferred over `int` for true/false values in 3K style.

## File Conventions

**defs.h**, Header file with `#define` macros for paths and shortcuts. Each area has its own, chaining up to the global one.

**create()**, Called once when an object is first loaded or cloned. Setup goes here.

**init()**, Called when a living enters an object's environment. `add_action` calls go here.

**reset()**, Called periodically by the driver. Monster respawning and item restocking go here.
