#ifndef TEMPVISCOSITY_H_
#define TEMPVISCOSITY_H_


class TempViscosityPoint{
private:

public:
    double temperature; // kelvin
    double viscosity; // mPa*second
    
    TempViscosityPoint(double temperature, double viscosity)
    {
        this->temperature=temperature;
        this->viscosity=viscosity;
    }
};

#endif
