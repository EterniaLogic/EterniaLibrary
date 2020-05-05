#ifndef BASICCELLMATERIALS_H_
#define BASICCELLMATERIALS_H_

#include "CellMaterial.h"

// Initial temperature assumed to be room temperature

// Basic Materials, such as Water, Metals, Mercury, etc.
// =CONCAT("CellMaterial* ", A2, " = new CellMaterial(MATTERSTATE_",F2,", ",D2,", ",E2,");")


// Note that metals are treated like mercury when they are melted, following a similar curve just with the temperature shifted upwards.
// gas viscosity is more 'free'

namespace CellMaterials{
    // (state, melting point, boiling point kelvin, Viscosity?)
    const CellMaterial* Water = new CellMaterial(MATTERSTATE_LIQUID, 272.6, 373.2, ViscosityCurve(1.0e-1, -20.572395, 100.0, 272.6));
    
    const CellMaterial* CarbonDioxide = new CellMaterial(MATTERSTATE_GAS, 216.6, 194.7, ViscosityCurve(0.015));
    
    
    // Basic Elements, viscosity not given (assumed based on either water or helium as default, solids have none, but assumed to be same viscosity as liquid iron)
    // Viscosity given is in mPa·s
    // Default Viscosities are for 25C or if at melting temperature for metals
    CellMaterial* Hydrogen = new CellMaterial(MATTERSTATE_GAS, 13.81, 20.28,    ViscosityCurve(0.0089));
    CellMaterial* Helium = new CellMaterial(MATTERSTATE_GAS, 0.95, 4.216,       ViscosityCurve(0.01985));
    CellMaterial* Lithium = new CellMaterial(MATTERSTATE_SOLID, 1615, 453.7);   
    CellMaterial* Beryllium = new CellMaterial(MATTERSTATE_SOLID, 3243, 1560);
    CellMaterial* Boron = new CellMaterial(MATTERSTATE_SOLID, 4275, 2365);
    CellMaterial* Carbon = new CellMaterial(MATTERSTATE_SOLID, 5100, 3825);
    CellMaterial* Nitrogen = new CellMaterial(MATTERSTATE_GAS, 63.15, 77.344,   ViscosityCurve(0.01776));
    CellMaterial* Oxygen = new CellMaterial(MATTERSTATE_GAS, 54.8, 90.188,      ViscosityCurve(0.02064));
    CellMaterial* Fluorine = new CellMaterial(MATTERSTATE_GAS, 53.55, 85,       ViscosityCurve(0.02316));
    CellMaterial* Neon = new CellMaterial(MATTERSTATE_GAS, 24.55, 27.1,         ViscosityCurve(0.03175));
    CellMaterial* Sodium = new CellMaterial(MATTERSTATE_SOLID, 1156, 371);
    CellMaterial* Magnesium = new CellMaterial(MATTERSTATE_SOLID, 1380, 922);
    CellMaterial* Aluminum = new CellMaterial(MATTERSTATE_SOLID, 2740, 933.5);
    CellMaterial* Silicon = new CellMaterial(MATTERSTATE_SOLID, 2630, 1683);
    CellMaterial* Phosphorus = new CellMaterial(MATTERSTATE_SOLID, 553, 317.3);
    CellMaterial* Sulfur = new CellMaterial(MATTERSTATE_SOLID, 717.82, 392.2);
    CellMaterial* Chlorine = new CellMaterial(MATTERSTATE_GAS, 172.17, 239.18,  ViscosityCurve(0.0134));
    CellMaterial* Argon = new CellMaterial(MATTERSTATE_GAS, 83.95, 87.45,       ViscosityCurve(0.02261));
    CellMaterial* Potassium = new CellMaterial(MATTERSTATE_SOLID, 1033, 336.8);
    CellMaterial* Calcium = new CellMaterial(MATTERSTATE_SOLID, 1757, 1112);
    CellMaterial* Scandium = new CellMaterial(MATTERSTATE_SOLID, 3109, 1814);
    CellMaterial* Titanium = new CellMaterial(MATTERSTATE_SOLID, 3560, 1945);
    CellMaterial* Vanadium = new CellMaterial(MATTERSTATE_SOLID, 3650, 2163);
    CellMaterial* Chromium = new CellMaterial(MATTERSTATE_SOLID, 2945, 2130);
    CellMaterial* Manganese = new CellMaterial(MATTERSTATE_SOLID, 2335, 1518);
    CellMaterial* Iron = new CellMaterial(MATTERSTATE_SOLID, 3023, 1808);
    CellMaterial* Cobalt = new CellMaterial(MATTERSTATE_SOLID, 3143, 1768);
    CellMaterial* Nickel = new CellMaterial(MATTERSTATE_SOLID, 3005, 1726);
    CellMaterial* Copper = new CellMaterial(MATTERSTATE_SOLID, 2840, 1356.6);
    CellMaterial* Zinc = new CellMaterial(MATTERSTATE_SOLID, 1180, 692.73);
    CellMaterial* Gallium = new CellMaterial(MATTERSTATE_SOLID, 2478, 302.92);
    CellMaterial* Germanium = new CellMaterial(MATTERSTATE_SOLID, 3107, 1211.5);
    CellMaterial* Arsenic = new CellMaterial(MATTERSTATE_SOLID, 876, 1090);
    CellMaterial* Selenium = new CellMaterial(MATTERSTATE_SOLID, 958, 494);
    CellMaterial* Bromine = new CellMaterial(MATTERSTATE_LIQUID, 265.95, 331.85,ViscosityCurve::curveInaccurateLiquid25C(0.944,265.95));
    CellMaterial* Krypton = new CellMaterial(MATTERSTATE_GAS, 116, 120.85,      ViscosityCurve(0.02538));
    CellMaterial* Rubidium = new CellMaterial(MATTERSTATE_SOLID, 961, 312.63);
    CellMaterial* Strontium = new CellMaterial(MATTERSTATE_SOLID, 1655, 1042);
    CellMaterial* Yttrium = new CellMaterial(MATTERSTATE_SOLID, 3611, 1795);
    CellMaterial* Zirconium = new CellMaterial(MATTERSTATE_SOLID, 4682, 2128);
    CellMaterial* Niobium = new CellMaterial(MATTERSTATE_SOLID, 5015, 2742);
    CellMaterial* Molybdenum = new CellMaterial(MATTERSTATE_SOLID, 4912, 2896);
    CellMaterial* Technetium = new CellMaterial(MATTERSTATE_SOLID, 4538, 2477);
    CellMaterial* Ruthenium = new CellMaterial(MATTERSTATE_SOLID, 4425, 2610);
    CellMaterial* Rhodium = new CellMaterial(MATTERSTATE_SOLID, 3970, 2236);
    CellMaterial* Palladium = new CellMaterial(MATTERSTATE_SOLID, 3240, 1825);
    CellMaterial* Silver = new CellMaterial(MATTERSTATE_SOLID, 2436, 1235.08);
    CellMaterial* Cadmium = new CellMaterial(MATTERSTATE_SOLID, 1040, 594.26);
    CellMaterial* Indium = new CellMaterial(MATTERSTATE_SOLID, 2350, 429.78);
    CellMaterial* Tin = new CellMaterial(MATTERSTATE_SOLID, 2876, 505.12);
    CellMaterial* Antimony = new CellMaterial(MATTERSTATE_SOLID, 1860, 903.91);
    CellMaterial* Tellurium = new CellMaterial(MATTERSTATE_SOLID, 1261, 722.72);
    CellMaterial* Iodine = new CellMaterial(MATTERSTATE_SOLID, 457.5, 386.7);
    CellMaterial* Xenon = new CellMaterial(MATTERSTATE_GAS, 161.39, 165.1,      ViscosityCurve(0.02308));
    CellMaterial* Cesium = new CellMaterial(MATTERSTATE_SOLID, 944, 301.54);
    CellMaterial* Barium = new CellMaterial(MATTERSTATE_SOLID, 2078, 1002);
    CellMaterial* Lanthanum = new CellMaterial(MATTERSTATE_SOLID, 3737, 1191);
    CellMaterial* Cerium = new CellMaterial(MATTERSTATE_SOLID, 3715, 1071);
    CellMaterial* Praseodymium = new CellMaterial(MATTERSTATE_SOLID, 3785, 1204);
    CellMaterial* Neodymium = new CellMaterial(MATTERSTATE_SOLID, 3347, 1294);
    CellMaterial* Promethium = new CellMaterial(MATTERSTATE_SOLID, 3273, 1315);
    CellMaterial* Samarium = new CellMaterial(MATTERSTATE_SOLID, 2067, 1347);
    CellMaterial* Europium = new CellMaterial(MATTERSTATE_SOLID, 1800, 1095);
    CellMaterial* Gadolinium = new CellMaterial(MATTERSTATE_SOLID, 3545, 1585);
    CellMaterial* Terbium = new CellMaterial(MATTERSTATE_SOLID, 3500, 1629);
    CellMaterial* Dysprosium = new CellMaterial(MATTERSTATE_SOLID, 2840, 1685);
    CellMaterial* Holmium = new CellMaterial(MATTERSTATE_SOLID, 2968, 1747);
    CellMaterial* Erbium = new CellMaterial(MATTERSTATE_SOLID, 3140, 1802);
    CellMaterial* Thulium = new CellMaterial(MATTERSTATE_SOLID, 2223, 1818);
    CellMaterial* Ytterbium = new CellMaterial(MATTERSTATE_SOLID, 1469, 1092);
    CellMaterial* Lutetium = new CellMaterial(MATTERSTATE_SOLID, 3668, 1936);
    CellMaterial* Hafnium = new CellMaterial(MATTERSTATE_SOLID, 4875, 2504);
    CellMaterial* Tantalum = new CellMaterial(MATTERSTATE_SOLID, 5730, 3293);
    CellMaterial* Tungsten = new CellMaterial(MATTERSTATE_SOLID, 5825, 3695);
    CellMaterial* Rhenium = new CellMaterial(MATTERSTATE_SOLID, 5870, 3455);
    CellMaterial* Osmium = new CellMaterial(MATTERSTATE_SOLID, 5300, 3300);
    CellMaterial* Iridium = new CellMaterial(MATTERSTATE_SOLID, 4700, 2720);
    CellMaterial* Platinum = new CellMaterial(MATTERSTATE_SOLID, 4100, 2042.1);
    CellMaterial* Gold = new CellMaterial(MATTERSTATE_SOLID, 3130, 1337.58);
    CellMaterial* Mercury = new CellMaterial(MATTERSTATE_LIQUID, 234.31, 629.88,ViscosityCurve::curveInaccurateLiquid25C(1.526,234.31));
    CellMaterial* Thallium = new CellMaterial(MATTERSTATE_SOLID, 1746, 577);
    CellMaterial* Lead = new CellMaterial(MATTERSTATE_SOLID, 2023, 600.65);
    CellMaterial* Bismuth = new CellMaterial(MATTERSTATE_SOLID, 1837, 544.59);
    CellMaterial* Astatine = new CellMaterial(MATTERSTATE_SOLID, 610, 575);
    CellMaterial* Radon = new CellMaterial(MATTERSTATE_SOLID, 211.4, 202);
    CellMaterial* Francium = new CellMaterial(MATTERSTATE_SOLID, 950, 300);
    CellMaterial* Radium = new CellMaterial(MATTERSTATE_SOLID, 1413, 973);
    CellMaterial* Thorium = new CellMaterial(MATTERSTATE_SOLID, 5060, 2028);
    CellMaterial* Protactinium = new CellMaterial(MATTERSTATE_SOLID, 4300, 1845);
    CellMaterial* Uranium = new CellMaterial(MATTERSTATE_SOLID, 4407, 1408);
    CellMaterial* Neptunium = new CellMaterial(MATTERSTATE_SOLID, 4175, 912);
    CellMaterial* Plutonium = new CellMaterial(MATTERSTATE_SOLID, 3505, 913);
    CellMaterial* Americium = new CellMaterial(MATTERSTATE_SOLID, 2880, 1449);

}



#endif
