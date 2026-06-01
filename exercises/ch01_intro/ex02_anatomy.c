#include <defs.h>

inherit "/obj/treasure";

void create()  {
	::create();

	set_name("broken gem");
	set_alias(({"gem", "broken gem"}));
	set_short("a broken gem");
	set_long("A gemstone riddled with cracks. Something is wrong with it.");
	set_value(5);
	set_weight(1);

	return
}

int query_is_broken()
{
	return 1;
}
