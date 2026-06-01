/*
  ex01_branch_logic.c
  Exercise 7.1 — Branch Logic
  Implements weather description using both if/else and switch/case
  to demonstrate equivalent branching approaches.
*/
#pragma strong_types
#include "defs.h"

void create()
{
  return;
}

// TODO: Implement string describe_weather_if(int code)
//   Use if/else to map integer codes to weather strings:
//
//   Code  Return value
//   ----  ------------
//   0     "clear"
//   1     "cloudy"
//   2     "rainy"
//   3     "stormy"
//   4     "snowy"
//   other "unknown"
//
//   Use if/else if/else chain ending with else return "unknown";

// TODO: Implement string describe_weather_switch(int code)
//   Use switch/case to produce identical output to the if/else version.
//   Each case must use break; to prevent fall-through.
//   Use default: for the unknown case.
//
//   Hint: Declare a local string result; variable, assign in each
//   branch, and return result at the end.
