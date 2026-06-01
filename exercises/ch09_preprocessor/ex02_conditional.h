/*
  ex02_conditional.h
  Exercise 9.2 — Configuration header
  Demonstrate include guards and compile-time configuration defines.
*/

// TODO: Add an include guard using #ifndef / #define / #endif
//   Pattern:
//     #ifndef __MY_CONFIG_H__
//     #define __MY_CONFIG_H__
//     ... all your defines here ...
//     #endif // __MY_CONFIG_H__

// TODO: Define a VERSION number (e.g., 2)
//   This will be used by #if directives in code to enable or
//   disable features based on the current version level.

// TODO: Define an AREA_TITLE string constant
//   Example: #define AREA_TITLE "The Conditional Caverns"

// TODO: Add a DEBUG toggle.
//   When defined, #ifdef DEBUG blocks will compile their debug code.
//   When commented out, those blocks are skipped entirely.
//   Show the student how to toggle by commenting/uncommenting:
//     #define DEBUG
//   vs:
//     // #define DEBUG

// TODO: Close the include guard with #endif
