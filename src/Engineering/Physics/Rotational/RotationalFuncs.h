#ifndef ROTATIONAL_FUNCS_H_
#define ROTATIONAL_FUNCS_H_

namespace Rotational {
    enum IType {ISphere, IBall, IRod, IDisc, ICylinder};


    double getTorque(double radius, double force);
    double getAngularMomentum(double I, double angularVelo);
    double getMomentOfIntertia(IType inertialType, double M, double r);
}

#endif
