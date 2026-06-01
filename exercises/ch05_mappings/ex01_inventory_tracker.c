/*
  ex01_inventory_tracker.c
  Exercise 5.1 — Inventory Tracker
  Demonstrates basic mapping operations: create, assign, lookup,
  delete, and key retrieval.
*/
#pragma strong_types
#include "defs.h"

// TODO: Declare a global mapping variable named "inventory"

void create()
{
  // TODO: Initialize inventory as an empty mapping.

  return;
}

// TODO: Implement void add_item(string name, int qty)
//   If "name" already exists in the mapping, add qty to the existing value.
//   If "name" does not exist, create a new entry with the given qty.
//
//   Hint: Check if the key exists, then add to or create the entry.

// TODO: Implement void remove_item(string name)
//   Delete the entry for "name" from the inventory.
//   Hint: Use map_delete() to remove a key from a mapping.

// TODO: Implement int query_item(string name)
//   Return the quantity for "name", or 0 if not found.
//   Hint: Mappings return 0 for missing keys by default.

// TODO: Implement string *list_items()
//   Return a sorted array of all item names in the inventory.
//   Hint: Use keys() to get all keys, then sort_array() to sort them.
