#ifndef MARGINHOLDER_H_
#define MARGINHOLDER_H_


#include "AssetHolder.h"
#include "Accounting/Liability.h"
#include "Accounting/Margin.h"
// Margin Holders have enabled margin (aka, can take out loans way beyond their initial
//                                      means to pay off)


class MarginHolder : public AssetHolder{
private:

public:
    // Standard lists for accounting
    LinkedList<Liability> liabilities; // Debts, obligations, issued payments, etc.
    
    double creditscore; // calculated credit score, either directly given.
    double average_risk_profit; // average risk/profit ratio from trades.

    Margin calculateMargin();
};


#endif
