#ifndef FACTION_H_
#define FACTION_H_

#include "../../../Data/includes.h"

#include "../CEntity.h"

// Factions are relatively more complex than Governments because they are both public and private.
//  Factions also tend to be exclusive and private, even hiding in the shadows to influence politics in a government.

// Faction type determines the primary directive of the faction.
enum FACTION_TYPE {
    FACT_UNKNOWN,
    FACT_INDUSTRY, // Neutral
    FACT_PIRATE, FACT_SLAVER, FACT_SMUGGLING, FACT_BANDIT, // The types of factions that everybody loves to hate.
    FACT_POLITICS, FACT_ALLIANCE, // Standard political factions and multi-country factions
};

// FACT_POLITICS is a political faction. (Different from a Political Party, as factions more often than not stage coups)

// FACT_INDUSTRY is kind of like a company, but actually a conglomerate with no borders. Each faciton member would help attempt for maximizing profits cross-company. (I.e: The collection of Robber Barron CEOs in the age of railroads and steel)
//          industry factions also tend to trade mostly with each member company/conglomerate.


// FACT_ALLIANCE is a collection of countries usually combined with defensive pacts against a greater foe.

class Faction : public CEntity {
    LinkedList<CEntity> members; // conglomerates, companies, seedy characters, etc?
    
public:
    FACTION_TYPE ftype;

    Faction(){
        ftype = FACT_UNKNOWN;
        classname="[Faction]";
    }
};

#endif
