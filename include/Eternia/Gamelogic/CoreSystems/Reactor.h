#ifndef REACTOR_H_
#define REACTOR_H_

#include "PhysicalMaterial.h"
#include "../../Engineering/Chemistry/Atom.h"
#include "../../Engineering/Chemistry/Composite.h"

enum POWGEN { PGEN_TURBINE, PGEN_THERMOCOUPLE };
enum NUCLEARTYPE {NT_FUSION, NT_FISSION, NT_STAR};

class Reactor{
public:
	Reactor();
	
	float core_density; // 
	Atom coreElement; // 
	
	float rod_percent; // reactor rod
	
	Composite ishield, oshield; // material used to shield the reactor from exposing radiation
	Composite icoolant, ocoolant; // inner/outer coolant
};

#endif