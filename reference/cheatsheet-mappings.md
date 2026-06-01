# LPC Mappings — Quick Reference

## Creating Mappings

```lpc
// Empty mapping
mapping m = ([]);

// With values
mapping stats = ([
  "strength": 18,
  "dexterity": 14,
  "wisdom": 10,
]);

// From parallel arrays
string *keys = ({ "a", "b", "c" });
int *vals = ({ 1, 2, 3 });
mapping m = mkmapping(keys, vals);
```

## Accessing Values

```lpc
int str = stats["strength"];        // returns 18
stats["charisma"] = 12;             // add/set a key
int missing = stats["nonexist"];    // returns 0 (not an error)
```

## Key Functions

| Function               | Description                        | Example                        |
|------------------------|------------------------------------|--------------------------------|
| `m_indices(m)`         | All keys as array                  | `string *k = m_indices(m);`    |
| `m_values(m)`          | All values as array                | `mixed *v = m_values(m);`      |
| `sizeof(m)`            | Number of key-value pairs          | `if (sizeof(m) > 0)`          |
| `member(m, key)`       | 1 if key exists, 0 if not          | `if (member(m, "hp"))`        |
| `m_delete(m, key)`     | Remove a key, returns modified map | `m = m_delete(m, "old");`      |
| `mkmapping(keys, vals)`| Build from two arrays              | `mapping m = mkmapping(k, v);` |
| `widthof(m)`           | Number of values per key           | `int w = widthof(m);`          |

## Iteration

### foreach (preferred)

```lpc
// Keys and values
foreach (string key, int val : stats)
{
  write(key + ": " + val + "\n");
}

// Keys only
foreach (string key : stats)
{
  write(key + "\n");
}
```

### Manual iteration

```lpc
string *keys = m_indices(stats);
for (int i = 0; i < sizeof(keys); i++)
{
  write(keys[i] + ": " + stats[keys[i]] + "\n");
}
```

## Nested Mappings

```lpc
mapping inventory = ([
  "weapons": ([
    "sword": 1,
    "dagger": 3,
  ]),
  "potions": ([
    "healing": 5,
    "mana": 2,
  ]),
]);

// Access nested
int swords = inventory["weapons"]["sword"];

// Set nested
inventory["weapons"]["axe"] = 1;
```

## Multi-Value Mappings

```lpc
// Mappings can have multiple values per key (width > 1)
// Less common, but supported by the driver
mapping m = m_allocate(0, 2);  // width 2
m_add(m, "key", "val1", "val2");
```

## Common Patterns

```lpc
// Check before access
if (member(m, key))
  val = m[key];

// Merge two mappings (second wins on conflicts)
mapping combined = m1 + m2;

// Copy a mapping
mapping copy = m + ([]);

// Remove multiple keys
foreach (string key : remove_list)
  m = m_delete(m, key);
```

## Gotchas

- Uninitialized mapping is `0`, not `([])`. Always initialize.
- `m[key]` returns `0` for missing keys, same as integer default.
- Use `member(m, key)` to distinguish "key missing" from "key has value 0".
- Mappings are passed by reference. Modifying a mapping modifies all references.
