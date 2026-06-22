#pragma strong_types
#include "../defs.h"

// String Toolbox - utility object with common string
// manipulation functions using LPC driver efuns.

// Function prototypes
string title_case(string s);
int word_count(string s);
string pad_right(string s, int width);

// Capitalize the first letter of every word in a string.
// Splits on spaces, capitalizes each piece, then rejoins.
//   "hello world" -> "Hello World"
string title_case(string s)
{
  string *words;
  int i;

  words = explode(s, " ");
  for (i = 0; i < sizeof(words); i++)
    words[i] = capitalize(words[i]);
  return implode(words, " ");
}

// Count the number of words in a string.
// Returns 0 for an empty string.
int word_count(string s)
{
  if (!s || s == "")
    return 0;
  return sizeof(explode(s, " "));
}

// Pad a string with trailing spaces to reach the given width.
// If the string is already at or beyond width, return it as-is.
//   pad_right("gold", 10) -> "gold      "
string pad_right(string s, int width)
{
  if (strlen(s) >= width)
    return s;
  return sprintf("%-*s", width, s);
}
