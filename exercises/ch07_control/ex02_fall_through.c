/*
  ex02_fall_through.c
  Exercise 7.2 — Switch Fall-Through
  Demonstrates intentional fall-through in switch statements where
  multiple damage types share the same message.
*/
#pragma strong_types
#include "defs.h"

void create()
{
  return;
}

// TODO: Implement string damage_message(string type)
//   Use a switch statement with intentional fall-through so that
//   related damage types share the same message.
//
//   Fall-through pairs:
//     "fire" + "acid"      -> "It burns!"
//     "ice"  + "lightning"  -> "A shocking chill!"
//
//   Standalone:
//     "poison"             -> "You feel ill."
//     default              -> "Ouch!"
//
//   Comment every intentional fall-through with: // fall through
//
//   Pattern:
//   case "fire":
//     // fall through, fire and acid share the same message
//   case "acid":
//     result = "It burns!";
//     break;
//
//   Hint: Declare a local string result; variable, assign in each
//   branch, and return result at the end.
