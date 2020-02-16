#ifndef GAMEU_H
#define GAMEU_H

#include "../Universe.h"
#include "../Space/Galaxy.h"


class GameUniverse : public Universe{
public:
    GameUniverse(long seedx){
        this->seed = seedx;
        // Define fundamental Laws
        
        // sub-Lowest level
        laws.add(ULaw(UL_ENERGY, "Particles")); // Raw ... whatever becomes particles (Even lower is kinda useless in simulation)
        laws.add(ULaw(UL_MATTER, "Atoms")); // Particles become Atoms
        laws.add(ULaw(UL_MATTER, "Protons"));
        laws.add(ULaw(UL_MATTER, "Neutrons"));
        laws.add(ULaw(UL_MATTER, "Electrons"));
        
        laws.add(ULaw(UL_MATTER, "Compounds")); // Atoms come together and bond
        
        laws.add(ULaw(UL_MATTER, "Sun")); // super-cluster of atoms
        laws.add(ULaw(UL_MATTER, "BlackHole")); // a sun got too greedy
        laws.add(ULaw(UL_MATTER, "Galaxy")); // cluster of stars around a cluster of black holes
        
        // Sub-laws
        laws.add(ULaw(UL_ENERGY, "Fusion")); // Atoms can fuse particles with enough pressure and energy
        laws.add(ULaw(UL_ENERGY, "Fission")); // Atoms can diffuse particles (Radiation)
        
        
        // Forces
        laws.add(ULaw(UL_MATTER, "Gravity"));
        laws.add(ULaw(UL_MATTER, "Collision"));
        laws.add(ULaw(UL_MATTER, "Magnetism"));
        laws.add(ULaw(UL_ENERGY, "Electricity")); // delta of free Electron charges
        
        // Energy Types
        laws.add(ULaw(UL_ENERGY, "Mana")); // Mages
        laws.add(ULaw(UL_ENERGY, "Vitality")); // Body cultivation
        laws.add(ULaw(UL_ENERGY, "Aura")); // Qi
        laws.add(ULaw(UL_ENERGY, "Soul")); // Mental
        
        // Usable Laws (Wuxia, Elements, Magic, Contamination)
        laws.add(ULaw(UL_LAW, "Light"));
        laws.add(ULaw(UL_LAW, "Earth"));
        laws.add(ULaw(UL_LAW, "Fire"));
        laws.add(ULaw(UL_LAW, "Water"));
        laws.add(ULaw(UL_LAW, "Air"));
        laws.add(ULaw(UL_LAW, "Lightning"));
        laws.add(ULaw(UL_LAW, "Dark"));
        laws.add(ULaw(UL_LAW, "Devouring")); // Some can gain the abilities of others
    }
    
    
    // get a galaxy using a seed (seed also doubles as XYZ coordinates from the center of everything)
    Galaxy getGalaxy(long seed){ 
        
    }
};

#endif
