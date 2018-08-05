#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include "Atom.h"

enum STATE {solid, liquid, gas, plasma};

// Bond between atoms
class AtomBond {
private:
	float strength; // strength, in kJ/mol
	float length; // distance, normal in pico-meters
	
	Atom *a, *b;
};

class Composite {
    public:
        Composite();
        virtual ~Composite();

        STATE Type;
        double density; // used for stuff like atmospheres, ect.
        double totalMass; // total composite mass
};

#endif /*COMPOSITE_H_*/
