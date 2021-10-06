#ifndef STOCK_H_
#define STOCK_H_

#include "../Company.h"

// A single stock is a partitionable share of a business.

// Note: Stock programs are faster using assembler with a dedicated server on a fiber network.
// This is a C/C++ attemptemplation of what a stock machine does.
// Since this code is Open-source, one can just use __asm__("" \n"" :\n""); code. (where \n is newline)

class Stock{
private:
    Company* company;
    double last; // value of each share
    int count; // count of shares TOTAL in company
    
public:
    Stock();
    virtual ~Stock();
};

#endif
