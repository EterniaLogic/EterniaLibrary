#ifndef ASSETHOLDER_H_ 
#define ASSETHOLDER_H_

class AssetHolder;

#include "../../Data/includes.h"

#include "BEntity.h"

#include "Assets/Asset.h"

#include "Accounting/Transaction.h"


#include "Accounting/Account.h"
#include "Accounting/Budget.h"
#include "Person.h"


// Assset holders can be any individual or entity that holds money and assets.
//  any individual that takes out a loan or a mortgate technically become a MarginHolder.

// As it is impossible to actually know eveybody's assets, transactions and liabilites, many fields will be empty.


class AssetHolder : public BEntity{
public:
    LinkedList<Asset> equities; // known/unkown list of assets/equities
    
    LinkedList<Account> accounts; // where money is stored in raw form. (used by banks, but most of the time known capital would be stored under Equity)
    LinkedList<Transaction> transactions; // full relevant list of transactions in the previous fiscal quarter
    Budget *budget;
    // CharString name; // from Object
    Person *identity;
    
    double getTotalValue(); // count up the total value of all assets
    double getTotalCash(); // count up the total value of all bank checking/savings assets
};


#else
class AssetHolder;
#endif
