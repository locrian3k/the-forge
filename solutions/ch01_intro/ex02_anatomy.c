/*
  ex02_anatomy.c
  Mimic 260315
  Exercise 1.2 — Anatomy of an LPC File (corrected)
  Find and fix every bug in a broken LPC file.

  Fixes applied:
    1. Added file header comment block
    2. Added #pragma strong_types as first non-comment line
    3. Changed <defs.h> to "defs.h"
    4. Moved opening brace of create() to its own line (Allman style)
    5. Replaced all tabs with 2-space indentation
    6. Added missing semicolon after return in create()
    7. Changed query_is_broken return type from int to status
    8. Fixed tab indentation in query_is_broken
*/
#pragma strong_types
#include "defs.h"

inherit "obj/treasure";

void create()
{
  ::create();

  set_name("broken gem");
  set_alias(({"gem", "broken gem"}));
  set_short("a broken gem");
  set_long("A gemstone riddled with cracks. Something is wrong with it.");
  set_value(5);
  set_weight(1);

  return;
}

status query_is_broken() { return 1; }
