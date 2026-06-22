#pragma strong_types
#include "../defs.h"

//
// Exercise 9.2: Conditional Compilation
// Demonstrates #ifdef, #if, and include guards. Behavior changes
// at compile time based on defines in the header.
//

#include "ex02_conditional.h"

void create()
{
  return;
}

//
// query_debug_info - Returns debug information when DEBUG is defined,
// or a placeholder string when it is not. The #ifdef directive checks
// whether DEBUG exists as a define (regardless of its value).
//
string query_debug_info()
{
#ifdef DEBUG
  // This block only compiles when DEBUG is #defined in the header.
  return "DEBUG active: version=" + VERSION + ", title=" + AREA_TITLE;
#else
  // This block compiles when DEBUG is NOT defined.
  return "no debug";
#endif
}

//
// query_feature - Returns different feature descriptions depending on
// the VERSION level. The #if directive evaluates the numeric value of
// VERSION at compile time, allowing feature gating by version.
//
string query_feature()
{
#if VERSION >= 2
  // Version 2+ gets the enhanced feature set.
  return "enhanced";
#else
  // Older versions get basic functionality only.
  return "basic";
#endif
}

//
// query_version - Returns the VERSION number from the header.
//
int query_version() { return VERSION; }

//
// query_title - Returns the AREA_TITLE string from the header.
//
string query_title() { return AREA_TITLE; }
