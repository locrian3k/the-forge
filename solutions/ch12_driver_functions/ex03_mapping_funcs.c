#pragma strong_types
#include "defs.h"

// Mapping Utilities - demonstrates iterating over mappings,
// building new mappings, and combining mapping data.

// Function prototypes
mapping invert_mapping(mapping m);
mapping merge_mappings(mapping a, mapping b);

// Swap keys and values of a mapping.
//   ([ "a":1, "b":2 ]) -> ([ 1:"a", 2:"b" ])
// Iterates the source mapping and assigns each value as
// a key and each key as a value in the result.
mapping invert_mapping(mapping m)
{
  mapping result;
  mixed key, val;

  result = ([ ]);
  foreach (key, val : m)
    result[val] = key;
  return result;
}

// Combine two mappings into one. Values from mapping b
// overwrite values from mapping a where keys conflict.
//   ([ "hp":100, "sp":50 ]) + ([ "sp":75, "mp":30 ])
//   -> ([ "hp":100, "sp":75, "mp":30 ])
// Does not modify the original mappings.
mapping merge_mappings(mapping a, mapping b)
{
  mapping result;
  mixed key, val;

  result = ([ ]);

  // Copy all entries from a
  foreach (key, val : a)
    result[key] = val;

  // Copy all entries from b, overwriting conflicts
  foreach (key, val : b)
    result[key] = val;

  return result;
}
