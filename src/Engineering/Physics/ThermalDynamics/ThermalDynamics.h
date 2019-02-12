#ifndef THERMALDYNAMICS_H_
#define THERMALDYNAMICS_H_

#include "../../../Data/LinkedList.hpp"

// https://en.wikipedia.org/wiki/Table_of_thermodynamic_equations

double thermBeta(double kb, double T); // beta = kb*T
double thermTemperature(double kb, double T); // tau = kb*T
double thermTemperature2(double kb, char* U); // tau = kb*(dU/dS)
double entropy(double kb, LinkedList<double> vals); // S = -kb*sum(vals[i]*ln(vals[i]))
double pressure(char* F); // P = -(dF/dV)
double thermenergy(LinkedList<double> energies); // U = sum(E[i])
double enthalpy(double U, double p, double V); // H = U+pV



#endif /*THERMALDYNAMICS_H_*/
