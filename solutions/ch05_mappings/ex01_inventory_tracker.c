#pragma strong_types
#include "defs.h"

//
// Exercise 5.1: Inventory Tracker
// Demonstrates basic mapping operations: create, assign, lookup,
// delete, and key retrieval.
//

// Global mapping to store item names and their quantities
mapping inventory;

void create()
{
  // Initialize an empty mapping
  inventory = ([]);
  return;
}

//
// add_item - Adds quantity to an existing item or creates a new entry.
// If the item already exists, the quantity is accumulated.
//
void add_item(string name, int qty)
{
  if (inventory[name])
    inventory[name] += qty;
  else
    inventory[name] = qty;
  return;
}

//
// remove_item - Deletes an item entry from the inventory entirely.
//
void remove_item(string name)
{
  map_delete(inventory, name);
  return;
}

//
// query_item - Returns the quantity of an item, or 0 if not found.
// Mappings return 0 for missing keys by default in LPC, so a simple
// lookup suffices here.
//
int query_item(string name)
{
  return inventory[name];
}

//
// list_items - Returns a sorted array of all item names currently
// stored in the inventory.
//
string *list_items()
{
  return sort_array(keys(inventory), 1);
}
