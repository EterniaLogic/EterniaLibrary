#include "testViscosityCurve.h"


void testViscosityCurve(){
    LinkedList<TempViscosityPoint*> tpoints;
    
     //Water Data
        tpoints.add(new TempViscosityPoint(275.15, 1.6735));
        tpoints.add(new TempViscosityPoint(276.15, 1.619));
        tpoints.add(new TempViscosityPoint(277.15, 1.5673));
        tpoints.add(new TempViscosityPoint(278.15, 1.5182));
        tpoints.add(new TempViscosityPoint(279.15, 1.4715));
        tpoints.add(new TempViscosityPoint(280.15, 1.4271));
        tpoints.add(new TempViscosityPoint(281.15, 1.3847));
        tpoints.add(new TempViscosityPoint(282.15, 1.3444));
        tpoints.add(new TempViscosityPoint(283.15, 1.3059));
        tpoints.add(new TempViscosityPoint(284.15, 1.2692));
        tpoints.add(new TempViscosityPoint(285.15, 1.234));
        tpoints.add(new TempViscosityPoint(286.15, 1.2005));
        tpoints.add(new TempViscosityPoint(287.15, 1.1683));
        tpoints.add(new TempViscosityPoint(288.15, 1.1375));
        tpoints.add(new TempViscosityPoint(289.15, 1.1081));
        tpoints.add(new TempViscosityPoint(290.15, 1.0798));
        tpoints.add(new TempViscosityPoint(291.15, 1.0526));
        tpoints.add(new TempViscosityPoint(292.15, 1.0266));
        tpoints.add(new TempViscosityPoint(293.15, 1.0016));
        tpoints.add(new TempViscosityPoint(294.15, 0.9775));
        tpoints.add(new TempViscosityPoint(295.15, 0.9544));
        tpoints.add(new TempViscosityPoint(296.15, 0.9321));
        tpoints.add(new TempViscosityPoint(297.15, 0.9107));
        tpoints.add(new TempViscosityPoint(298.15, 0.89));
        tpoints.add(new TempViscosityPoint(299.15, 0.8701));
        tpoints.add(new TempViscosityPoint(300.15, 0.8509));
        tpoints.add(new TempViscosityPoint(301.15, 0.8324));
        tpoints.add(new TempViscosityPoint(302.15, 0.8145));
        tpoints.add(new TempViscosityPoint(303.15, 0.7972));
        tpoints.add(new TempViscosityPoint(304.15, 0.7805));
        tpoints.add(new TempViscosityPoint(305.15, 0.7644));
        tpoints.add(new TempViscosityPoint(306.15, 0.7488));
        tpoints.add(new TempViscosityPoint(307.15, 0.7337));
        tpoints.add(new TempViscosityPoint(308.15, 0.7191));
        tpoints.add(new TempViscosityPoint(309.15, 0.705));
        tpoints.add(new TempViscosityPoint(310.15, 0.6913));
        tpoints.add(new TempViscosityPoint(311.15, 0.678));
        tpoints.add(new TempViscosityPoint(312.15, 0.6652));
        tpoints.add(new TempViscosityPoint(313.15, 0.6527));
        tpoints.add(new TempViscosityPoint(318.15, 0.5958));
        tpoints.add(new TempViscosityPoint(323.15, 0.5465));
        tpoints.add(new TempViscosityPoint(328.15, 0.5036));
        tpoints.add(new TempViscosityPoint(333.15, 0.466));
        tpoints.add(new TempViscosityPoint(338.15, 0.4329));
        tpoints.add(new TempViscosityPoint(343.15, 0.4035));
        tpoints.add(new TempViscosityPoint(348.15, 0.3774));
        tpoints.add(new TempViscosityPoint(353.15, 0.354));

    //tpoints.add(new TempViscosityPoint(173.15, 3));
    

    ViscosityCurve curvewater = ViscosityCurve(tpoints,273.2,false);
    
    
    cout << "water visc @ 2C = " << curvewater.getViscosity(275.15) << " expected 1.6735" << endl;
    cout << "water visc @ 20C = " << curvewater.getViscosity(293.15) << " expected 1.0016" << endl;
    cout << "water visc @ 30C = " << curvewater.getViscosity(303.15) << " expected 0.7972" << endl;
    cout << "water visc @ 40C = " << curvewater.getViscosity(313.15) << " expected 0.6527" << endl;
    
    
    cout << "---- solve for different materials ----" << endl;
    
    ViscosityCurve curvemercury = ViscosityCurve::curveInaccurateLiquid25C(1.526, 234.31);
    cout << "mercury visc @ -38.15C = " << curvemercury.getViscosity(235.0) << "" << endl;
    cout << "mercury visc @ 2C = " << curvemercury.getViscosity(275.15) << "" << endl;
    cout << "mercury visc @ 20C = " << curvemercury.getViscosity(293.15) << "" << endl;
    cout << "mercury visc @ 25C = " << curvemercury.getViscosity(297.15) << " expected 1.526" << endl;
    cout << "mercury visc @ 30C = " << curvemercury.getViscosity(303.15) << "" << endl;
    cout << "mercury visc @ 40C = " << curvemercury.getViscosity(313.15) << "" << endl;
    
}
