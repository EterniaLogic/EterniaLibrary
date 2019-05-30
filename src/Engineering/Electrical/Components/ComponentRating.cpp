#include "ComponentRating.h"
#include <math.h>

ComponentRating::ComponentRating(Chemistry::Atom* material, PowerValue* MaxPower, double MaxTemp, double Impedance) {
    temperatureMax = MaxTemp;
    powerMax = MaxPower;
    impedance = Impedance;

    currentPower = 0x0; // zip power going through
    ambientTemperature = 0; // unknown temperature
    conductorMaterial = material;

    dead = false;
    deathCause = CR_None;
}

ComponentRating::~ComponentRating() {
    currentPower = 0x0;
    ambientTemperature = 0;

    powerMax = 0x0;
    temperatureMax = 0;
    impedance = 0;
    conductorMaterial = 0x0;

    dead = 0;
    deathCause = CR_None;
}

// calculate temperature, or death due to overpower
void ComponentRating::tick(SecondTick* tickTime) {
    // Change in time
    double ch_time = tickTime->getTime();
    // Add up total running time
    powerTime += ch_time;
    // calculate temperature increase in ellapsed time
    currentTemp = currentTemp + ch_time * pow(currentPower->getWatts(), 2);

    // Dissipation of Heat due to air
    // use surface area of component

    //

    if(currentTemp > temperatureMax) {
        deathCause = CR_OverHeat;
        dead=true;
    }//else if(){

    //}
}


// ambient temp may change
void ComponentRating::setAmbientTemperature(double temp) {
    ambientTemperature = temp;
}

// for initial power setting
void ComponentRating::setPower(PowerValue* power) {
    currentPower = power;
}


// get maximum Power
PowerValue* ComponentRating::maxPower() {
    return powerMax;
}
// get component resistance
double ComponentRating::getImpedance() {
    return impedance;
}
// return dead
bool ComponentRating::isDead() {
    return dead;
}
// return why it died
CR_DEATHCAUSE ComponentRating::getDeathCause() {
    return deathCause;
}
