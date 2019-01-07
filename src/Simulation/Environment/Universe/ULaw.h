#ifndef ULAW_H
#define ULAW_H

enum ULAWT {UL_ENERGY, UL_MATTER, UL_MIND, UL_PHYS, UL_DIMENSIONS, UL_LAW};
#include "../../../Data/CharString.h"

// Universal laws begin with the smallest units.
//  - Strings form string theory or cirles or w/e.
//  - All matter attracts other matter? (Gravity, F=G(mM)/r)


class ULaw{
public:
    ULAWT type;
    CharString name;
    ULaw(ULAWT type, CharString name);
};

#endif
