#ifndef FLUIDMECHANICS_H_
#define FLUIDMECHANICS_H_

// Fluid Mechanics is a mid-level set of tools to help control water or other material's physical
//      properties.

// The fundamental idea behind fluid mechanics is a push-pull action system where oscillations can occur.

// sinc(i) is the best describer for fluid's oscillations when something falls into it. Without
//      gravity, friction in water is almost nothing except for present air.

// everything is dealt with in terms of meter^3, liters and kilograms.


class FluidMechanics {
    public:
        FluidMechanics();
        virtual ~FluidMechanics();
};

#endif /*FLUIDMECHANICS_H_*/
