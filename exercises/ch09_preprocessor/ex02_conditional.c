/*
  ex02_conditional.c
  Exercise 9.2 — Conditional Compilation
  Demonstrate #ifdef, #if, and include guards. Behavior changes
  at compile time based on defines in the header.
*/
#pragma strong_types
#include "../defs.h"

// TODO: Include your configuration header (ex02_conditional.h)

void create()
{
  return;
}

//
// query_debug_info - Returns debug information when DEBUG is defined,
// or a placeholder string when it is not.
//
// TODO: Use #ifdef DEBUG / #else / #endif to implement:
//   When DEBUG is defined:
//     Return a string containing the word "DEBUG" plus the VERSION
//     and AREA_TITLE values from the header.
//   When DEBUG is NOT defined:
//     Return "no debug".
//

//
// query_feature - Returns different feature descriptions depending on
// the VERSION level.
//
// TODO: Use #if VERSION >= 2 / #else / #endif to implement:
//   When VERSION is 2 or higher: return "enhanced"
//   When VERSION is below 2: return "basic"
//

//
// query_version - Returns the VERSION number from the header.
//
// TODO: Implement. Return VERSION.
//

//
// query_title - Returns the AREA_TITLE string from the header.
//
// TODO: Implement. Return AREA_TITLE.
//
