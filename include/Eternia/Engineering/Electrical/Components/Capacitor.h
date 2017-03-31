#ifndef Capacitor_h_
#define Capacitor_h_

#include "Component.h"

// A capacitor stores charge between two plates.

class Capacitor : private Component {
    public:
        Capacitor(double farads, double max_volts);
        virtual ~Capacitor();

        void tick(SecondTick* tickTime); // operate time

    private:
        double Farads; // Capacitor rating
        double maxVolts;
};

#endif
