#include "ViscosityCurve.h"
#include <math.h>
// assumes data will be entered incrementally
ViscosityCurve::ViscosityCurve(){
    this->lowesttemp = 0;
    this->A = 0;
    this->B = 0;
    this->C = 0;
    this->V = 0;
}

// Flat Viscosity (inaccurate, but ok for games or w/e)
ViscosityCurve::ViscosityCurve(double Viscosity){
    this->lowesttemp = 0;
    this->A = 0;
    this->B = 0;
    this->C = 0;
    this->V = Viscosity;
}

// assumes data already solved for.
ViscosityCurve::ViscosityCurve(double A, double B, double C, double freezingtemp, bool gas){
    this->lowesttemp = freezingtemp;
    this->A = A;
    this->B = B;
    this->C = C;
    this->V = 0;
    this->gas = gas;
}

// List of points in temperature and viscosity.
ViscosityCurve::ViscosityCurve(LinkedList<TempViscosityPoint*> points, double lowesttemp, bool gas){
    this->lowesttemp = lowesttemp;
    this->V = 0;
    this->gas = gas;
    if(gas) solveGasCurve(points);
    else solveLiquidCurve(points);
}

double runviscosity(double A, double B, double T, double C){
    double E = (double)physical::constant::e;
    double x = (B/(T-C));
    double val = A * std::pow(E, x);
    //cout << "A=" << A << " B=" << B << " T=" << T << " C=" << C << "    =    " << val << endl;
    return val;
}


// Gases are the opposite of Liquids.
//  They become more viscous the hotter they get.
void ViscosityCurve::solveGasCurve(LinkedList<TempViscosityPoint*> points){
    this->A = 0;
    this->B = 0;
    this->C = 0;
    
}

// Solve extrapolation for equation Mu = Ae^(B/(T-C))
// only 70-95% accurate depending on the given curve data, but relatively fast to interpolate for several materials.
void ViscosityCurve::solveLiquidCurve(LinkedList<TempViscosityPoint*> points){
    this->A = 0;
    this->B = 0;
    this->C = 0;
    
    
    
    
    double N_a = 6.02214076e23; // avogardo  1/mol
    double h = 6.62607015e-34; // Planck     J/s
    double V = 0.018; // volume of mole of liquid (Liters)
    double T_b = 373.2; // boiling point    Kelvin
    // Joule/(Atom/liter*seconds)/liters = Joule/atom.seconds
    //double Mu = (N_a*h/V)e^(3.8*T_b/T);
    // \frac{\left(6.02214076\cdot10^{23}\cdot6.62607015\cdot10^{-34}\right)}{0.018}\cdot e^{\left(3.8\cdot\frac{100}{x}\right)}
    
    
    // Mu = Ae^(B/(T-C))
    double AAcc =0, BAcc=0, CAcc=0;
    double ATemp = 0.01;
    double BTemp = 100.;
    double CTemp = 100.;
    
    int attempts=10; // re-runs the solver for better accuracy
    int attempts2=100000; // higher = more accurate for extremes, but longer time
    int accuracy=4; // higher = more accurate in terms of decimals, but longer
    points.freeze(); // makes getting data faster 
    
    // Loop though # of attempts
    for(int _x = 0; _x<attempts;_x++){
        double diff=_x+1;
        AAcc = 0.01/diff;
        BAcc = 100./diff;
        CAcc = 100./diff;
        for(int _a = 0; _a<accuracy;_a++){
            
            // Loop through points
            for(int _b = 0; _b<attempts2;_b++){
                for(int p=0;p<points.frozenlen;p++){
                    TempViscosityPoint* point = points[p];
                    double visc = point->viscosity;
                    double temperature = point->temperature;
                    // Loop through plausible A/B/C in large units first
                    
                    // Loop though # of attempts
                
                    double ATemp_ = ATemp;
                    double BTemp_ = BTemp;
                    double CTemp_ = CTemp;
                
                    // run and check if value is closer
                    // initial greater than temp and Arp is lower, yet still greater
                    double v = runviscosity(ATemp, BTemp, temperature, CTemp);
                    double Arp = runviscosity(ATemp + AAcc, BTemp, temperature, CTemp); // add accuracy
                    double Arn = runviscosity(ATemp - AAcc, BTemp, temperature, CTemp); // remove accuracy
                    ATemp = (v > visc && Arp > visc && Arp < v) ? ATemp+AAcc : // find solution if applicable
                            (v < visc && Arn < visc && Arn > v) ? ATemp-AAcc :
                            ATemp;
                    
                    // re-run initial settings
                    v = runviscosity(ATemp, BTemp, temperature, CTemp);
                    double Brp = runviscosity(ATemp, BTemp + BAcc, temperature, CTemp);
                    double Brn = runviscosity(ATemp, BTemp - BAcc, temperature, CTemp);
                    BTemp = (v > visc && Brp > visc && Brp < v) ? BTemp+BAcc :
                            (v < visc && Brn < visc && Brn > v) ? BTemp-BAcc :
                            BTemp;
                    
                    v = runviscosity(ATemp, BTemp, temperature, CTemp);
                    double Crp = runviscosity(ATemp, BTemp, temperature, CTemp + CAcc);
                    double Crn = runviscosity(ATemp, BTemp, temperature, CTemp - CAcc);
                    CTemp = (v > visc && Crp > visc && Crp < v) ? CTemp+CAcc :
                            (v < visc && Crn < visc && Crn > v) ? CTemp-CAcc :
                            CTemp;
                    
                    
                    // escape if no difference
                    if(ATemp_ == ATemp && BTemp_ == BTemp && CTemp_ == CTemp){
                        _b = attempts2+100;
                        break;
                    }
                }
                
            }
            AAcc /= 10;
            BAcc /= 10;
            CAcc /= 10;
            //cout << "endacc " << _a << endl;
        }
        //cout << "endrun" << endl;
    }
    A = ATemp;
    B = BTemp;
    C = CTemp;
    printf("Constants: %4.6f %4.6f %4.6f\n", A, B, C);
}

// get viscosity from Kelvin temperature
float ViscosityCurve::getViscosity(float temperature){
    if(temperature < lowesttemp){
        return INFINITY;
    }else{
        return runviscosity(A, B, temperature, C);
    }
}

double ViscosityCurve::getA(){
    return A;
}
double ViscosityCurve::getB(){
    return B;
}
double ViscosityCurve::getC(){
    return C;
}
double ViscosityCurve::getLowestTemp(){
    return lowesttemp;
}
