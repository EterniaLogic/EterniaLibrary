#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "../../../Data/includes.h"
#include "../Assets/Asset.h"

// only Checking and savings are insured by FDIC
enum ACCOUNT_TYPE {ACC_CHECKING, ACC_SAVINGS, ACC_CD, ACC_INVESTMENT, ACC_MUTUALFUND, ACC_MARGIN, ACC_BROKERAGE, ACC_CRYPTO};

// Bank Account
// (use InvestmentAccount for CD Investing or mutual funds)

// does not include login information for online accounts
class Account : public Asset{
public:
    int account_number;
    int institution_number;
    CharString account_name, institution_name;
    
    double value; // money stored in the account (Estimated)
    ACCOUNT_TYPE atype; // account type
    
    Account(ACCOUNT_TYPE _atype, double _value){
        type = AT_ACCOUNT; // AssetType
        atype = _atype;
        value = _value;
    }
};

#endif
