#ifndef ATOM_H_
#define ATOM_H_

//#include "Hadron/"

// The Atom class is used to help model a single atom. Note, however, that the Atom is not even close to simple.
#include "../../constants.h"
#include "../../Design/Colors.h"

// This class helps determine resistivity, number of atoms, hall effect, ect.
class Atom;

namespace MatterPhase{
enum PHASE {solid, liquid, gas, plasma};
};

// Bond between atoms
typedef struct AtomBond {
    // https://labs.chem.ucsb.edu/zakarian/armen/11---bonddissociationenergy.pdf
    
	float strength; // strength, in kJ/mol
	float length; // distance, normal in pico-meters
	
	Atom *a; // current element
	Atom *b; // connected to other element
};

// Types of elements
// Alkali Earth Metals, Alkaline Earth Metals, Halogen, Lanthanide, Metalloid, Non-Metal, Nobal Gas, Poor Metal, Actinide, Transition Metal
enum ELEMENT_TYPE {ELEM_Alkali, ELEM_Alkaline, ELEM_Halogen, ELEM_Lanthanide, ELEM_Metalloid, ELEM_NonMetal, ELEM_Noble, ELEM_Poor, ELEM_Actinide, ELEM_Transition};

class Atom {
    public:
        // 12 doubles
        Atom(const char* Name, const char* label, double Group, double Period, double Protons, double Neutrons, double Electrons, double Density, double Resistivity, double ThermConductivity, double Melting, double Boiling, double SpecificHeat, double Valence, vertex Color, ELEMENT_TYPE Type); // assign base constants
        virtual ~Atom();

        Atom* getAtom(); // get this material's atom.

        // Electrical Properties
        double getConductivity();

        // Chemical Properties
        double getAtomicNumber(); // N = p
        double getAtomicWeight(); // W = (p+n+e)
        MatterPhase::PHASE getPhase(double temp, double pressure); // get the phase of the material

        // Thermal Properties


        // Operations for bondings and ions
        bool isBondPossible(Atom* atom); // checks valence and ions
        
        Atom* clone() const; // clone, useful for Element copying
        
        
        LinkedList<AtomBond*> bonds;
        
        char* name;
        char* symbol;

        char group;
        char period;

        int protons; // also used as ID
        int neutrons;
        int electrons;
        char valence; // "bond-slots"

        double density;
        double resistivity;
        double thermal_conductivity;
        double melting_point;
        double boiling_point;
        double specific_heat;

        vertex color;
        ELEMENT_TYPE type;
};

#endif /*ATOM_H_*/
