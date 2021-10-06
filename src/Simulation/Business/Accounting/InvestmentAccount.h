#ifndef INVESTMENTACCOUNT_H_
#define INVESTMENTACCOUNT_H_

#include "Account.h"
#include "Transaction.h"
#include <time.h>

class InvestmentAccount : public Account{
public:
    
    // investment information
    int compounding_days; // number of days to where a percentage compounds
    double rate; // multiplier in value
    double costbasis; // initial amount invested
    std::time_t initial_date; // date initially invested
    std::time_t last_date; // last date added extra
    
    LinkedList<Transaction> in, out;
};

#endif
