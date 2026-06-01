/*
  ex03_artifact.c
  Exercise 10.3 — Multiple Inheritance, Artifact (Child)
  Inherits from BOTH describable and trackable, combining description
  management and location tracking into a single object.
*/
#pragma strong_types
#include "defs.h"

// TODO: Inherit BOTH parent files
//   inherit __DIR__ + "ex03_describable";
//   inherit __DIR__ + "ex03_trackable";

// TODO: Declare a global string variable: artifact_name

void create()
{
  // TODO: Call BOTH parent creates using the named form.
  //   A plain ::create() would only call the first parent's create.
  //   Use: describable::create();
  //        trackable::create();

  // TODO: Set artifact_name to something, e.g. "The Ember Crystal"

  // TODO: Call set_description() with a custom description string.
  //   This function is inherited from the describable parent.

  // TODO: Call set_location() with a custom location string.
  //   This function is inherited from the trackable parent.

  return;
}

// TODO: Implement query_full_info()
//   Combines capabilities from both parents into a single
//   formatted string. This demonstrates the power of multiple
//   inheritance: the artifact "is a" describable AND "is a" trackable.
//
//   Return: artifact_name + "\n" +
//     "Description: " + query_description() + "\n" +
//     "Location: " + query_location()

// TODO: Implement query_artifact_name()
//   Artifact-specific function not in either parent.
//   Returns the artifact_name string.
