#ifndef LIABILITY__H
#define LIABILITY__H

#include <ctime>
#include <time.h>

// Holdings are when someone puts money into your company to invest
// Short term are for lump sums which are payable in a year
enum LIABILITY_CLASS {LC_HOLDING, LC_SHORTTERM, LC_LONGTERM}; 

// 
enum LIABILITY_TYPE {
    LT_WAGE, LT_TAX, LT_ACCOUNTS_PAYABLE, // Current, easily liquidatable
    LT_BOND, LT_LEASE, LT_MORTGAGE, LT_LOAN, // debts
    LT_INSURANCE, LT_NOTES_PAYABLE, LT_PENSION, LT_WARRANTY, LT_HEALTHCARE, LT_COMPENSATION, // Long-term
    LT_DEF_REVENUES, LT_DEF_INCOME_TAX, // 
    LT_SHARE_CAPITAL // for PLC
};


// A company's legal financial debts or obligations that arise during the course of business operations.
class Liability{
public:
    LIABILITY_CLASS ctype;
    LIABILITY_TYPE type;
    
    
    virtual double getValue(); // current value not including paid interest
    virtual double paidInterest(); // sums up payments
    
    
    double costbasis; // the current sum from all original transactions
    
    // Transactions related
    // costbasis_requests -- a request for more debt
    // lost_money -- spent the money
    // gain_money -- dividends
    LinkedList<Transaction> interestpayments, costbasis_requests, lost_money, gain_money;
    
    
    // DEBTS
    double interest_rate; // rate of change over period in percentage. 25% rate would increase $1,000 to $1,250 over a year for example. (1.25 = 25%)
    double compound_period; // days unto which a debt compounds (monthly, yearly, etc.)
    std::time_t startdate, expirydate; // unix time start/expiration time
};

#endif
