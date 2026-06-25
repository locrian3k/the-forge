/*
  ex03_artifact.c
  YourName YYMMDD
  Exercise 10.3 — Multiple Inheritance, Artifact (Child)
  Inherits from BOTH describable and trackable, combining description
  management and location tracking into a single object.
*/
#pragma strong_types
#include "../defs.h"

// TODO: Inherit BOTH parent files (ex03_describable and ex03_trackable)
//   Use __DIR__ + "filename" to build each path.

// TODO: Declare a global string variable: artifact_name

void create()
{
  // TODO: Call BOTH parent creates using the named form.
  //   A plain ::create() would only call the first parent's create.
  //   Syntax: parentname::create();

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
//   Include the artifact name, the description from the describable
//   parent, and the location from the trackable parent.

// TODO: Implement query_artifact_name()
//   Artifact-specific function not in either parent.
//   Returns the artifact_name string.
