/*
  ex01_string_funcs.c
  YourName YYMMDD
  Exercise 12.1 — String Toolbox
  A utility object with common string manipulation functions
  using LPC driver efuns.
*/
#pragma strong_types
#include "../defs.h"

// TODO: Add function prototypes for all three functions below.

// TODO: Implement title_case(string s)
//   Capitalize the first letter of every word in a string.
//   Steps:
//     1. Use explode(s, " ") to split into an array of words
//     2. Loop through the array, calling capitalize() on each word
//     3. Use implode(words, " ") to rejoin with spaces
//   Example: "hello world" -> "Hello World"

// TODO: Implement word_count(string s)
//   Count the number of words in a string.
//   Steps:
//     1. Handle edge cases: if s is 0 (null) or "", return 0
//     2. Use explode(s, " ") to split, then sizeof() to count
//   Example: "the quick brown fox" -> 4

// TODO: Implement pad_right(string s, int width)
//   Pad a string with trailing spaces to reach the given width.
//   Steps:
//     1. If strlen(s) >= width, return s as-is
//     2. Otherwise use sprintf() with a left-aligned format to pad
//   Example: pad_right("gold", 10) -> "gold      "
