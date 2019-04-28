#ifndef CREATUREPOOLS_H_
#define CREATUREPOOLS_H_

class CreaturePools{
public:
    
    double MP, MPMax; // Mana
    double SP, SPMax; // Stamina Pool (not used when 'usefood' is on)
    
    double MPregen, SPregen; // regen per minute
    
    CreaturePools();
    
    void tick(double seconds); // regeneration
};

#endif
