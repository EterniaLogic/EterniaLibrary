#ifndef LIABILITY__H
#define LIABILITY__H

enum LIABILITY_CLASS {LC_CURRENT, LC_LONGTERM};
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
    
    double value;
    
    
    // DEBTS
    double rate; // rate of change over period in percentage. 25% rate would increase $1,000 to $1,250 over a year for example. (1.25 = 25%)
    double period; // days unto which a debt increases (monthly, yearly, etc.)
    CharString last_loan_payment_date; // for loans
};

#endif
