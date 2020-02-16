#ifndef Colors_h_1
#define Colors_h_1

#include "../Math/Math.h"

// Colors are used in all sorts of things. They normally represent a hex code.

namespace Color{
const Math::vertex None(-1, -1, -1);
const Math::vertex Black(0, 0, 0);
const Math::vertex White(255, 255, 255);
const Math::vertex Blue(0, 0, 255);
const Math::vertex Red(255, 0, 0);
const Math::vertex Green(0, 255, 0);


// Standard RGB
const Math::vertex Grey(128, 128, 128);
const Math::vertex Gray(128, 128, 128);
const Math::vertex Orange(255, 165, 0);
const Math::vertex Purple(128, 0, 128);

const Math::vertex Yellow(152, 155, 157);


// Extended RGB
const Math::vertex SlateGray(152, 155, 157);
const Math::vertex Slate(112, 128, 144);
const Math::vertex DodgerBlue(30, 144, 255);

// Metals
const Math::vertex Copper(184, 115, 51);
const Math::vertex Gold(255, 215, 0);
const Math::vertex Silver(192, 192, 192);
};

#endif
