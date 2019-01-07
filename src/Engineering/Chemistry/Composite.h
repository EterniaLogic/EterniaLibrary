#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include "Atom.h"
#include "elements.h"
#include "../../Data/includes.h"

#include <vector>



class Composite {
    public:
        Composite();
        Composite(MatterPhase::PHASE phase, double density, double mass, const std::vector<Atom*> atoms);
        Composite(CharString c); // CompositeTypeString {phase, density, mass, {atoms}}
        virtual ~Composite();
        
        LinkedList<Atom*> atoms; // first atom in the Composite

        MatterPhase::PHASE phase;
        double density; // used for stuff like atmospheres, ect, kg/m^3
        double totalMass; // total composite molar mass (g/mol)
        
        CharString getString(); // convert to CompositeTypeString
};



namespace CompositeGas{
    const Composite co2("{2|1.980000|44.010000|{0\\6|1\\8|2\\8},{0,749.000000,116.300003,1'0,749.000000,116.300003,2}}");
    const Composite o2("{2|1.429000|31.999000|{0\\8|1\\8},{0,498.000000,121.000000,1}}");

    void printCompositeGasses();
};

#endif /*COMPOSITE_H_*/
