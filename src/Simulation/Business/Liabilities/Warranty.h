#ifndef WARRANTY_H_
#define WARRANTY_H_

#include <ctime>
#include <time.h>

class Warranty : public Liability{
private:
    double years; // days warranty is active (usually measured in years)
    // inherits std::time_t startdate, expirydate;
public:
};

#endif
