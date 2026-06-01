//
// my_config.h - Configuration header for Exercise 9.2
// Demonstrates include guards and compile-time configuration defines.
//

// Include guard: prevents double-inclusion errors when this header
// is included by multiple files or included indirectly more than once.
#ifndef __MY_CONFIG_H__
#define __MY_CONFIG_H__

// Version number, used by #if directives in code to enable or
// disable features based on the current version level.
#define VERSION     2

// Area title constant
#define AREA_TITLE  "The Conditional Caverns"

// Debug toggle: uncomment the line below to enable debug output.
// When defined, #ifdef DEBUG blocks will compile their debug code.
// When commented out, those blocks are skipped entirely.
#define DEBUG

#endif // __MY_CONFIG_H__
