#ifndef Account_h_
#define Account_h_
#include "../../Data/CharString.h"

enum interestTYPE {Interest_HOURLY, Interest_DAILY, Interest_WEEKLY, Interest_MONTHLY, Interest_YEARLY};
enum accountATTRIBUTE {ACCATT_Account, ACCATT_Credit, ACCATT_Loan};

// Accounts are based on a bitcoin-like crypto-currency.
// Players can mine the currency which means players starting out will be rich later on.

class Account {
public:
    Account(double ID, double Value, double key);

    double getID(); // return the account id
    double getValue();
    double getKey();
    double createKey(CharString passcode); // Create a key based on a passcode
    void challengeKey(CharString passcode); // Challenge the key, user entering PIN
    
    bool transferAccount(); // perform a full account transfer
    
    void tick(double tps); // perform interest ticks

private:
    PType<double> key; // number-key for accessing account, hashed
    PType<int> id; // account id
    PType<double> value; // account value
    PType<bool> unlocked; // account unlocked
    
    PType<double> interest; // percent interest
    PType<interestTYPE> interest_type;

    PType<accountATTRIBUTE> main_attribute; // account or a loan?
};

#endif
