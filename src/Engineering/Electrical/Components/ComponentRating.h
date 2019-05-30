#ifndef COMPONENTRATING_h_
#define COMPONENTRATING_h_

namespace Chemistry{
class Atom;
}

#include "../../Chemistry/Atom.h"
#include "../../../Emulation/SecondTick.h"
#include "../PowerValue.h"

// The Component Rating is used to define the maxima of tolerance for all factors. This includes Voltage, Amperage, Power and Temperature.

// Q ~ I^2 * R

// some integrated circuits may have multiple power ratings based on pins.

enum CR_DEATHCAUSE {CR_None, CR_OverVoltage, CR_OverCurrent, CR_OverHeat};

class ComponentRating {
public:
    ComponentRating(Chemistry::Atom* material, PowerValue* MaxPower, double MaxTemp, double Impedance); // assign base variables
    virtual ~ComponentRating();

    void tick(SecondTick* tickTime); // calculate temperature, or death due to overpower

    void setAmbientTemperature(double temp); // ambient temp may change
    void setPower(PowerValue* power); // for initial power setting


    PowerValue* maxPower(); // get maximum Power
    double getImpedance(); // get component resistance
    bool isDead(); // return dead
    CR_DEATHCAUSE getDeathCause(); // return why it died

private:
    PowerValue* currentPower;
    double ambientTemperature; // sorrounding temperature (can be used to wick heat)
    double currentTemp;
    double powerTime; // time in which power is applied

    PowerValue* powerMax; // defines max power of a component.
    double temperatureMax; // defines max temperature of a component in Celsius.
    double impedance; // resistance creates temperature when current flows through it
    Chemistry::Atom* conductorMaterial; // material that this is made of

    bool dead; // is this component dead?
    CR_DEATHCAUSE deathCause; // reason for death
};

#endif
