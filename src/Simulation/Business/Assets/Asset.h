#ifndef ASSET_H
#define ASSET_H

#include "../../../Data/includes.h"

#include "../BEntity.h"

enum ASSET_TYPE {AT_SHARE, AT_IP, AT_MATERIAL, AT_PROPERTY, AT_ITEM, AT_LIABILITY, AT_EQUITY};
enum ACCOUNTING_TYPE {ACT_UNKNOWN, ACT_ASSET, ACT_LIABILITY, ACT_EQUITY, ACT_INVESTMENT};

class Asset{
public:
    Asset();
    ASSET_TYPE type;
    long count;
    double value;
    double original_value;
    CharString purchasedate;
    CharString name;
    BEntity *holder;
};

#endif
