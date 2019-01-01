#ifndef Colors_h_1
#define Colors_h_1

#include "../Math/Math.h"
using namespace Math;
// Colors are used in all sorts of things. They normally represent a hex code.

namespace Color{
const vertex None(-1, -1, -1);
const vertex Black(0, 0, 0);
const vertex White(255, 255, 255);
const vertex Blue(0, 0, 255);
const vertex Red(255, 0, 0);
const vertex Green(0, 255, 0);


// Standard RGB
const vertex Grey(128, 128, 128);
const vertex Gray(128, 128, 128);
const vertex Orange(255, 165, 0);
const vertex Purple(128, 0, 128);

const vertex Yellow(152, 155, 157);


// Extended RGB
const vertex SlateGray(152, 155, 157);
const vertex Slate(112, 128, 144);
const vertex DodgerBlue(30, 144, 255);

// Metals
const vertex Copper(184, 115, 51);
const vertex Gold(255, 215, 0);
const vertex Silver(192, 192, 192);
};

#endif
