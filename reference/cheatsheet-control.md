# LPC Control Flow — Quick Reference

## if / else

```lpc
// Single statement, no braces (3K style)
if (x > 10)
  write("big\n");

// With else
if (x > 10)
  write("big\n");
else
  write("small\n");

// Multiple statements, Allman braces
if (x > 10)
{
  write("big\n");
  do_thing();
}
else if (x > 5)
{
  write("medium\n");
}
else
{
  write("small\n");
}
```

## switch / case

```lpc
switch (cmd)
{
  case "north":
    go_north();
    break;
  case "south":
    go_south();
    break;
  case "east":
  case "west":          // fall-through: both hit this code
    write("Horizontal!\n");
    break;
  default:
    write("Unknown direction.\n");
    break;
}
```

Switch also works with int and ranges:

```lpc
switch (roll)
{
  case 1..5:
    write("Low roll.\n");
    break;
  case 6..10:
    write("High roll.\n");
    break;
}
```

**Warning**: Forgetting `break;` causes fall-through.

## for

```lpc
for (int i = 0; i < sizeof(arr); i++)
{
  write(arr[i] + "\n");
}
```

## foreach

### Over arrays

```lpc
foreach (string item : items)
{
  write(item + "\n");
}
```

### Over mappings

```lpc
foreach (string key, mixed val : my_map)
{
  write(key + " = " + val + "\n");
}
```

### Over a range

```lpc
foreach (int i : 1 .. 10)
{
  write(i + "\n");
}
```

## while

```lpc
while (count > 0)
{
  do_thing();
  count--;
}
```

## do-while

```lpc
do
{
  result = try_something();
}
while (result == 0);
```

Executes body at least once.

## break

Exits the innermost loop or switch:

```lpc
for (int i = 0; i < 100; i++)
{
  if (found_it(i))
    break;  // exit the for loop
}
```

## continue

Skips to the next iteration:

```lpc
foreach (object ob : items)
{
  if (!ob)
    continue;  // skip null objects
  ob->do_thing();
}
```

## return

Exits the current function:

```lpc
status do_action(string arg)
{
  if (!arg)
    return 0;
  // process arg
  return 1;
}
```

## Common Patterns

```lpc
// Guard clause, exit early on bad input
if (!arg || arg == "")
  return 0;

// Null-safe iteration
if (arr && sizeof(arr))
{
  foreach (mixed item : arr)
    process(item);
}
```
