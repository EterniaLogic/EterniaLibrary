#ifndef INVESTMENTACCOUNT_H_
#define INVESTMENTACCOUNT_H_

#include "Account.h"

class InvestmentAccount : public Account{
public:
    
    // investment information
    int compounding_days; // number of days to where a percentage compounds
    double rate; // multiplier in value
    double initial_value; // initial amount invested
    CharString initial_date; // date initially invested
    CharString additional_date; // last date added
};

#endif
