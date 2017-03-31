#ifndef RACE_H_
#define RACE_H_

#include "../../Engineering/Chemistry/elementals.h"
#include "../../Engineering/Chemistry/Composite.h"

// A brand new race can be created by a player.
// 	Players will be warned that new races will increase the chances of provocation from other races.
//	This includes war-band races or races without the same principles.
//	New races will start out on a random planet with a generous population.

// The player could also join a race. Joining a race will make players spawn on the Capital planet.
//	They are ordered to start a new colony.

class Race{
private:
	
	// values
	float xenophilia; // -1 = hatred towards other races, 1 = love new races
	
	// Biological requirements
	float tempreature; // living temperature, in kelvin (Humans like 294.817 kelvin, 71 fahrenheit)
	float sleep; // Ratio to sleep of the day. Humans normally have a 29.1% time sleep for each day. (0.291)
	Composite breathing; // molecule normally used for breathing, humans like o2
	
	// Psychological
	float intelligence; // Base intelligence level, rated in IQ. Higher IQ = faster research.
	float psyche; // likelihood to go "insane", humans have around 0.001 (.1%)
	float emotion; // amount of emotion, 0=wut, 1=human, 100=crybabies/revengers
};

#endif
