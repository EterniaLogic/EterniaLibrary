#ifndef ASSET_H
#define ASSET_H

#include "../../../Data/includes.h"

#include "../BEntity.h"
#include <time.h>

enum ASSET_TYPE {AT_SHARE, AT_IP, AT_MATERIAL, AT_PROPERTY, AT_ITEM, AT_EQUITY, AT_ACCOUNT};

class Asset : BEntity{
public:
    Asset();
    ASSET_TYPE type;
    long count; // counts of value
    double value; // current value after compounded interest
    double costbasis; // original value before interest rate
    double intrestrate; // assumed ROI per year
    std::time_t purchasedate; // initial purchase, not including extra purchases
    CharString name;
    BEntity *holder;
};

#endif
