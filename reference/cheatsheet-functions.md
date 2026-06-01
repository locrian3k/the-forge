# LPC Functions — Quick Reference

## Declaration Syntax

```lpc
return_type function_name(param_type param, ...)
{
  // body
  return value;
}
```

```lpc
int add(int a, int b)
{
  return a + b;
}

void greet(string name)
{
  write("Hello, " + name + "!\n");
  return;
}
```

## Void Functions

Always end with explicit `return;` (3K codestyle rule).

```lpc
void do_something()
{
  write("Done.\n");
  return;
}
```

## Short Query/Set Functions

Simple one-liners stay on one line:

```lpc
int query_level() { return level; }
void set_level(int x) { level = x; return; }
string query_name() { return name; }
```

## Prototypes

Declare before use if defined later in the file:

```lpc
void helper_func(string arg);  // prototype

void create()
{
  helper_func("test");
  return;
}

void helper_func(string arg)
{
  write(arg + "\n");
  return;
}
```

## Varargs

```lpc
varargs void announce(string msg, int loud)
{
  if (loud)
    write("!!! " + msg + " !!!\n");
  else
    write(msg + "\n");
  return;
}

announce("hello");       // loud defaults to 0
announce("hello", 1);    // loud = 1
```

## Calling Patterns

### Direct call (same object)

```lpc
int result = my_function(arg1, arg2);
```

### Arrow operator (other object)

```lpc
string name = (string)ob->query_name();
ob->take_damage(50);
```

### call_other (dynamic)

```lpc
mixed result = call_other(ob, "query_name");
call_other(ob, "take_damage", 50);
```

### this_object() calls

```lpc
this_object()->query_name();  // call on self via external interface
```

## Object Lifecycle Functions

| Function   | When called                              |
|------------|------------------------------------------|
| `create()` | When object is first loaded/cloned       |
| `init()`   | When a living enters the environment     |
| `reset()`  | Periodically by the driver (~60 min)     |

```lpc
void create()
{
  ::create();  // call parent's create
  // setup code
  return;
}

void init()
{
  ::init();
  add_action("do_pull", "pull");
  return;
}

void reset()
{
  ::reset();
  // respawn/refresh logic
  return;
}
```

## Common Return Patterns

```lpc
// Boolean success/failure
status do_action(string arg)
{
  if (!arg)
    return 0;  // failure: let driver try other actions
  // do stuff
  return 1;    // success: action handled
}

// Return 1 from init actions to claim the verb
// Return 0 to let other objects try
```

## apply vs efun vs lfun vs sefun

- **efun**: driver-provided (write, clone_object, tell_room)
- **lfun**: locally defined in the current object
- **sefun**: simulated efun, available everywhere like an efun
- **apply**: driver calls these on objects (create, init, reset, heart_beat)
