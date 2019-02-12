#include "ThermalDynamics.h"

double thermBeta(double kb, double T){ // beta = kb*T
    return 0;
}

double thermTemperature(double kb, double T){ // tau = kb*T
    return 0;
}

double thermTemperature2(double kb, char* U){ // tau = kb*(dU/dS)
    return 0;
}

double entropy(double kb, LinkedList<double> vals){ // S = -kb*sum(vals[i]*ln(vals[i]))
    return 0;
}

double pressure(char* F){ // P = -(dF/dV)
    return 0;
}

double thermenergy(LinkedList<double> energies){ // U = sum(E[i])
    return 0;
}

double enthalpy(double U, double p, double V){ // H = U+pV
    return 0;
}
