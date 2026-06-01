//
// my_defs.h - Area header file for Exercise 9.1
// Defines path constants, an area name, and a utility macro.
//

// Base path for this area, all other paths build from here
#define MY_PATH   "/players/me/myarea/"

// Subdirectory paths built from the base
#define MY_ROOMS  (MY_PATH + "rooms/")
#define MY_MOBS   (MY_PATH + "mobs/")

// Area name constant, used in descriptions and announcements
#define AREA_NAME "The Training Grounds"

// Utility macro: returns the larger of two values.
// Parentheses around (a) and (b) prevent precedence bugs when
// the macro arguments are expressions like (x + 1).
#define MAX(a, b) ((a) > (b) ? (a) : (b))
