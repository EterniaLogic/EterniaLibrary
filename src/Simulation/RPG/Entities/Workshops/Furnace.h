#ifndef FURNACE_H_
#define FURNACE_H_

#include "Workshop.h"

enum FURNACE_ADDON {FA_BOULEDRAWER, FA_ARC, FA_SEALANT, FA_DRAIN, FA_CASTINGTABLE};

class Furnace : public Workshop{
public:
    double temperature; // temperature in celcius
    
    bool sealed; // sealing will prevent air from entering enabling the use of gasses other than oxygen
    
    LinkedList<FURNACE_ADDON> addons;
    CastingTable ctaddon; // use with drain (FA_DRAIN, FA_CASTINGTABLE)
    
    Furnace(){
        classname="Furnace";
        
        // heating for anvil
        recipes.add(new Recipe("1 Metal Item","1 Hot Metal Item", 600));
        recipes.add(new Recipe("1 Metal Item","1 Semi-Hot Metal Item", 600));
    
        // crude refining
        recipes.add(new Recipe("1kg Crucible, 333g Sand, 333g Soda Ash, 333g Lime","1kg Glass Boule", 600)); // (soda ash is sodium carbonate from wood-ash)
        recipes.add(new Recipe("1kg Crucible, 1kg Ore Dust","990g Metal Ingot, 10g slag", 300));
        recipes.add(new Recipe("ARC, 1kg Crucible, 600g Sand, 460g Coal Coke","400g Silicon")); // Arc furnace, Pure Silicon
        
        // alloying
        recipes.add(new Recipe("1kg Crucible, 740g iron, 180g chromium, 80g nickel","990g Stainless Steel, 10g slag", 900));
        recipes.add(new Recipe("1kg Crucible, 750g copper, 250g tin","990kg Bronze, 10g slag", 900));
        
        // Liquid Drain recipes (No more crucibles!)
        // use casting table or it will just drop on the floor :P
        recipes.add(new Recipe("DRAIN, 333g Sand, 333g Soda Ash, 333g Lime","1kg Liquid Glass", 600)); // (soda ash is sodium carbonate)
        recipes.add(new Recipe("DRAIN, 1kg Ore Dust","990g Liquid Metal, 10g slag", 300));
        recipes.add(new Recipe("DRAIN, 740g iron, 180g chromium, 80g nickel","990g Liquid Stainless Steel, 10g slag", 900));
        recipes.add(new Recipe("DRAIN, 750g copper, 250g tin","990kg Liquid Bronze, 10g slag", 900));
        recipes.add(new Recipe("DRAIN, ARC, 600g Sand, 460g Coal Coke","400g Silicon")); // Arc furnace, drain, Pure Silicon
        
        // Silicon Boules, Sealed with Boron atmosphere and a BOULEDRAWER over 48 hours
        recipes.add(new Recipe("BOULEDRAWER, 1 Silicon Crystal Seed, Silicon","Silicon Boule", 48*60*60));
        
        
    }
};

#endif
