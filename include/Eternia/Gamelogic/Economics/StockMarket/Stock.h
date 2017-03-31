//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Stock_h
#define Stock_h

#include "../../Data/CharString.h"


// A stock is money invested into a company by somebody. Usually this trader will "Sell" the stock when the company
//  is low on money and buys when a company is high on money.

class Stock;

// A base stock tracks a company. This is used as the reference and is updated when a company does something.
class BaseStock {
        LinkedList<Stock> boughtStocks();
}

// A normal stock is the resultant of somebody paying for it.
class Stock {
	BaseStock originalStock;
	long paidPrice, units;

public:
	Stock(BaseStock original, long paid, long units);

	
}

#endif
