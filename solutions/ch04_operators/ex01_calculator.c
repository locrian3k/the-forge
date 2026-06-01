#pragma strong_types
#include "defs.h"

// Exercise 4.1, Calculator Object
// Basic arithmetic operations with division-by-zero protection.

inherit "obj/treasure";

void create()
{
  ::create();

  set_name("calculator");
  set_alias(({"calc", "calculator"}));
  set_short("a calculator");
  set_long(
    "A brass device covered in tiny gears and dials. It can "
    "perform the fundamental operations of arithmetic, and it "
    "is smart enough not to divide by zero."
  );
  set_value(15);
  set_weight(2);

  return;
}

// Addition
int do_add(int a, int b)
{
  return a + b;
}

// Subtraction
int do_sub(int a, int b)
{
  return a - b;
}

// Multiplication
int do_mul(int a, int b)
{
  return a * b;
}

// Division, returns 0 if divisor is zero
int do_div(int a, int b)
{
  if (b == 0)
    return 0;
  return a / b;
}

// Modulo, returns 0 if divisor is zero
int do_mod(int a, int b)
{
  if (b == 0)
    return 0;
  return a % b;
}
