#ifndef CRYPTOACCOUNT_H_
#define CRYPTOACCOUNT_H_


//


#include "Account.h"
#include "../Assets/Crypto.h"
class CryptoAccount : public Account {
private:
    
public:
    // inherits  double value;
    
    CharString walletid; // if value stored on a private wallet
    LinkedList<Crypto> currencies; // list of all owned currency pairs
};

#endif
