//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
#ifndef PowerValue_h_
#define PowerValue_h_

// The PowerValue defines the Wattage of a system, along with some solver methods for getting voltage, ect.

// Used for special declarations
#define VOLTS unsigned int
#define AMPS unsigned char

class PowerValue {
    public:
        PowerValue(double Voltage, double Amperes); // set wattage knowning the voltage and amps
        PowerValue(double Voltage, double Watts, VOLTS); // Set wattage knowning the watts and voltage
        PowerValue(double Amperes, double Watts, AMPS); // Set wattage knowning the watts and amps
        virtual ~PowerValue();


        // Get/set functions for private variables
        // Automatically applies power law
        void setVoltage(double Voltage);
        void setAmperage(double Amperes);
        double getVoltage();
        double getAmperage();
        double getWatts();
        double getResistance(); // gets the known resistance

    private:
        double voltage; // Applied voltage
        double amperage; // Applied amperes
        double wattage; // Raw wattage in this point on the curcuit. (Auto-assigned)

        void setPower(); // Power Law
};

#endif
