//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Tax.h"


// Basic load
Tax::Tax(double incomeTax, double tradeTax, double salesTax){
    Income = incomeTax;
    Trade = tradeTax;
    Sales = salesTax;
}
    
    
// Generic get/set functions
// set income tax
void Tax::setIncomeTax(double percent){
    Income = percent;
}

// set trade tax
void Tax::setTradeTax(double percent){
    Trade = percent;
}

// set sales tax
void Tax::setSalesTax(double percent){
    Sales = percent;
}


// return income tax
double Tax::getIncomeTax(){
    return Income;
}

// return Trade tax
double Tax::getTradeTax(){
    return Trade;
}

// return sales tax
double Tax::getSalesTax(){
    return Sales;
}
