/*
  ex03_mapping_funcs.c
  YourName YYMMDD
  Exercise 12.3 — Mapping Utilities
  Demonstrates iterating over mappings, building new mappings,
  and combining mapping data.
*/
#pragma strong_types
#include "../defs.h"

// TODO: Add function prototypes for both functions below.

// TODO: Implement invert_mapping(mapping m)
//   Swap keys and values of a mapping.
//   Example: ([ "a":1, "b":2 ]) -> ([ 1:"a", 2:"b" ])
//
//   Steps:
//     1. Create an empty result mapping
//     2. Use foreach to iterate over the input mapping
//     3. For each entry, swap the key and value in the result
//     4. Return result

// TODO: Implement merge_mappings(mapping a, mapping b)
//   Combine two mappings into one. Values from mapping b
//   overwrite values from mapping a where keys conflict.
//   Example:
//     ([ "hp":100, "sp":50 ]) + ([ "sp":75, "mp":30 ])
//     -> ([ "hp":100, "sp":75, "mp":30 ])
//
//   Steps:
//     1. Create an empty result mapping
//     2. Use foreach to copy all entries from a into result
//     3. Use foreach to copy all entries from b into result
//        (this naturally overwrites conflicts from a)
//     4. Return result
//   Do not modify the original mappings.
