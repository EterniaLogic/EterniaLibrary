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
#include "../../MiscLib/CharString.h"
#include "Account.h"

enum interestTYPE {Interest_HOURLY, Interest_DAILY, Interest_WEEKLY, Interest_MONTHLY, Interest_YEARLY};
enum accountATTRIBUTE {ACCATT_Account, ACCATT_Loan};

// Advanced account, such as a CD
// Sub-accounts stored in a secure FileCache for long-period chunk processing
// This system enables millions of accounts in the bank, which is computed and secured
// by multiple server sub-systems
class AccountType
{
public:
  AccountType();
  
  void recieveAccounts(CharString* encrypted);
  
  void tick(); // tick the accounts in the secure cache (Modified time based on interest type)
private:
  //>>>>> SecureFileCache<Account>* accounts;
  double interest;
  interestTYPE interest_type;
  
  accountATTRIBUTE main_attribute; // account or a loan?
};


// Advanced Banking System
class Banking
{
public:
  Banking();
  
  void tick(); // tick for each game tick
private:
  LinkedList<AccountType>* AccountTypes; // List of lists
};