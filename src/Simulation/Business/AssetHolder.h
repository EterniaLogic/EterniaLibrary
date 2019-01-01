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

class AssetHolder : public BEntity{
public:
    LinkedList<Asset> assets; // known/unkown list of assets
    LinkedList<Account> accounts; // where money is stored in raw form.
    LinkedList<Transaction> transactions; // full relevant list of transactions in the previous fiscal quarter
    Budget *budget;
    CharString name;
    Person* identity;
    
    double getTotalValue(); // count up the total value of all assets
    double getTotalCash(); // count up the total value of all bank checking/savings assets
};


#else
class AssetHolder;
#endif
