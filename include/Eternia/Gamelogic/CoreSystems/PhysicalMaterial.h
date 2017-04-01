#ifndef PHYSMAT_H_
#define PHYSMAT_H_

// Material used for reactors, weapons, armor plating, ect.
class PhysicalMaterial{
public:
	PhysicalMaterial();
	
	float density; // density of the material (g/cm3)
	float thermal_conductivity; // W/(m.K)
	float electrical_conductivity;
	char* name; //
	char* formula;
	
};


// 1.57 -- 25 --  -- Carbon Fibre -- H5C4
#endif