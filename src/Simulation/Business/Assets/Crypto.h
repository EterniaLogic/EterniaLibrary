#ifndef CRYPTO_H
#define CRYPTO_H

#include "Asset.h"


// determined value based on currency pair

class Crypto : Asset{
public:

    // inherits fiat values
    //double value; // current value in fiat currency (USD, aud, etc.)
    //double costbasis; // sum of fiat used to buy/sell
    CharString fiatname; // USD, AUD, EUR, etc.
    
    
    double cryptovalue;
    double crypto_avgprice; // weighted average from buys
    double crypto_current_price; // current price of the currency
    CharString cryptoname; // BTC, STM, SOL, ETH, etc.
    
    LinkedList<Transaction> buys, sells; // used to determine cost basis and profits
    
    
    double getProfit(); // based on difference of current value and costbasis
    double getProfitPercent();
};

#endif
