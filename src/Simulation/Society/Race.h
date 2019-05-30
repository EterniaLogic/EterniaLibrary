#ifndef RACE_H_
#define RACE_H_

#include "../../Data/includes.h"
#include "../../Engineering/Chemistry/Composite.h"


#ifndef RELATIONS_H_
#include "Relations.h"
#else
class Relations;
#endif

// A brand new race can be created by a player.
// 	Players will be warned that new races will increase the chances of provocation from other races.
//	This includes war-band races or races without the same principles.
//	New races will start out on a random planet with a generous population.

// The player could also join a race. Joining a race will make players spawn on the Capital planet.
//	They are ordered to start a new colony.

typedef struct diff_t{
    double min;
    double avg;
    double max;
};


namespace RaceDiet{
    // list of diets
    enum Diet {NONE, //
        CARNIVORE, HERBIVORE, OMNIVORE,
        PHYTOVORE, // literally eats light
        WOODVORE, // eats wood, like termites
        MAGIVORE, // eats magical food only, like Fae (if in a magical world ofc)
        METALVORE,
        EARTHVORE, // Eats the earth for nutrients, like worms
    };
}

namespace RaceLimb{
    enum LimbType{
        Arm,
        Leg,
        Head,
        Torso,
        Waist,
        Neck,
        Foot,
        Hand,

        // Animal bits
        Wing,
        Horn,
    };
}

/*typedef struct Limb{
    RaceLimb::LimbType type;
    int qty; // number of limbs
    double mass; // each limb has a mass in Kilograms, Kg. (Mass factors into how much damage this race would take from a hit)
};*/

namespace RaceCaste{
    enum Caste_Type {asexual, male, female};
}

class Caste{
public:
    RaceCaste::Caste_Type type;
    CharString castename;

    RaceDiet::Diet diet;
//    LinkedList<Limb> limbs;

    // mental
    float intelligence; // Base intelligence level, rated in IQ. Higher IQ = faster research.
    float psyche; // likelihood to go "insane", humans have around 0.001 (.1%)
    float emotion; // amount of emotion, 0=wut, 60=human female, 100=beings controlled purely by emotion (wrath, envy, etc)

    // values
    float xenophilia; // -1 = hatred towards other intelligent races, 1 = love new races (Humans are like -0.2)

    // Basic Biological requirements
    float temperature; // living temperature, in kelvin (Humans like 294.817 kelvin, 71 fahrenheit)
    float sleep; // Ratio to sleep of the day. Humans normally have a 29.1% time sleep for each day. (0.291)
    Chemistry::Composite breathing; // molecule normally used for breathing, humans like o2


    diff_t lifespan; //   = {30, 50, 120}; // differential float {min,avg,max}
    diff_t weight_adult;
    diff_t size_adult;
    diff_t weight_baby;
    diff_t size_baby;


    // Procreation
    double days_pregnant; // 274 days for humans
    double age_fertile, age_maxfertile; // year ages required for females to be able to become pregnant and when the female loses the ability. -1 for no cap on pregnancy (13, 40 for humans)
    double age_puberty, puberty_years; // transition years to youth, start and length
};

class Race{
public:
	Race(){}

    LinkedList<Relations> relationships; // hates / likes of another race

    LinkedList<Caste> castes; // males/females, variations of species


    CharString name, description;
};

#endif
