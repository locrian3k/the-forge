# 3K Codestyle — Quick Reference

## File Structure Order

1. File header comment: `/* filename.c / Author YYMMDD / Description */`
2. `#pragma strong_types` (first non-comment line)
3. `#include "defs.h"`
4. `#define` macros
5. `inherit` statements
6. Global variables
7. Function prototypes
8. `create()`
9. `init()`
10. `reset()`
11. Other functions

## Braces — Allman Style

Opening brace on its OWN line:

```lpc
void create()
{
  ::create();
  return;
}

if (x > 5)
{
  do_thing();
  do_other();
}
```

**Never** same-line braces: ~~`void create() {`~~

## Indentation

- **Spaces only**, no tabs
- **2-space** indent levels

## Single-Statement if/else

No braces for single statements:

```lpc
if (x > 5)
  do_thing();
else
  do_other();
```

## Void Functions

Always end with explicit `return;`:

```lpc
void setup()
{
  set_name("thing");
  return;
}
```

## Short Functions

Simple query/set on one line:

```lpc
int query_level() { return level; }
void set_level(int x) { level = x; return; }
```

## status Type

Use `status` for true/false values, not `int`:

```lpc
status is_active = 1;
status do_action(string arg)
{
  if (!arg)
    return 0;
  return 1;
}
```

## Naming Conventions

- **Lowercase with underscores**: `my_variable`, `do_action`
- **Function prefixes**: `query_`, `set_`, `clear_`, `reset_`, `do_`
- **UPPERCASE** for `#define` macros: `MAX_HP`, `ROOM_PATH`

## Variables

- List by type, alphabetically
- Pointers after standard vars
- Remove unused declarations

```lpc
int count;
int level;
string name;
int *scores;
string *names;
```

## Lines

- Under 80 characters when possible
- Strings over 40-50 chars: wrap to player's COLS setting
- Single spacing between sentences in strings

## Comments

- Comment your code thoroughly
- Use `//` for single-line, `/* */` for multi-line

## Function Type

Type on same line as function name:

```lpc
void create()     // correct
```

Not split across lines: ~~`void\ncreate()`~~

## Screenreader

Check SCREENREADER property; skip decorative/ASCII art strings:

```lpc
if (!(int)TP->query_property("SCREENREADER"))
  write(ascii_art_string);
```

## Quick Checklist

- [ ] File header comment block first?
- [ ] `#pragma strong_types` as first non-comment line?
- [ ] Allman braces (own line)?
- [ ] 2-space indent, no tabs?
- [ ] Void functions end with `return;`?
- [ ] `status` for booleans?
- [ ] No braces on single-statement if/else?
- [ ] Variables declared by type, alphabetically?
- [ ] No unused variables?
- [ ] Lines under 80 chars?
- [ ] Functions follow naming conventions?
