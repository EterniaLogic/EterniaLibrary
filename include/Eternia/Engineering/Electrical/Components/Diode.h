#ifndef Diode_h_
#define Diode_h_

#include "Component.h" // << includes PowerValue and SecondTick

// a diode restricts current from flowing in one direction.

enum DIODETYPE {DIODE, Zener_DIODE, Avalanche_DIODE, LIghtEmitting_DIODE, PNJunct_DIODE, Laser_DIODE, Schottky_DIODE, Photo_DIODE, Tunnel_DIODE, Varicap_DIODE, Gunn_DIODE, Thermal_DIODE, Stabistor_DIODE};

class Diode : private component {
    public:
        Diode(DIODETYPE Type); // define diode type for output
        virtual ~Diode();


    private:
        DIODETYPE type;
};

#endif
