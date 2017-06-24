#ifndef Inductor_h_
#define Inductor_h_

#include "Component.h"

// An inductor resists change in current; current eventually reaches zero over time.

class Inductor : private Component {
private:
    float inductance;
    float energy; // energy currently charged, in Joules.
    float current, voltage; // current voltage/current values.
public:
    // Float values in meters
    Inductor(int wraps, float width, float length, float spacing); // generates an inductor value based on inputs
    Inductor(float inductance); // values in henrys
    
    
    void tick(SecondTick* tickTime); // operate time
    
    float getImpedance(float frequency); // get impedance of this inductor from a specific sine wave frequency. (Assumes perfect sine wave)
};

#endif
