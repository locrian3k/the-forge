#pragma strong_types
#include "defs.h"

//
// Exercise 8.1: Access Control
// Demonstrates access modifiers: public, private, protected, static.
// Each function uses the modifier best suited to its role.
//

string title;
string owner_name;

//
// format_name - PRIVATE: This is a helper function used only inside
// this file. No external object or child class needs to call it
// directly. Making it private encapsulates the formatting logic and
// prevents outside code from depending on its implementation.
//
private string format_name(string name)
{
  if (!name)
    return "Nobody";
  return "~ " + capitalize(name) + " ~";
}

//
// do_setup - STATIC: This function performs one-time initialization.
// We use static so it cannot be triggered externally via call_other
// (which would re-initialize the object unexpectedly). Children can
// still call it if they need to re-run setup after their own create().
//
static void do_setup()
{
  owner_name = "artisan";
  title = "Master Crafter";
  return;
}

//
// internal_reset - PROTECTED: This resets internal state and is meant
// for use by child classes that may need to reset the parent's data
// as part of their own reset logic. External unrelated objects should
// not be able to trigger a reset, so we use protected instead of public.
//
protected void internal_reset()
{
  owner_name = "artisan";
  title = "Master Crafter";
  return;
}

//
// query_title - PUBLIC: This is the external interface. Any object in
// the MUD should be able to query our title via call_other. Public is
// the right choice for getter functions that form part of the object's
// external API.
//
public string query_title()
{
  return format_name(owner_name) + ", " + title;
}

void create()
{
  do_setup();
  return;
}
