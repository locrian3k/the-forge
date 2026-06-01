# Driver Functions (efuns) — Quick Reference

## String Functions

| Function | Description | Example |
|----------|-------------|---------|
| `explode(str, del)` | Split string into array | `explode("a:b:c", ":") // ({"a","b","c"})` |
| `implode(arr, del)` | Join array into string | `implode(({"a","b"}), ", ") // "a, b"` |
| `sprintf(fmt, ...)` | Formatted string | `sprintf("%-20s %d", name, level)` |
| `sscanf(str, fmt, ...)` | Parse string into vars | `sscanf("hp:100", "%s:%d", key, val)` |
| `replace_string(str, old, new)` | Replace all occurrences | `replace_string(s, " ", "_")` |
| `capitalize(str)` | Uppercase first char | `capitalize("bob") // "Bob"` |
| `lower_case(str)` | Lowercase entire string | `lower_case("BOB") // "bob"` |
| `strlen(str)` | String length | `if (strlen(name) > 20)` |
| `str[i..j]` | Substring (inclusive) | `"hello"[0..2] // "hel"` |

### sprintf Format Codes

| Code | Type | Example |
|------|------|---------|
| `%d` | integer | `sprintf("%d", 42)` |
| `%s` | string | `sprintf("%s", name)` |
| `%O` | any (debug) | `sprintf("%O", mapping)` |
| `%-20s` | left-align, width 20 | Column formatting |
| `%:3d` | zero-padded, width 3 | `sprintf("%:3d", 5) // "005"` |

## Array Functions

| Function | Description | Example |
|----------|-------------|---------|
| `sizeof(arr)` | Number of elements | `if (sizeof(arr) > 0)` |
| `member(arr, val)` | Index of val (-1 if missing) | `member(({1,2,3}), 2) // 1` |
| `sort_array(arr, dir)` | Sort (1=asc, -1=desc) | `sort_array(arr, 1)` |
| `filter(arr, func)` | Keep matching elements | `filter(arr, #'stringp)` |
| `map(arr, func)` | Transform each element | `map(arr, #'capitalize)` |
| `unique_array(arr, func)` | Group by function result | `unique_array(obs, #'query_race)` |

## Mapping Functions

| Function | Description | Example |
|----------|-------------|---------|
| `m_delete(map, key)` | Remove key, return map | `m = m_delete(m, "old")` |
| `m_indices(map)` | Array of all keys | `string *keys = m_indices(m)` |
| `m_values(map)` | Array of all values | `mixed *vals = m_values(m)` |
| `mkmapping(keys, vals)` | Build from two arrays | `mapping m = mkmapping(k, v)` |
| `member(map, key)` | 1 if key exists | `if (member(m, "hp"))` |
| `sizeof(map)` | Number of entries | `int count = sizeof(m)` |

## Object Functions

| Function | Description | Example |
|----------|-------------|---------|
| `clone_object(path)` | Create a clone | `object ob = clone_object(MON + "goblin")` |
| `destruct(ob)` | Destroy an object | `destruct(this_object())` |
| `find_object(path)` | Find loaded object | `object ob = find_object("/obj/weapon")` |
| `load_object(path)` | Load (don't clone) | `load_object("/room/start")` |
| `present(id, ob)` | Find by id in inventory | `present("sword", TP)` |
| `all_inventory(ob)` | Array of contents | `object *inv = all_inventory(TP)` |
| `environment(ob)` | Container of ob | `object room = environment(TP)` |
| `move_object(dest)` | Move this_object | `move_object(room)` |
| `this_player()` | Current acting player | `object tp = this_player()` |
| `this_object()` | Current object | `object to = this_object()` |

## Math Functions

| Function | Description | Example |
|----------|-------------|---------|
| `random(n)` | Random 0 to n-1 | `int roll = random(6) + 1` |
| `abs(n)` | Absolute value | `int dist = abs(x - y)` |

## Time Functions

| Function | Description | Example |
|----------|-------------|---------|
| `time()` | Seconds since epoch | `int now = time()` |
| `ctime(t)` | Human-readable time | `string s = ctime(time())` |

## File Functions

| Function | Description | Example |
|----------|-------------|---------|
| `read_file(path)` | Read file contents | `string data = read_file(path)` |
| `write_file(path, str)` | Append to file | `write_file(log, msg)` |

## Output Functions

| Function | Description | Target |
|----------|-------------|--------|
| `write(str)` | Message to this_player | Current player only |
| `say(str)` | Message to room except TP | Everyone else in room |
| `tell_object(ob, str)` | Message to specific object | One object |
| `tell_room(room, str)` | Message to entire room | Everyone in room |
| `tell_room(room, str, exclude)` | Room except excluded | Room minus array |

```lpc
write("You swing your sword!\n");
say((string)TP->query_name() + " swings a sword!\n");
tell_room(ETO, "A loud boom echoes!\n");
tell_room(ETO, "You dodge!\n", ({ TP }));
```

## Delayed Execution

| Function | Description | Example |
|----------|-------------|---------|
| `call_out(func, delay, args...)` | Call func after delay secs | `call_out("do_explode", 3)` |
| `remove_call_out(func)` | Cancel pending call_out | `remove_call_out("do_explode")` |
| `find_call_out(func)` | Time remaining (-1 if none) | `if (find_call_out("tick") == -1)` |
| `set_heart_beat(flag)` | Enable/disable heartbeat | `set_heart_beat(1)` |

Heart beat fires every 2 seconds when enabled. Use `heart_beat()` apply.

> **Note:** Common macros like `TP`, `TO`, and `ETO` are defined in `defs.h` --
> see the Preprocessor cheatsheet for the full list.
