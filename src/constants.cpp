#include "constants.h"


namespace physical {

    // converts KITem to string.
    CharString *getVariableFromKItem(KItem *item_) {
        KItem item = *item_;
        CharString *cc = new CharString();
        switch (item) {
            case KNormal:
                cc->set_("N", 1);
                break;
            case KDistance:
                cc->set_("xf-xi", 5);
                break;
            case KNewton:
                cc->set_("N", 1);
                break;
            case KGravity:
                cc->set_("g", 1);
                break;
            case KFriction:
                cc->set_("μ*m*g", 4);
                break;
            case KCentripetal:
                cc->set_(".5*(m*r^2)", 9);
                break;
            case KMu:
                cc->set_("μ", 1);
                break;
            case KVelocity:
                cc->set_("vi", 2);
                break;
            case KVelocityFinal:
                cc->set_("vf", 2);
                break;
            case KAcceleration:
                cc->set_("a", 1);
                break;
            case KTime:
                cc->set_("t", 1);
                break;
            case KTension:
                cc->set_("T", 1);
                break;
            case Kxi:
                cc->set_("xi", 2);
                break;
            case Kxf:
                cc->set_("xf", 2);
                break;
            case KMass:
                cc->set_("m", 1);
                break;
            default:
                // set cc to nothing.
                cc->set_("", 0);
                break;
        }

        return cc;
    }
}

namespace electrical {
    double getWatts(double volts, double amps) {
        return volts * amps;
    };
    double getAmps(double volts, double watts) {
        return watts / volts;
    };
    double getVolts(double amps, double watts) {
        return watts / amps;
    };
    double getOhms(double volts, double amps) {
        return volts / amps;
    }; // get resistance

    double Capacitance(double coulomb, double volt) {
        return coulomb / volt;
    };
    double SeriesSum(double *C, int Clen) {
        double ret = 0;
        for (int i = 0; i < Clen; i++) ret += 1 / C[i];
        return ret;
    };
    double ParallelSum(double *C, int Clen) {
        double ret = 0;
        for (int i = 0; i < Clen; i++) ret += C[i];
        return ret;
    };

}

namespace electromagnetic {
    namespace sound {
        // Returns the frequency of a specified note
        double getNote(double Letter, double Octave) {
            return Letter * Octave   * octave; // ends with Octave constant
        }
    }
}
