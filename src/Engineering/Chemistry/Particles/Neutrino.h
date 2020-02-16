#ifndef Neutrino_h_
#define Neutrino_h_


#include "BaseParticle.h"

// Fermions
// Electron neutrino / antineutrino
// Muon neutrino / antineutrino
// Tau neutrino / antineutrino
namespace Chemistry{
class Neutrino : public BaseParticle {
        Neutrino(){spin=0.5;charge=0;}
        virtual ~Neutrino();
};
}
#endif
