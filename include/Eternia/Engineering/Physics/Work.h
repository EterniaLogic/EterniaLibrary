//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Work_h
#define Work_h
#include "../../Data/LinkedList.hpp"
#include "../../constants.h"

using namespace physical;
class EnergyValue
{
public:
    EnergyValue(KEnergyType type, double value);
    KEnergyType energyType; // PotentialGravEnergy, PotentialSpringEnergy, KineticTEnergy, KineticREnergy
    double Gravity, heightx, velocity, RotVelo, springK; // input vars.
    
    double computeEnergy(); // solve for the total energy
    bool unsolvedVars(); // does this have unsolved variables?
};

class Work
{
private:
    // Potential Energy due to gravity
    // Potential Energy due to Spring
    // Translational Kinetic Energy
    // Rotational Kinetic Energy
    double mass, TEnergy; // stored mass (Since mass doesn't normally change)
public:
    LinkedList<EnergyValue>* listOfTypes;
    Work(double Mass);
    double compute(); // Compute the energy of the system
    double getTotalWatts(double time); // divides joules by time
    
};

#endif