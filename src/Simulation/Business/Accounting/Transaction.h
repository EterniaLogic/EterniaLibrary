#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include "../../../Data/includes.h"

#include "../BEntity.h"


enum TransType {TT_UNKNOWN, TT_BUY, TT_SELL, TT_SERVICE, TT_PAYROLL};

// A transaction is a single event of changing one object of value for another object of value
class Transaction{
public:
    Transaction();
    
    CharString transactionID; // ID to help track in database
    CharString receiptID; // receipt ID from company or invoice #
    
    TransType type;
    BEntity from, to; // from a person/ this company or to a person, this company
    BEntity *employee; // employee who processed this transaction (Who bought an item, etc)
    CharString date; // Date / time this transaction occured
    double value; // value in relevant currency (discounting tax)
    double tax; // tax incurred (Whether selling or buying)
    
    bool finalized; // has this transaction been finalized yet?
};

#endif
