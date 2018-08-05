#ifndef PAYROLL_H_
#define PAYROLL_H_
#include "../../Data/includes.h"
#include "Accounting/Transaction.h"

// Global Payroll pre-calculation for an entire segment of a company or a branch
// cannot fill in for check-signing, auto-payroll, etc.
class Payroll{
public:
    Payroll(Company *c);
    
    
    LinkedList<Transaction> calculateBudgets(); // pre-calculates transactions that need to occur
    
};

#endif
