#ifndef ENCHTABLE_H_
#define ENCHTABLE_H_

#include "Workshop.h"

class EnchantmentTable : public Workshop{
public:
    EnchantmentTable(){
        classname="EnchantmentTable";
        // Enables for enchantments
        // Must have a skill/spell level in that element to be able to enchant.
        
        recipes.add(new Recipe("1 equippable item, ? mana","1 enchanted equippable item", 1200));
        recipes.add(new Recipe("1 scroll, ? mana","1 enchanted scroll", 1200));
        recipes.add(new Recipe("1 slate, ? mana","1 enchanted slate", 1200));
    }
};

#endif
