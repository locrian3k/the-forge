#pragma strong_types
#include "../defs.h"

//
// Exercise 9.1: Define and Include
// Demonstrates #include and #define by using a custom header file
// with path defines, a string constant, and a utility macro.
//

#include "ex01_my_defs.h"

// Store computed values for query functions
string area_name;
string room_path;
string mob_path;
int max_result;

void create()
{
  // Use AREA_NAME string constant from our header
  area_name = AREA_NAME;

  // Build full paths using the path defines
  room_path = MY_ROOMS + "entrance";
  mob_path = MY_MOBS + "goblin";

  // Use the MAX utility macro
  max_result = MAX(5, 10);

  return;
}

//
// query_area_name - Returns the area name from our define.
//
string query_area_name() { return area_name; }

//
// query_room_path - Returns a full room path built with MY_ROOMS.
//
string query_room_path() { return room_path; }

//
// query_mob_path - Returns a full mob path built with MY_MOBS.
//
string query_mob_path() { return mob_path; }

//
// query_max_test - Returns the result of MAX(5, 10) to prove
// the macro works. Should return 10.
//
int query_max_test() { return max_result; }
