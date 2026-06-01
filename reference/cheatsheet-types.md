# LPC Types — Quick Reference

## Type Table

| Type      | Description                  | Default Value | Example                    |
|-----------|------------------------------|---------------|----------------------------|
| `int`     | Integer                      | `0`           | `int x = 42;`             |
| `status`  | Boolean (0 or 1)             | `0`           | `status active = 1;`      |
| `string`  | Text string                  | `0` (null)    | `string s = "hello";`     |
| `float`   | Floating point               | `0.0`         | `float f = 3.14;`         |
| `object`  | Object reference             | `0` (null)    | `object ob = this_player();` |
| `mixed`   | Any type                     | `0`           | `mixed m = "anything";`   |
| `void`    | No return value              | n/a           | `void create() { }`       |
| `mapping` | Key-value pairs              | `0` (null)    | `mapping m = ([]);`        |

## Array Types

```lpc
int *nums = ({ 1, 2, 3 });
string *words = ({ "a", "b" });
object *obs = ({ });
mixed *stuff = ({ 1, "two", ob });
```

Arrays use `type *name` syntax. `({ })` is the array literal.

## Type-Check Functions

| Function    | Tests for  | Example                       |
|-------------|------------|-------------------------------|
| `intp(x)`   | int        | `if (intp(val)) ...`          |
| `stringp(x)`| string     | `if (stringp(val)) ...`       |
| `objectp(x)`| object     | `if (objectp(ob)) ...`        |
| `floatp(x)` | float      | `if (floatp(val)) ...`        |
| `pointerp(x)` | array   | `if (pointerp(arr)) ...`      |
| `mappingp(x)` | mapping | `if (mappingp(m)) ...`        |
| `closurep(x)` | closure | `if (closurep(cl)) ...`       |
| `living(x)` | is living  | `if (living(ob)) ...`         |
| `interactive(x)` | is player | `if (interactive(ob)) ...` |

## Casting

```lpc
int x = (int)ob->query_level();
string name = (string)ob->query_name();
object *inv = (object *)all_inventory(room);
```

Cast with `(type)expression`. Used when the compiler cannot infer the type.

## Null Checks

- Strings: `if (str)` or `if (stringp(str) && str != "")`
- Objects: `if (ob)` or `if (objectp(ob))`
- Arrays: `if (arr && sizeof(arr))`
- Mappings: `if (m && sizeof(m))`
- `0` is falsy for all types. Uninitialized variables are `0`.
