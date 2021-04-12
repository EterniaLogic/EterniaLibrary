#ifndef BASICCELLMATERIALS_H_
#define BASICCELLMATERIALS_H_

#include "CellMaterial.h"

// Initial temperature assumed to be room temperature

// Basic Materials, such as Water, Metals, Mercury, etc.
// =CONCAT("", A2, " = CellMaterial(MATTERSTATE_",F2,", ",D2,", ",E2,");")


void init_cellmaterials();

// Note that metals are treated like mercury when they are melted, following a similar curve just with the temperature shifted upwards.
// gas viscosity is more 'free'

namespace CellMaterials{
    // (state, melting point, boiling point kelvin, Viscosity?)

    static CellMaterial Water,
        CarbonDioxide,
    
        // elements
        Hydrogen,
        Helium,
        Lithium,
        Beryllium,
        Boron,
        Carbon,
        Nitrogen,
        Oxygen,
        Fluorine,
        Neon,
        Sodium,
        Magnesium,
        Aluminum,
        Silicon,
        Phosphorus,
        Sulfur,
        Chlorine,
        Argon,
        Potassium,
        Calcium,
        Scandium,
        Titanium,
        Vanadium,
        Chromium,
        Manganese,
        Iron,
        Cobalt,
        Nickel,
        Copper,
        Zinc,
        Gallium,
        Germanium,
        Arsenic,
        Selenium,
        Bromine,
        Krypton,
        Rubidium,
        Strontium,
        Yttrium,
        Zirconium,
        Niobium,
        Molybdenum,
        Technetium,
        Ruthenium,
        Rhodium,
        Palladium,
        Silver,
        Cadmium,
        Indium,
        Tin,
        Antimony,
        Tellurium,
        Iodine,
        Xenon,
        Cesium,
        Barium,
        Lanthanum,
        Cerium,
        Praseodymium,
        Neodymium,
        Promethium,
        Samarium,
        Europium,
        Gadolinium,
        Terbium,
        Dysprosium,
        Holmium,
        Erbium,
        Thulium,
        Ytterbium,
        Lutetium,
        Hafnium,
        Tantalum,
        Tungsten,
        Rhenium,
        Osmium,
        Iridium,
        Platinum,
        Gold,
        Mercury,
        Thallium,
        Lead,
        Bismuth,
        Astatine,
        Radon,
        Francium,
        Radium,
        Thorium,
        Protactinium,
        Uranium,
        Neptunium,
        Plutonium,
        Americium;

};



#endif
