//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Tax_h
#define Tax_h
#include "TaxRefund.h" // enables governments to give money back to players as part of money not used.


// Enables governments to tax players
class Tax {
        double Income, Trade, Sales;
    public:
        Tax(double incomeTax, double tradeTax, double salesTax);

        // Generic get/set functions
        void setIncomeTax(double percent);
        void setTradeTax(double percent);
        void setSalesTax(double percent);

        double getIncomeTax();
        double getTradeTax();
        double getSalesTax();
};

#endif
