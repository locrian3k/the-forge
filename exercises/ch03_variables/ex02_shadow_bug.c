/*
  ex02_shadow_bug.c
  Exercise 3.2 — Shadow Bug Fix
  A fellow coder wrote this counter object, but query_counter() always
  returns 0 no matter how many times do_increment() is called.
  Find the variable shadowing bug and fix it.
*/
#pragma strong_types
#include "../defs.h"

inherit "obj/treasure";

int counter;

void create()
{
  ::create();

  set_name("shadow counter");
  set_alias(({"counter", "shadow counter"}));
  set_short("a shadow counter");
  set_long("A counting device plagued by shadows.");
  set_value(1);
  set_weight(1);

  counter = 0;

  return;
}

// BUG: query_counter() always returns 0. Why?
// HINT: Look at the first line inside this function.
// TODO: Fix this function so counter++ modifies the global variable.
void do_increment()
{
  // BUG: this local declaration shadows the global!
  int counter;

  counter++;

  return;
}

int query_counter() { return counter; }
