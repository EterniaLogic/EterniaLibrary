#ifndef LINEOFCREDIT_H_
#define LINEOFCREDIT_H_

#include "../Accounting/Liability.h"

// a lump sum is a direct debt which must be paid in full by a specific date or 
//  it the interest rate must be paid.

class LumpSum : public Liability{
private:
    // inherits  double interest_rate;
};

#endif
