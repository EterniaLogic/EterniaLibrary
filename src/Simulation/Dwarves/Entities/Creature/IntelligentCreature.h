#ifndef icreature_h_
#define icreature_h_

#include "Creature.h"


// intelligent creatures tend to actually move.
class IntelligentCreature : public Creature{
public:
    // Current Action
    Action current_action;
    
    bool tamable; // since this creature is intelligent, tamable?
    bool disguised;
    
    // NEEDED actions
    LinkedList<Action> biological_actions; // actions needed to stay healthy
    LinkedList<Action> existential_actions; // higher priority actions needed to survive, AKA: going to be wiped out
    
    
    IntelligentCreature();
    
    void think(double seconds); // make the creature think, kind of needed for creating things
};


#endif
