# LPC Modifiers — Quick Reference

## Modifier Table

| Modifier    | Applies to       | What it does                                                |
|-------------|------------------|-------------------------------------------------------------|
| `private`   | functions, vars  | Only accessible within this object (not via `->` or `::`)  |
| `protected` | functions, vars  | Accessible by this object and inheriting objects only       |
| `public`    | functions, vars  | Accessible by any object (default for functions)            |
| `static`    | functions, vars  | **Functions**: cannot be called via `call_other`/`->`. **Variables**: not saved. |
| `nosave`    | variables        | Variable is not saved/restored (same as static for vars)    |
| `nomask`    | functions        | Cannot be overridden by inheriting objects                  |
| `varargs`   | functions        | Some parameters are optional                                |
| `virtual`   | inherit          | Shared single copy in diamond inheritance                   |

## Usage Examples

### private

```lpc
private int secret_value;

private void helper()
{
  // only this file can call helper()
  return;
}
```

### protected

```lpc
protected void internal_reset()
{
  // this object and children can call, but outsiders cannot
  return;
}
```

### static / nosave

```lpc
// For variables, static and nosave both mean "don't save"
nosave int temp_counter;
static int also_not_saved;

// For functions, static means "no call_other access"
static void local_only()
{
  // ob->local_only() will fail
  // direct call within this object works fine
  return;
}
```

### nomask

```lpc
nomask int query_level()
{
  // children cannot override this function
  return level;
}
```

### varargs

```lpc
varargs void attack(object target, int bonus)
{
  if (!bonus)
    bonus = 0;
  // bonus is optional when calling
  return;
}
```

### virtual inherit

```lpc
virtual inherit "std/base";
// In diamond inheritance, only one copy of /std/base exists
```

## Combining Modifiers

```lpc
private nosave int cache;
protected nomask void core_function() { return; }
public varargs void flexible_func(string arg, int flag) { return; }
static private int internal_only;
```

## When to Use What

| Situation                              | Use                    |
|----------------------------------------|------------------------|
| Internal helper nobody else needs      | `private`              |
| Variable that children might need      | `protected`            |
| Temporary data, not saved              | `nosave`               |
| Prevent children from overriding       | `nomask`               |
| Some args optional                     | `varargs`              |
| Block external `->` calls on function  | `static`               |
| Diamond inheritance shared base        | `virtual inherit`      |

## Gotchas

- `private` functions cannot be called with `::` from child objects.
- `static` on a function is NOT the same as in C/C++. It means "no call_other".
- `static` on a variable means `nosave`. Prefer `nosave` for clarity.
- Default visibility for functions is `public`.
- Default visibility for global variables is `public` and saved (if save/restore is used).
