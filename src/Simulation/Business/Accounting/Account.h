#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "../../../Data/includes.h"

enum ACCOUNT_TYPE {ACC_CHECKING, ACC_SAVINGS, ACC_CD, ACC_INVESTMENT, ACC_MUTUALFUND};

// Bank Account
// (use InvestmentAccount for CD Investing or mutual funds)

// does not include login information for online accounts
class Account{
public:
    int account_number;
    int institution_number;
    CharString account_name, institution_name;
    
    double value; // money stored in the account (Estimated)
    ACCOUNT_TYPE type;
};

#endif
