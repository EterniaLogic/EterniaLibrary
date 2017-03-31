//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

// Banking keeps track of money (obviously) through millions of number-based accounts.
// Loans have a % interest rate for a defined time period.
// Interest rate is defined by in-game players.

#include "../../Data/SecureFileCache.hpp"
#include "../../Data/Protect/PType.hpp"
#include "../../Data/CharString.h"
#include "Account.h"



// Advanced account, such as a CD
// Sub-accounts stored in a secure FileCache for long-period chunk processing
// This system enables millions of accounts in the bank, which is computed and secured
// by multiple server sub-systems



// Advanced Banking System
class Banking {
    public:
        Banking();

        void tick(); // tick for each game tick
    private:
        double totalvalue; // total bank value in crypto-currency
        LinkedList<Account> accounts; // list of loaded accounts
};
