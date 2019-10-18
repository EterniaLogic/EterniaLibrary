#ifndef ENCHANTMENT_H_
#define ENCHANTMENT_H_

enum ENCHANTMENT_TYPE {
    ET_SPEED, // movement/attackspeed
    ET_DAMAGE, // magic/ranged/melee weapon
    ET_DURABILITY, ET_PROTECTION,  // armor
    ET_POCKET, ET_TELEPORT, // Space
    
    
    ET_LEVELABLE}; // most OP enchantment
    
enum ENCHANTMENT_ELEMENT {EE_LIGHT, EE_FIRE, EE_WIND, EE_EARTH, EE_WATER, EE_ICE, EE_SPACE, EE_LIGHTNING, EE_DARK, EE_NECRO, EE_TIME};

class Enchantment{
public:
    ENCHANTMENT_ELEMENT element; // element used during the enchant, effects magic and other stats
    ENCHANTMENT_TYPE type; // combined with element to generate status changes
    double strength; // mana structure strength, too much mana put into enchantment will explode the enchant
    
    // [PROTECTION] from [FIRE] of [100] mana
    // [FIRE] [DAMAGE] of [100] mana
    // [WIND] [SPEED] of [100] mana      for boots
    
    // [SPACE] [POCKET] of [10] m3 of space    space ring
};

#endif
