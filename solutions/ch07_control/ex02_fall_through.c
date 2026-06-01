#pragma strong_types
#include "defs.h"

//
// Exercise 7.2: Switch Fall-Through
// Demonstrates intentional fall-through in switch statements where
// multiple damage types share the same message. Every fall-through
// is explicitly commented.
//

void create()
{
  return;
}

//
// damage_message - Returns a damage description string based on
// the damage type. Uses intentional fall-through so that related
// damage types share the same message.
//
// Fall-through pairs:
//   "fire" + "acid"      -> "It burns!"
//   "ice"  + "lightning"  -> "A shocking chill!"
//
string damage_message(string type)
{
  string result;

  switch (type)
  {
    case "fire":
      // fall through, fire and acid share the same message
    case "acid":
      result = "It burns!";
      break;
    case "ice":
      // fall through, ice and lightning share the same message
    case "lightning":
      result = "A shocking chill!";
      break;
    case "poison":
      result = "You feel ill.";
      break;
    default:
      result = "Ouch!";
      break;
  }
  return result;
}
