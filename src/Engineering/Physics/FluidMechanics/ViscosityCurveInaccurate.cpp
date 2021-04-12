#include "ViscosityCurve.h"



// only for inaccurate situations, but filling in information when there is no graph data.
//
ViscosityCurve ViscosityCurve::curveInaccurateGas25C(double visc25c, double freezingpoint){
    // copy data and scale from Hydrogen
    
    ViscosityCurve curve = ViscosityCurve();
}

ViscosityCurve ViscosityCurve::curveInaccurateLiquid25C(double visc25c, double freezingpoint){
    // copy data and scale from Water
    
    double diff = visc25c/0.89;
    LinkedList<TempViscosityPoint*> tpoints;
    // WATER
    tpoints.add(new TempViscosityPoint(275.15, 1.6735*diff));
    tpoints.add(new TempViscosityPoint(276.15, 1.619*diff));
    tpoints.add(new TempViscosityPoint(277.15, 1.5673*diff));
    tpoints.add(new TempViscosityPoint(278.15, 1.5182*diff));
    tpoints.add(new TempViscosityPoint(279.15, 1.4715*diff));
    tpoints.add(new TempViscosityPoint(280.15, 1.4271*diff));
    tpoints.add(new TempViscosityPoint(281.15, 1.3847*diff));
    tpoints.add(new TempViscosityPoint(282.15, 1.3444*diff));
    tpoints.add(new TempViscosityPoint(283.15, 1.3059*diff));
    tpoints.add(new TempViscosityPoint(284.15, 1.2692*diff));
    tpoints.add(new TempViscosityPoint(285.15, 1.234*diff));
    tpoints.add(new TempViscosityPoint(286.15, 1.2005*diff));
    tpoints.add(new TempViscosityPoint(287.15, 1.1683*diff));
    tpoints.add(new TempViscosityPoint(288.15, 1.1375*diff));
    tpoints.add(new TempViscosityPoint(289.15, 1.1081*diff));
    tpoints.add(new TempViscosityPoint(290.15, 1.0798*diff));
    tpoints.add(new TempViscosityPoint(291.15, 1.0526*diff));
    tpoints.add(new TempViscosityPoint(292.15, 1.0266*diff));
    tpoints.add(new TempViscosityPoint(293.15, 1.0016*diff));
    tpoints.add(new TempViscosityPoint(294.15, 0.9775*diff));
    tpoints.add(new TempViscosityPoint(295.15, 0.9544*diff));
    tpoints.add(new TempViscosityPoint(296.15, 0.9321*diff));
    tpoints.add(new TempViscosityPoint(297.15, 0.9107*diff));
    tpoints.add(new TempViscosityPoint(298.15, 0.89*diff));   // << visc25C
    tpoints.add(new TempViscosityPoint(299.15, 0.8701*diff));
    tpoints.add(new TempViscosityPoint(300.15, 0.8509*diff));
    tpoints.add(new TempViscosityPoint(301.15, 0.8324*diff));
    tpoints.add(new TempViscosityPoint(302.15, 0.8145*diff));
    tpoints.add(new TempViscosityPoint(303.15, 0.7972*diff));
    tpoints.add(new TempViscosityPoint(304.15, 0.7805*diff));
    tpoints.add(new TempViscosityPoint(305.15, 0.7644*diff));
    tpoints.add(new TempViscosityPoint(306.15, 0.7488*diff));
    tpoints.add(new TempViscosityPoint(307.15, 0.7337*diff));
    tpoints.add(new TempViscosityPoint(308.15, 0.7191*diff));
    tpoints.add(new TempViscosityPoint(309.15, 0.705*diff));
    tpoints.add(new TempViscosityPoint(310.15, 0.6913*diff));
    tpoints.add(new TempViscosityPoint(311.15, 0.678*diff));
    tpoints.add(new TempViscosityPoint(312.15, 0.6652*diff));
    tpoints.add(new TempViscosityPoint(313.15, 0.6527*diff));
    tpoints.add(new TempViscosityPoint(318.15, 0.5958*diff));
    tpoints.add(new TempViscosityPoint(323.15, 0.5465*diff));
    tpoints.add(new TempViscosityPoint(328.15, 0.5036*diff));
    tpoints.add(new TempViscosityPoint(333.15, 0.466*diff));
    tpoints.add(new TempViscosityPoint(338.15, 0.4329*diff));
    tpoints.add(new TempViscosityPoint(343.15, 0.4035*diff));
    tpoints.add(new TempViscosityPoint(348.15, 0.3774*diff));
    tpoints.add(new TempViscosityPoint(353.15, 0.354*diff));
    
    
    ViscosityCurve curve = ViscosityCurve(tpoints,freezingpoint,false);
    
    return curve;
}
