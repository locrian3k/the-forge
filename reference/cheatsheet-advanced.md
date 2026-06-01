# Advanced Patterns — Quick Reference

## heart_beat

Fires every 2 seconds when enabled. Use for continuous effects.

```lpc
// Enable
set_heart_beat(1);

// Disable
set_heart_beat(0);

// The apply, defined in your object
void heart_beat()
{
  // Check if room is empty (optimization)
  if (!sizeof(filter(all_inventory(ETO), #'interactive)))
  {
    set_heart_beat(0);
    return;
  }

  // Do periodic work
  do_periodic_thing();
  return;
}
```

### Re-enable on player entry

```lpc
void init()
{
  ::init();
  if (interactive(this_player()))
    set_heart_beat(1);
  return;
}
```

## call_out

Schedule a function call after a delay (in seconds).

```lpc
// Basic usage
call_out("do_explode", 5);           // call do_explode in 5 seconds
call_out("say_msg", 3, "Hello!\n");  // with argument

void do_explode()
{
  tell_room(ETO, "BOOM! The barrel explodes!\n");
  return;
}
```

### Prevent duplicate call_outs

```lpc
void start_timer()
{
  if (find_call_out("tick") == -1)  // -1 means no pending call
    call_out("tick", 10);
  return;
}
```

### Cancel a call_out

```lpc
remove_call_out("do_explode");  // cancel pending call
```

### Repeating call_out

```lpc
void tick()
{
  // do work
  do_thing();

  // schedule next tick
  call_out("tick", 10);
  return;
}
```

### Cleanup on destruct

```lpc
void remove()
{
  remove_call_out("tick");
  remove_call_out("do_explode");
  ::remove();
  return;
}
```

## add_action Pattern

Register custom commands when a living enters the room/picks up the object.

```lpc
void init()
{
  ::init();
  add_action("do_push", "push");
  add_action("do_search", "search");
  return;
}

status do_push(string arg)
{
  if (arg != "button")
    return 0;  // not our command, let others try
  write("You push the button.\n");
  say((string)TP->query_name() + " pushes a button.\n");
  return 1;    // handled
}
```

**Key rules:**
- Return `1` = command handled, stop searching.
- Return `0` = not handled, driver tries other objects.
- Always check `arg` before acting.

## Closures

Closures are function references. Two syntaxes:

### #' syntax (efun/lfun references)

```lpc
// Reference to an efun
closure cl = #'write;

// Use with filter/map
string *names = filter(names, #'stringp);
string *upper = map(names, #'capitalize);

// Sort with comparison
int *sorted = sort_array(nums, #'>);
```

### (: :) syntax (inline closures)

```lpc
// Inline closure with $1, $2 for arguments
string *long_names = filter(names, (: strlen($1) > 5 :));

// With local variable capture
int min_level = 10;
object *strong = filter(monsters,
  (: (int)$1->query_level() >= min_level :)
);

// In sort_array
sort_array(players,
  (: (int)$1->query_level() - (int)$2->query_level() :)
);
```

### funcall / apply

```lpc
closure cl = #'write;
funcall(cl, "Hello!\n");     // call the closure

closure add = (: $1 + $2 :);
int result = funcall(add, 3, 4);  // result = 7
```

## Lambda (Rare)

```lpc
// Lambda creates closures at runtime, rarely needed
closure cl = lambda(({'x, 'y}), ({#'+, 'x, 'y}));
int result = funcall(cl, 3, 4);  // 7
```

Prefer `(: :)` syntax over lambda in almost all cases.

## Common Combined Patterns

### Delayed room message sequence

```lpc
void begin_sequence()
{
  tell_room(ETO, "The ground begins to shake...\n");
  call_out("step_two", 3);
  return;
}

void step_two()
{
  tell_room(ETO, "Rocks tumble from the ceiling!\n");
  call_out("step_three", 2);
  return;
}

void step_three()
{
  tell_room(ETO, "A passage opens in the north wall!\n");
  // add a new exit or change room state
  return;
}
```

### Timed puzzle with heart_beat

```lpc
nosave int timer;

void start_puzzle()
{
  timer = 30;
  set_heart_beat(1);
  return;
}

void heart_beat()
{
  timer -= 2;  // heart_beat fires every 2 seconds
  if (timer <= 0)
  {
    tell_room(this_object(), "Time's up! The door slams shut.\n");
    set_heart_beat(0);
  }
  else if (timer == 10)
    tell_room(this_object(), "You hear a ticking sound speeding up.\n");
  return;
}
```
