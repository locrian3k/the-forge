# LPC Preprocessor — Quick Reference

## #pragma strong_types

Must be the first **non-comment** line of every `.c` file (after the file header comment):

```lpc
#pragma strong_types
```

Enables compile-time type checking. Required by 3K codestyle.

## #include

```lpc
#include "defs.h"          // local include (relative to file)
#include <std.h>           // system include (from mudlib include path)
#include "../../defs.h"    // for files in subdirectories
```

Use quotes for project headers, angle brackets for system headers.

## #define — Simple Constants

```lpc
#define MAX_HP       1000
#define DUNGEON_NAME "Goblin Caves"
#define ROOM_PATH    (AREAS + "horde/rooms/")
```

Convention: UPPERCASE names for defines.

## #define — Macros

```lpc
#define TP    this_player()
#define TO    this_object()
#define ETO   environment(this_object())

#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#define MIN(a, b)  ((a) < (b) ? (a) : (b))
```

**Always parenthesize** macro parameters and the whole expression.

> **Tip:** `TPQN` (This Player Query Name) is a handy macro common on many
> MUDs but not included in the standard 3K `defs.h`. We recommend defining
> it yourself:
> ```lpc
> #define TPQN ((string)this_player()->query_name())
> ```
> This gives you a clean shorthand for the player's name in messages.

## #define — Multi-line

```lpc
#define LONG_DESC \
  "This is a very long " \
  "description that spans " \
  "multiple lines."
```

Use `\` at end of line to continue.

## Conditional Compilation

### #ifdef / #ifndef

```lpc
#ifdef DEBUG
  write("Debug mode active.\n");
#endif

#ifndef DEFS_H
#define DEFS_H
  // header content
#endif
```

### #if / #elif / #else

```lpc
#if MAX_LEVEL > 100
  // high-level config
#elif MAX_LEVEL > 50
  // mid-level config
#else
  // low-level config
#endif
```

## Include Guard Pattern

Prevents double-inclusion of headers:

```lpc
// In defs.h:
#ifndef __MYAREA_DEFS_H__
#define __MYAREA_DEFS_H__

#include "../../defs.h"

#define DNAME   "My Area"
#define ROOMS   (AREAS + "myarea/rooms/")
#define OBJ     (AREAS + "myarea/obj/")
#define MON     (AREAS + "myarea/mon/")

#endif
```

## #undef

```lpc
#undef MAX_HP
#define MAX_HP 2000
```

Remove a previous definition before redefining.

## Typical defs.h Chain

```
include/defs.h         , global defines (AREAS, TP, TO, etc.)
  areas/myarea/defs.h  , area defines (ROOMS, OBJ, MON, DNAME)
    areas/myarea/rooms/rm1.c , #include "../defs.h"
    areas/myarea/obj/sword.c , #include "../defs.h"
    areas/myarea/obj/sub/x.c , #include "../../defs.h"
```

## Gotchas

- `#pragma strong_types` must be the first non-comment line (file header comment comes first).
- No semicolons after `#define` values (they become part of the value).
- Macro arguments are text substitution, not evaluated. Always use parens.
- Subdirectory files need extra `../` in include paths.
