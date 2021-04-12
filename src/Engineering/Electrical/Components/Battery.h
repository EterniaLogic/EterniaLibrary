#ifndef BATTERY_H_
#define BATTERY_H_

// Batteries come in a selection of options.
//  each battery type determines several properties, such as rechargeability, lifespan, etc.

// Lithium Ion - Li-O- - Modern batteries, rechargeable
// Alkaline - Zn+2MnO2 - Disposable, non-rechargable
// Perfect - No losses in charging, near-instant transfer of energy, ect.
enum BatteryType {BT_LITHIUMION, BT_ALKALINE, BT_PERFECT};

namespace BATTERY_CONSTANTS{ // calculated from D batteries
    const float LIOH_AH = 111.1111; // Amp-hour per liter (Li-ion are 1/4 as good as Alkaline)
    const float ALKALINE_AH = 444.4444; // Amp-hour per liter (16 AH, 72mL/2 = 0.4444)

    const bool LIOH_Rechargable = true;
    const bool ALKALINE_Rechargable = false;
}

class Battery{
private:
    BatteryType btype;
    double surfacearea; // surface area of internal plates determine voltage
    double volume; // internal volume in liters
    
    double targetvoltage; // voltage this battery was specified for
    double charge; // Charge left in Amp-Hour
    double maxcharge; // Max Charge left in Amp-Hour (semi-constant)
    double internalresistance; // calculated based on surface area and type


    double externalvoltage;
    double externalresistance;
public:
    // figures out internal surface area, charge, etc. starts with a max charge.
    // if internal surface area is not even theoretically possible, output voltage will suffer.
    Battery(BatteryType btype, double volume, double targetvoltage);
    virtual ~Battery();
    
    double getCapacityMax(); // get max possible capacity in Amp-hours
    double getCapacity(); // get current capacity in Amp-hours
    
    double getPowerWH(); // get power left in watt-hours based on theoretical voltage and Amp-hour charge
    
    double getVoltage(); // get current output voltage
    double getAmperage(); // get output amperage
    double getOutputPower(); // get current output power
    double getInternalResistance(); // get internal resistance
    
    // discharging
    double setExternalResistance(double r); // resistance this battery sees (determines output power and power usage)
    
    // charging
    bool setExternalVoltage(double r); // if external voltage is greater than current capability, charge, true if charging
    
    
    void simulate(double dt); // seconds delta
};


#endif
