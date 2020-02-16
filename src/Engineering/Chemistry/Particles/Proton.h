#ifndef Proton_h_
#define Proton_h_

#include "Baryon.h"

// A proton is a Baryon.
// Configuration:
//      u
//    d   d
namespace Chemistry{
class Proton: public Baryon {
        Proton();
        virtual ~Proton();
};
}
#endif
