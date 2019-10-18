#ifndef GASSEPARATOR_H_
#define GASSEPARATOR_H_


#include "Workshop.h"
class GasSeparator : public Workshop{
public:
    GasSeparator(){
        classname="GasSeparator";

        // Gas separators separate out mixed gasses, such as HGLs, Still Gasses and other products such as hydrogen.

        // Swing adsorption techniques (Pressure/Vacuum/Temperature)
        //      under high pressure, gases tend to be attracted to solid surfaces
        // Membrane Gas separation (Using special membranes, but pretty slow compared to the swing methods)

        recipes.add(new Recipe("1L HGL","", 2400)); // Ethane, Propane, Butane, etc.
    }
};

#endif
