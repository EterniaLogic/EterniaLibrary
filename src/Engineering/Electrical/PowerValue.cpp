
#include "PowerValue.h"

// set wattage knowning the voltage and amps
PowerValue::PowerValue(double Voltage, double Amperes) {
    voltage = Voltage;
    amperage = Amperes;
    setPower();
}

// Set wattage knowning the watts and voltage
PowerValue::PowerValue(double Voltage, double Watts, VOLTS) {
    voltage = Voltage;
    wattage = Watts;

    // P = I*V  =>  I=P/V
    amperage = wattage/voltage;
}

// Set wattage knowning the watts and amps
PowerValue::PowerValue(double Amperes, double Watts, AMPS) {
    amperage = Amperes;
    wattage = Watts;

    // P = I*V  =>  V=P/I
    voltage = wattage/amperage;
}

PowerValue::~PowerValue() {
    wattage = 0;
    voltage = 0;
    amperage = 0;
}

// Automatically applies power law
void PowerValue::setVoltage(double Voltage) {
    voltage = Voltage;
    setPower();
}

// Automatically applies power law
void PowerValue::setAmperage(double Amperes) {
    amperage = Amperes;
    setPower();
}

// Return voltage
double PowerValue::getVoltage() {
    return voltage;
}

// Return Amps
double PowerValue::getAmperage() {
    return amperage;
}

// Return Power
double PowerValue::getWatts() {
    return wattage;
}

// Return known resistance
double PowerValue::getResistance() {
    // I = V/R
    // R = V/I
    return voltage/amperage;
}

// set Wattage
void PowerValue::setPower() {
    // P = V*I
    wattage = voltage*amperage;
}
