#pragma strong_types
#include "defs.h"

//
// Exercise 7.1: Branch Logic
// Implements weather description using both if/else and switch/case
// to demonstrate equivalent branching approaches.
//

void create()
{
  return;
}

//
// describe_weather_if - Returns a weather description using if/else.
// Maps integer codes to weather strings.
//
string describe_weather_if(int code)
{
  if (code == 0)
    return "clear";
  else if (code == 1)
    return "cloudy";
  else if (code == 2)
    return "rainy";
  else if (code == 3)
    return "stormy";
  else if (code == 4)
    return "snowy";
  else
    return "unknown";
}

//
// describe_weather_switch - Returns a weather description using
// switch/case. Produces identical output to the if/else version.
// Each case uses break; to prevent fall-through.
//
string describe_weather_switch(int code)
{
  string result;

  switch (code)
  {
    case 0:
      result = "clear";
      break;
    case 1:
      result = "cloudy";
      break;
    case 2:
      result = "rainy";
      break;
    case 3:
      result = "stormy";
      break;
    case 4:
      result = "snowy";
      break;
    default:
      result = "unknown";
      break;
  }
  return result;
}
