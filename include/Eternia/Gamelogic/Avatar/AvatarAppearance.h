#ifndef AVATAR_APPEARANCE_H_

#include "../../Math/struct/vertex.h"
#include "../../Data/Protect/PType.hpp"
#include "../../Data/CharString.h"
#include "../../Serialization/SpecificSerializer.h"

enum AP_GENDER {AP_MALE, AP_FEMALE, AP_ROBOT, AP_ASEXUAL};


// The majority of this class is 

class AvatarAppearance : public SpecificSerializer{
public:
    AvatarAppearance();
    virtual ~AvatarAppearance();
    
// General values //
    PType<AP_GENDER> gender;
    PType<double> height; // Avatar height in meters not including hair or shoes.
    PType<double> strength; // Muscle development
    PType<double> obesity; // huh.
    vertex skin_color; // skin color
    
// Hair //
    PType<double> hair_length, hair_gloss, hair_curliness; // growable hair length
    vertex hair_color, beard_color, eyebrow_color; // hair color
    
    
// Shape crafting //
    PType<double> hip_width, torso_width, leg_diameter, arm_diameter; // base
    PType<double> tail_length, horn_length; // Alien
    
// Face //
    vertex eye_color; // eye color
    PType<double> eyebrow_height, nose_height, mouth_height;
    
// Models, textures and other assets //
    CharString model; // model location
    CharString attack_sfx; // list of sfx used when fighting
    CharString idle_sfx; // sfx used when avatar or monster is idle
    CharString random_sfx; // sfx used at random (may be used in tandom with an animation)
};

#endif