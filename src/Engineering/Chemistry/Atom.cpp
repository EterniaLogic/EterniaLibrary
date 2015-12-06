//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Atom.h"

using namespace physical::constant; // from constants.h

// assign base constants
Atom::Atom(const char* Name, const char* label, double Group, double Period, 
      double Protons, double Neutrons, double Electrons, double Density, 
      double Resistivity, double ThermConductivity, double Melting, 
      double Boiling, double SpecificHeat, double Valence, vertex Color, ELEMENT_TYPE Type){
  name = (char*)Name;
  symbol = (char*)label;
  
  group = Group;
  period = Period;
  
  protons = Protons;
  neutrons = Neutrons;
  electrons = Electrons;
  valence = Valence;
  
  // Properties
  density = Density;
  resistivity = Resistivity;
  thermal_conductivity = ThermConductivity;
  melting_point = Melting;
  boiling_point = Boiling;
  specific_heat = SpecificHeat;
  
  color = Color; // visible color at room temperature
  type = Type; // Periodic group type
  
}
Atom::~Atom(){}

Atom* Atom::getAtom(){} // get this material's atom.

// Electrical Properties
double Atom::getConductivity(){return 1/resistivity;}

// Chemical Properties
 // N = p
double Atom::getAtomicNumber(){
        return protons;
}

// W = (p+n+e)
double Atom::getAtomicWeight(){
  return protons*m_P + neutrons*m_P + electrons*m_e;
}

// get the phase of the material (Temp in Celcius)
CHEMPHASE Atom::getPhase(double temp, double Pressure){
  double T = temp+273.15;
  // Ideal Gas Law PV = nRT
  // R = 8.31  =>  Gas Constant
  // T  =>  Temp in Kelvin
}
