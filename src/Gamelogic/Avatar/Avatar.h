#ifndef Avatar_h_
#define Avatar_h_

enum AvatarTYPE {AT_Player, AT_AI, AT_Static, AT_Boss};
enum DAMAGERESULT {DR_MISS, DR_HIT, DR_KILL};


// Ah, the art of abstraction.
#include "AvatarHealth.h"
#include "Skill.h"

class Avatar
{
public:
  Avatar(); // define all parameters
  
  void doAnimation(); // do a defined action. (Dance, hit, die, ect.)
  
  // Manage attributes
  void addDisease(Disease d); // diseases act like debuffs, but for long-periods
  void addSkill();
  
  // Physical character effects
  DAMAGERESULT damage(BODYPART part, float k); // damage character with k damage (note: defenses are taken into account)
  
  void tick(); // game tick, evaluate avatar hp, skills, ect.
  
  void loadStats(CharString* statsString); // load stats directly from a string.
  CharString* getStats(); // retrive stats to a string.
  
private:
  // Base attributes
  CharString* name;
  AvatarTYPE type;
  AvatarHealth health; // Advanced Health class that includes physiology, diseases, ect.
  
  // Base Stats (Can be increased by player)
  float strength; // Attack Strength / Carry ability / Awe
  float agility; // Attack Speed / Avoid
  float intelligence; // Research / Tech / Strategist / Crafting
  float awareness; // Keen senses / detection / timing
  float constitution; // Health / Defense / Def Rate
  
  // Hidden Stats (Cannot be increased by player, change on their own accord)
  float luck; // Crafting luck / likelihood of mistakes / mining luck
  float perception; // Accuracy / Intelligence
  float insight; // Intelligence / Discovery
  
  LinkedList<Skill>* skills;
  
  
  
  
  // Models, textures and other assets
  CharString* model; // model location
  CharString* attack_sfx; // list of sfx used when fighting
  CharString* idle_sfx; // sfx used when avatar or monster is idle
  CharString* random_sfx; // sfx used at random (may be used in tandom with an animation)
};

#endif