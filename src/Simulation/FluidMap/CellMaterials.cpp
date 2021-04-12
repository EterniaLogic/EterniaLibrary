#include "CellMaterials.h"

void init_cellmaterials(){
    // (state, melting point, boiling point kelvin, Viscosity?)
    CellMaterials::Water = CellMaterial(MATTERSTATE_LIQUID, 272.6, 373.2,       ViscosityCurve(1.0e-1, -20.572395, 100.0, 272.6,false));
    CellMaterials::CarbonDioxide = CellMaterial(MATTERSTATE_GAS, 216.6, 194.7,  ViscosityCurve(0.015));


    // Basic Elements, viscosity not given (assumed based on either water or helium as default, solids have none, but assumed to be same viscosity as liquid iron)
    // Viscosity given is in mPa·s
    // Default Viscosities are for 25C or if at melting temperature for metals
    CellMaterials::Hydrogen = CellMaterial(MATTERSTATE_GAS, 13.81, 20.28,       ViscosityCurve(0.0089));
    CellMaterials::Helium = CellMaterial(MATTERSTATE_GAS, 0.95, 4.216,          ViscosityCurve(0.01985));
    CellMaterials::Lithium = CellMaterial(MATTERSTATE_SOLID, 1615, 453.7);   
    CellMaterials::Beryllium = CellMaterial(MATTERSTATE_SOLID, 3243, 1560);
    CellMaterials::Boron = CellMaterial(MATTERSTATE_SOLID, 4275, 2365);
    CellMaterials::Carbon = CellMaterial(MATTERSTATE_SOLID, 5100, 3825);
    CellMaterials::Nitrogen = CellMaterial(MATTERSTATE_GAS, 63.15, 77.344,      ViscosityCurve(0.01776));
    CellMaterials::Oxygen = CellMaterial(MATTERSTATE_GAS, 54.8, 90.188,         ViscosityCurve(0.02064));
    CellMaterials::Fluorine = CellMaterial(MATTERSTATE_GAS, 53.55, 85,          ViscosityCurve(0.02316));
    CellMaterials::Neon = CellMaterial(MATTERSTATE_GAS, 24.55, 27.1,            ViscosityCurve(0.03175));
    CellMaterials::Sodium = CellMaterial(MATTERSTATE_SOLID, 1156, 371);
    CellMaterials::Magnesium = CellMaterial(MATTERSTATE_SOLID, 1380, 922);
    CellMaterials::Aluminum = CellMaterial(MATTERSTATE_SOLID, 2740, 933.5);
    CellMaterials::Silicon = CellMaterial(MATTERSTATE_SOLID, 2630, 1683);
    CellMaterials::Phosphorus = CellMaterial(MATTERSTATE_SOLID, 553, 317.3);
    CellMaterials::Sulfur = CellMaterial(MATTERSTATE_SOLID, 717.82, 392.2);
    CellMaterials::Chlorine = CellMaterial(MATTERSTATE_GAS, 172.17, 239.18,     ViscosityCurve(0.0134));
    CellMaterials::Argon = CellMaterial(MATTERSTATE_GAS, 83.95, 87.45,          ViscosityCurve(0.02261));
    CellMaterials::Potassium = CellMaterial(MATTERSTATE_SOLID, 1033, 336.8);
    CellMaterials::Calcium = CellMaterial(MATTERSTATE_SOLID, 1757, 1112);
    CellMaterials::Scandium = CellMaterial(MATTERSTATE_SOLID, 3109, 1814);
    CellMaterials::Titanium = CellMaterial(MATTERSTATE_SOLID, 3560, 1945);
    CellMaterials::Vanadium = CellMaterial(MATTERSTATE_SOLID, 3650, 2163);
    CellMaterials::Chromium = CellMaterial(MATTERSTATE_SOLID, 2945, 2130);
    CellMaterials::Manganese = CellMaterial(MATTERSTATE_SOLID, 2335, 1518);
    CellMaterials::Iron = CellMaterial(MATTERSTATE_SOLID, 3023, 1808);
    CellMaterials::Cobalt = CellMaterial(MATTERSTATE_SOLID, 3143, 1768);
    CellMaterials::Nickel = CellMaterial(MATTERSTATE_SOLID, 3005, 1726);
    CellMaterials::Copper = CellMaterial(MATTERSTATE_SOLID, 2840, 1356.6);
    CellMaterials::Zinc = CellMaterial(MATTERSTATE_SOLID, 1180, 692.73);
    CellMaterials::Gallium = CellMaterial(MATTERSTATE_SOLID, 2478, 302.92);
    CellMaterials::Germanium = CellMaterial(MATTERSTATE_SOLID, 3107, 1211.5);
    CellMaterials::Arsenic = CellMaterial(MATTERSTATE_SOLID, 876, 1090);
    CellMaterials::Selenium = CellMaterial(MATTERSTATE_SOLID, 958, 494);
    CellMaterials::Bromine = CellMaterial(MATTERSTATE_LIQUID, 265.95, 331.85,   ViscosityCurve::curveInaccurateLiquid25C(0.944,265.95));
    CellMaterials::Krypton = CellMaterial(MATTERSTATE_GAS, 116, 120.85,         ViscosityCurve(0.02538));
    CellMaterials::Rubidium = CellMaterial(MATTERSTATE_SOLID, 961, 312.63);
    CellMaterials::Strontium = CellMaterial(MATTERSTATE_SOLID, 1655, 1042);
    CellMaterials::Yttrium = CellMaterial(MATTERSTATE_SOLID, 3611, 1795);
    CellMaterials::Zirconium = CellMaterial(MATTERSTATE_SOLID, 4682, 2128);
    CellMaterials::Niobium = CellMaterial(MATTERSTATE_SOLID, 5015, 2742);
    CellMaterials::Molybdenum = CellMaterial(MATTERSTATE_SOLID, 4912, 2896);
    CellMaterials::Technetium = CellMaterial(MATTERSTATE_SOLID, 4538, 2477);
    CellMaterials::Ruthenium = CellMaterial(MATTERSTATE_SOLID, 4425, 2610);
    CellMaterials::Rhodium = CellMaterial(MATTERSTATE_SOLID, 3970, 2236);
    CellMaterials::Palladium = CellMaterial(MATTERSTATE_SOLID, 3240, 1825);
    CellMaterials::Silver = CellMaterial(MATTERSTATE_SOLID, 2436, 1235.08);
    CellMaterials::Cadmium = CellMaterial(MATTERSTATE_SOLID, 1040, 594.26);
    CellMaterials::Indium = CellMaterial(MATTERSTATE_SOLID, 2350, 429.78);
    CellMaterials::Tin = CellMaterial(MATTERSTATE_SOLID, 2876, 505.12);
    CellMaterials::Antimony = CellMaterial(MATTERSTATE_SOLID, 1860, 903.91);
    CellMaterials::Tellurium = CellMaterial(MATTERSTATE_SOLID, 1261, 722.72);
    CellMaterials::Iodine = CellMaterial(MATTERSTATE_SOLID, 457.5, 386.7);
    CellMaterials::Xenon = CellMaterial(MATTERSTATE_GAS, 161.39, 165.1,         ViscosityCurve(0.02308));
    CellMaterials::Cesium = CellMaterial(MATTERSTATE_SOLID, 944, 301.54);
    CellMaterials::Barium = CellMaterial(MATTERSTATE_SOLID, 2078, 1002);
    CellMaterials::Lanthanum = CellMaterial(MATTERSTATE_SOLID, 3737, 1191);
    CellMaterials::Cerium = CellMaterial(MATTERSTATE_SOLID, 3715, 1071);
    CellMaterials::Praseodymium = CellMaterial(MATTERSTATE_SOLID, 3785, 1204);
    CellMaterials::Neodymium = CellMaterial(MATTERSTATE_SOLID, 3347, 1294);
    CellMaterials::Promethium = CellMaterial(MATTERSTATE_SOLID, 3273, 1315);
    CellMaterials::Samarium = CellMaterial(MATTERSTATE_SOLID, 2067, 1347);
    CellMaterials::Europium = CellMaterial(MATTERSTATE_SOLID, 1800, 1095);
    CellMaterials::Gadolinium = CellMaterial(MATTERSTATE_SOLID, 3545, 1585);
    CellMaterials::Terbium = CellMaterial(MATTERSTATE_SOLID, 3500, 1629);
    CellMaterials::Dysprosium = CellMaterial(MATTERSTATE_SOLID, 2840, 1685);
    CellMaterials::Holmium = CellMaterial(MATTERSTATE_SOLID, 2968, 1747);
    CellMaterials::Erbium = CellMaterial(MATTERSTATE_SOLID, 3140, 1802);
    CellMaterials::Thulium = CellMaterial(MATTERSTATE_SOLID, 2223, 1818);
    CellMaterials::Ytterbium = CellMaterial(MATTERSTATE_SOLID, 1469, 1092);
    CellMaterials::Lutetium = CellMaterial(MATTERSTATE_SOLID, 3668, 1936);
    CellMaterials::Hafnium = CellMaterial(MATTERSTATE_SOLID, 4875, 2504);
    CellMaterials::Tantalum = CellMaterial(MATTERSTATE_SOLID, 5730, 3293);
    CellMaterials::Tungsten = CellMaterial(MATTERSTATE_SOLID, 5825, 3695);
    CellMaterials::Rhenium = CellMaterial(MATTERSTATE_SOLID, 5870, 3455);
    CellMaterials::Osmium = CellMaterial(MATTERSTATE_SOLID, 5300, 3300);
    CellMaterials::Iridium = CellMaterial(MATTERSTATE_SOLID, 4700, 2720);
    CellMaterials::Platinum = CellMaterial(MATTERSTATE_SOLID, 4100, 2042.1);
    CellMaterials::Gold = CellMaterial(MATTERSTATE_SOLID, 3130, 1337.58);
    CellMaterials::Mercury = CellMaterial(MATTERSTATE_LIQUID, 234.31, 629.88,   ViscosityCurve::curveInaccurateLiquid25C(1.526,234.31));
    CellMaterials::Thallium = CellMaterial(MATTERSTATE_SOLID, 1746, 577);
    CellMaterials::Lead = CellMaterial(MATTERSTATE_SOLID, 2023, 600.65);
    CellMaterials::Bismuth = CellMaterial(MATTERSTATE_SOLID, 1837, 544.59);
    CellMaterials::Astatine = CellMaterial(MATTERSTATE_SOLID, 610, 575);
    CellMaterials::Radon = CellMaterial(MATTERSTATE_SOLID, 211.4, 202);
    CellMaterials::Francium = CellMaterial(MATTERSTATE_SOLID, 950, 300);
    CellMaterials::Radium = CellMaterial(MATTERSTATE_SOLID, 1413, 973);
    CellMaterials::Thorium = CellMaterial(MATTERSTATE_SOLID, 5060, 2028);
    CellMaterials::Protactinium = CellMaterial(MATTERSTATE_SOLID, 4300, 1845);
    CellMaterials::Uranium = CellMaterial(MATTERSTATE_SOLID, 4407, 1408);
    CellMaterials::Neptunium = CellMaterial(MATTERSTATE_SOLID, 4175, 912);
    CellMaterials::Plutonium = CellMaterial(MATTERSTATE_SOLID, 3505, 913);
    CellMaterials::Americium = CellMaterial(MATTERSTATE_SOLID, 2880, 1449);
}
