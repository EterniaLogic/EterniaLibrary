

#include "RotationalFuncs.h"

namespace Rotational {
    double getTorque(double radius, double force) {
        return radius*force;
    }

    // Angular momentum
    double getAngularMomentum(double I, double angularVelo) {
        return I*angularVelo;
    }

    // moment of inertia: I
    double getMomentOfIntertia(IType inertialType, double M, double r) {
        double vv = 0;
        switch(inertialType) {
            case ISphere:
                vv = 2/3;
                break;
            case IBall:
                vv = 2/5;
                break;
            case IRod:
                vv = 1/12;
                break;
            case IDisc:
                vv = 1/2;
                break;
            case ICylinder:
                vv = 1/2;
                break;
        }

        return vv*M*r*r;
    }
}
