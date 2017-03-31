#ifndef RESISTOR_h_
#define RESISTOR_h_

#include "Component.h"

// Resists current in the circuit

class Resistor: private Component {
    public:
        Resistor(double Ohms, double Tolerance, double TempTolerance, PowerValue* MaxPower);
        virtual ~Resistor();

        void tick(SecondTick* tickTime); // operate time
        float getPower(); // returns power in watts. (P=I^2*R)

    private:
        double ohms; // Resistance
        double tolerance; // Percentage tolerance, 0 for none (Gold band)
        double tempTolerance; // if 5% above this point, the resistor will stop working.
        PowerValue* maxPower; // Max power this resistor can handle
};

#endif
