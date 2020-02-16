#ifndef Neutron_h_
#define Neutron_h_

#include "Baryon.h"

// A neutron is a Baryon.
// Configuration:
//    u   d
//      d
namespace Chemistry{
class Neutron : protected Baryon {
        Neutron();
        virtual ~Neutron();
};
}

#endif
