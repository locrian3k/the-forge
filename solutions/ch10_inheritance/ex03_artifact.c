#pragma strong_types
#include "defs.h"

//
// Exercise 10.3: Multiple Inheritance, Artifact (Child)
// Inherits from BOTH describable and trackable, combining description
// management and location tracking into a single object.
//

inherit __DIR__ + "ex03_describable";
inherit __DIR__ + "ex03_trackable";

string artifact_name;

void create()
{
  // Call BOTH parent creates using the named form.
  // A plain ::create() would only call the first parent's create.
  describable::create();
  trackable::create();

  // Now customize with artifact-specific values
  artifact_name = "The Ember Crystal";
  set_description("A crystalline shard that pulses with inner fire. "
    "Ancient runes are etched along its facets.");
  set_location("The Vault of Echoes");
  return;
}

//
// query_full_info - Combines capabilities from both parents into a
// single formatted string. This demonstrates the power of multiple
// inheritance: the artifact "is a" describable AND "is a" trackable.
//
string query_full_info()
{
  return artifact_name + "\n" +
    "Description: " + query_description() + "\n" +
    "Location: " + query_location();
}

//
// query_artifact_name - Artifact-specific function not in either parent.
// Returns the name of this particular artifact.
//
string query_artifact_name() { return artifact_name; }
