/*
  ex01_access_control.c
  Exercise 8.1 — Access Control
  Demonstrate LPC access modifiers: public, private, protected, static.
  Each function should use the modifier best suited to its role.
*/
#pragma strong_types
#include "defs.h"

// TODO: Declare two global string variables for title and owner name.

//
// format_name - A helper function used only inside this file.
// No external object or child class should be able to call it.
//
// TODO: Choose the correct modifier (public/private/protected/static)
//       and implement this function.
//   - If name is 0 (null), return "Nobody"
//   - Otherwise return "~ " + capitalize(name) + " ~"
//
// Hint: Which modifier means "only this file, not even children"?
//

//
// do_setup - Performs one-time initialization.
// Should not be callable via call_other() from external objects,
// but children should still be able to call it directly.
//
// TODO: Choose the correct modifier and implement.
//   - Set owner_name to "artisan"
//   - Set title to "Master Crafter"
//
// Hint: Which modifier blocks call_other() but allows children?
//

//
// internal_reset - Resets internal state.
// Meant for use by child classes that need to reset parent data.
// External unrelated objects should NOT be able to call this.
//
// TODO: Choose the correct modifier and implement.
//   - Set owner_name to "artisan"
//   - Set title to "Master Crafter"
//
// Hint: Which modifier allows children but blocks external objects?
//

//
// query_title - The external interface.
// Any object in the MUD should be able to call this via call_other.
//
// TODO: Choose the correct modifier and implement.
//   - Return format_name(owner_name) + ", " + title
//
// Hint: Which modifier means "anyone, from anywhere"?
//

void create()
{
  // TODO: Call do_setup() to initialize the object

  return;
}
