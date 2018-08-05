#ifndef BUDGET_H_
#define BUDGET_H_

#include "../BEntity.h"

// Allocated money for employee(s) and give constraints.
class Budget{
public:
    Budget();
    LinkedList<BEntity> members; // linked employees or customer
    
    // Allocated expenses
    double travel; // travel budget
    double project; // budget for parts
    double liabilities; // wages, etc. (pre-calculated value based on # of members)
    double materials; // budget for parts
    double getTotalExpenses();
    
    // planned revenue
    double sales; // must sell this value in minimum
    double production; // # of items must be produced
    
    // time
    double period; // period in days that this budget is valid for until a renewal date (usually a year)
    CharString initial_assigned; // date assigned for this budget
};

#endif
