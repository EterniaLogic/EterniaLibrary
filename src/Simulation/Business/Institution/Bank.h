#ifndef BANK_H_
#define BANK_H_

#include "../Company.h"
#include "../Accounting/Account.h"

class Bank : public Company{
private:
    LinkedList<AssetHolder> customers; // customer accounts included

public:
};

#endif
