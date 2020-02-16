#ifndef MESON_h_
#define MESON_h_

#include "Baryon.h"

// A Baryon is either a Proton or a Neutron that is made of 3 quarks.
namespace Chemistry{
class Meson : public Baryon {
        Meson();
        virtual ~Meson();
};
}
#endif
