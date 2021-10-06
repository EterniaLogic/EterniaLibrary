#ifndef CREDITCARD_H_
#define CREDITCARD_H_

#include "../Accounting/Liability.h"

// a credit card is like an on-demand credit/debt to be paid within the month.
//  to prevent fraud they usually track the cards via phone GPS.

class CreditCard : public Liability{
private:
    long cardnumber;
    unsigned char exp_month, exp_day;
    CharString holdername; // name on card
public:
    
};

#endif
