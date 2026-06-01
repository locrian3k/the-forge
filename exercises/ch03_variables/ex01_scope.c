/*
  ex01_scope.c
  Exercise 3.1 — Scope Matters
  Demonstrates the difference between global and local variable scope.
*/
#pragma strong_types
#include "defs.h"

inherit "obj/treasure";

// TODO: Declare a global int variable named "counter"

void create()
{
  ::create();

  // TODO: Set the object identity:
  //   name  -> "scope stone"
  //   alias -> ({"stone", "scope stone"})
  //   short -> "a scope stone"
  //   long  -> a description of your choice
  //   value -> 1
  //   weight -> 1

  // TODO: Initialize counter to 0

  return;
}

// TODO: Write int do_increment()
//   1. Declare a LOCAL int variable named "local_val"
//   2. Set local_val to 100
//   3. Increment the GLOBAL counter by 1  (counter++)
//   4. Return local_val
//
// Expected behavior: always returns 100, but counter grows each call.

// TODO: Write int query_counter()
//   Returns the global counter value.
//   Use the single-line format: int query_counter() { return counter; }
