#ifndef TURRET_H_
#define TURRET_H_

// This is the main weapon being mounted on a hardpoint.
enum TUR_TYPE {
	TURT_MG, TURT_CANNON, TURT_FLAK, TURT_NUKE, // Ballistic-based
	TURT_BEAM, TURT_PULSE, // Energy-based
	TURT_RAILGUN // Hybrid
};

class Turret{
public:
	Turret();
	
	float mass; // total mass of the turret in kilograms
	
	
	int turret_class; // class of the weapon, more or less just used for identifying it's ship fitting.
};


#endif