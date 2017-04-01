//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Company_h
#define Company_h

#include "../StockMarket/Stock.h"

#include "..//Government/Government.h"

#include "CompanyConst.h"

class Company {
        long IncomeTotal; // used for government tax
        BaseStock companyStock;
        Government government; // what side is this company on?
        COMPANYTYPE CompanyType; // type of company (ie: mining or broker?)

    public:
        Company(CharString name, COMPANYTYPE type);
};

#endif