//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Atom.h"

#ifndef ELEM_H_
#define ELEM_H_

// density in g/cm3

// This is a list of constants for each Atom.
//                         Group  Protons  Neutrons  Electrons  Density  Resistivity, ThermalConduct, Melting, Boiling, Valence
const Atom Hydrogen = new Atom("Hydrogen", "H", 1, 1, 1, 0,1, 0.00008988,UNKNOWN, 0.0001805, 14.01,20.28, 14.304, 1, COLOR_None,ELEM_NonMetal);
const Atom Helium = new Atom("Helium", "He", 18, 1, 2, 2,2, 0.0001785,UNKNOWN, 0.0001513, 0.956,4.22, 5.193, 0, COLOR_None,ELEM_Noble);
const Atom Lithium = new Atom("Lithium", "Li", 1, 2, 3, 4,3, 0.534,0.000000094, 0.085, 453.69,1560, 3.582, 1, COLOR_Silver,ELEM_Alkali);
const Atom Beryllium = new Atom("Beryllium", "Be", 2, 2, 4, 5,4, 1.85,0.00000004, 0.19, 1560,2742, 1.825, 2, COLOR_SlateGray,ELEM_Alkaline);
const Atom Boron = new Atom("Boron", "B", 13, 2, 5, 6,5, 2.34,10000, 0.027, 2349,4200, 1.026, 3, COLOR_Black,ELEM_Metalloid);
const Atom Carbon = new Atom("Carbon", "C", 14, 2, 6, 6,6, 2.267,0.00001, 0.14, 3800,4300, 0.709, 4, COLOR_Black,ELEM_NonMetal);
const Atom Nitrogen = new Atom("Nitrogen", "N", 15, 2, 7, 0,7, 0.0012506,UNKNOWN, 0.00002583, 63.15,77.36, 1.04, 3, COLOR_None,ELEM_NonMetal);
const Atom Oxygen = new Atom("Oxygen", "O", 16, 2, 8, 8,8, 0.001429,UNKNOWN, 0.00002658, 54.36,90.2, 0.918, 2, COLOR_None,ELEM_NonMetal);
const Atom Fluorine = new Atom("Fluorine", "F", 17, 2, 9, 10,9, 0.001696,UNKNOWN, 0.0000277, 53.53,85.03, 0.824, 1, COLOR_None,ELEM_Halogen);
const Atom Neon = new Atom("Neon", "Ne", 18, 2, 10, 10,10, 0.0008999,UNKNOWN, 0.0000491, 24.56,27.07, 1.03, 0, COLOR_None,ELEM_Noble);
const Atom Sodium = new Atom("Sodium", "Na", 1, 3, 11, 12,11, 0.971,0.000000047, 0.14, 370.87,1156, 1.228, 1, COLOR_Silver,ELEM_Alkali);
const Atom Magnesium = new Atom("Magnesium", "Mg", 2, 3, 12, 12,12, 1.738,0.000000044, 0.16, 923,1363, 1.023, 2, COLOR_Silver,ELEM_Alkaline);
const Atom Aluminum = new Atom("Aluminum", "Al", 13, 3, 13, 14,12, 2.698,0.000000026, 0.235, 933.47,2792, 0.897, 3, COLOR_Silver,ELEM_Poor);
const Atom Silicon = new Atom("Silicon", "Si", 14, 3, 14, 14,13, 2.3296,0.001, 0.15, 1687,3538, 0.705, 4, COLOR_Gray,ELEM_Metalloid);
const Atom Phosphorus = new Atom("Phosphorus", "P", 15, 3, 15, 16,14, 1.82,0.0000001, 0.000236, 317.3,550, 0.769, 5, COLOR_None,ELEM_NonMetal);
const Atom Sulfur = new Atom("Sulfur", "S", 16, 3, 16, 16,15, 2.067,1E+015, 0.000205, 388.36,717.87, 0.71, 6, COLOR_Yellow,ELEM_NonMetal);
const Atom Chlorine = new Atom("Chlorine", "Cl", 17, 3, 17, 18,16, 0.003214,100, 0.0000089, 171.6,239.11, 0.479, 5, COLOR_Yellow,ELEM_NonMetal);
const Atom Argon = new Atom("Argon", "Ar", 18, 3, 18, 22,17, 0.0017837,UNKNOWN, 0.00001772, 83.8,87.3, 0.52, 0, COLOR_None,ELEM_Noble);
const Atom Potassium = new Atom("Potassium", "K", 1, 4, 19, 20,18, 0.862,0.00000007, 0.1, 336.53,1032, 0.757, 1, COLOR_Silver,ELEM_Alkali);
const Atom Calcium = new Atom("Calcium", "Ca", 2, 4, 20, 20,19, 1.54,0.000000034, 0.2, 1115,1757, 0.647, 2, COLOR_Silver,ELEM_Alkaline);
const Atom Scandium = new Atom("Scandium", "Sc", 3, 4, 21, 24,20, 2.989,0.00000055, 0.016, 1814,3109, 0.568, 3, COLOR_Silver,ELEM_Transition);
const Atom Titanium = new Atom("Titanium", "Ti", 4, 4, 22, 26,21, 4.54,0.0000004, 0.022, 1941,3560, 0.523, 4, COLOR_Silver,ELEM_Transition);
const Atom Vanadium = new Atom("Vanadium", "V", 5, 4, 23, 28,22, 6.11,0.0000002, 0.031, 2183,3680, 0.489, 5, COLOR_Silver,ELEM_Transition);
const Atom Chromium = new Atom("Chromium", "Cr", 6, 4, 24, 28,23, 7.15,0.00000013, 0.094, 2180,2944, 0.449, 6, COLOR_Silver,ELEM_Transition);
const Atom Manganese = new Atom("Manganese", "Mn", 7, 4, 25, 30,24, 7.44,0.0000016, 0.0078, 1519,2334, 0.479, 4, COLOR_Silver,ELEM_Transition);
const Atom Iron = new Atom("Iron", "Fe", 8, 4, 26, 30,25, 7.874,0.000000097, 0.08, 1811,3134, 0.449, 3, COLOR_Gray,ELEM_Transition);
const Atom Cobalt = new Atom("Cobalt", "Co", 9, 4, 27, 32,26, 8.86,0.00000006, 0.1, 1768,3200, 0.421, 4, COLOR_Gray,ELEM_Transition);
const Atom Nickel = new Atom("Nickel", "Ni", 10, 4, 28, 31,27, 8.912,0.00000007, 0.091, 1728,3186, 0.444, 2, COLOR_Gray,ELEM_Transition);
const Atom Copper = new Atom("Copper", "Cu", 11, 4, 29, 35,28, 8.96,0.000000017, 0.4, 1357.77,2835, 0.385, 2, COLOR_Copper,ELEM_Transition);
const Atom Zinc = new Atom("Zinc", "Zn", 12, 4, 30, 35,29, 7.134,0.000000059, 0.12, 692.88,1180, 0.388, 2, COLOR_SlateGray,ELEM_Transition);
const Atom Gallium = new Atom("Gallium", "Ga", 13, 4, 31, 39,30, 5.907,0.00000014, 0.029, 302.9146,2477, 0.371, 3, COLOR_Silver,ELEM_Poor);
const Atom Germanium = new Atom("Germanium", "Ge", 14, 4, 32, 41,31, 5.323,0.0005, 0.06, 1211.4,3106, 0.32, 4, COLOR_Gray,ELEM_Metalloid);
const Atom Arsenic = new Atom("Arsenic", "As", 15, 4, 33, 42,32, 5.776,0.0000003, 0.05, 10907,887, 0.329, 5, COLOR_Silver,ELEM_Metalloid);
const Atom Selenium = new Atom("Selenium", "Se", 16, 4, 34, 45,33, 4.809,UNKNOWN, 0.00052, 453,958, 0.321, 6, COLOR_Gray,ELEM_NonMetal);
const Atom Bronium = new Atom("Bronium", "Br", 17, 4, 35, 45,34, 3.122,10000000000, 0.00012, 265.8,332, 0.474, 7, COLOR_Red,ELEM_Halogen);
const Atom Krypton = new Atom("Krypton", "Kr", 18, 4, 36, 48,35, 0.003733,UNKNOWN, 0.00000943, 115.79,119.93, 0.248, 2, COLOR_None,ELEM_Noble);
const Atom Rubidium = new Atom("Rubidium", "Rb", 1, 5, 37, 48,36, 1.532,0.00000012, 0.058, 312.46,961, 0.363, 1, COLOR_Silver,ELEM_Alkali);
const Atom Strontium = new Atom("Strontium", "Sr", 2, 5, 38, 50,37, 2.64,0.00000013, 0.035, 1050,1655, 0.301, 2, COLOR_Silver,ELEM_Alkaline);
const Atom Yttrium = new Atom("Yttrium", "Y", 3, 5, 39, 50,38, 4.469,0.00000056, 0.017, 1799,3609, 0.298, 3, COLOR_Silver,ELEM_Transition);
const Atom Zirconium = new Atom("Zirconium", "Zr", 4, 5, 40, 51,39, 6.506,0.00000042, 0.023, 2128,4682, 0.278, 4, COLOR_Silver,ELEM_Transition);
const Atom Niobium = new Atom("Niobium", "Nb", 5, 5, 41, 52,40, 8.57,0.00000015, 0.054, 2750,5017, 0.265, 5, COLOR_Gray,ELEM_Transition);
const Atom Molybdenum = new Atom("Molybdenum", "Mo", 6, 5, 42, 54,41, 10.22,0.00000005, 0.139, 2896,4912, 0.251, 6, COLOR_Gray,ELEM_Transition);
const Atom Technetium = new Atom("Technetium", "Tc", 7, 5, 43, 55,42, 11.5,0.0000002, 0.051, 2430,4538, UNKNOWN, 7, COLOR_Silver,ELEM_Transition);
const Atom Ruthenium = new Atom("Ruthenium", "Ru", 8, 5, 44, 57,43, 12.37,0.000000071, 0.12, 2607,4423, 0.238, 6, COLOR_Silver,ELEM_Transition);
const Atom Rhodium = new Atom("Rhodium", "Rh", 9, 5, 45, 58,44, 12.41,0.000000043, 0.15, 2237,3968, 0.243, 6, COLOR_Silver,ELEM_Transition);
const Atom Palladium = new Atom("Palladium", "Pd", 10, 5, 46, 60,45, 12.02,0.0000001, 0.072, 1828.05,3236, 0.244, 4, COLOR_Silver,ELEM_Transition);
const Atom Silver = new Atom("Silver", "Ag", 11, 5, 47, 61,46, 10.501,0.000000016, 0.43, 1234.93,2435, 0.235, 2, COLOR_Silver,ELEM_Transition);
const Atom Cadmium = new Atom("Cadmium", "Cd", 12, 5, 48, 64,47, 8.69,0.00000007, 0.097, 594.22,1040, 0.232, 2, COLOR_Silver,ELEM_Transition);
const Atom Indium = new Atom("Indium", "In", 13, 5, 49, 66,48, 7.31,0.00000008, 0.082, 429.75,2345, 0.233, 3, COLOR_Silver,ELEM_Poor);
const Atom Tin = new Atom("Tin", "Sn", 14, 5, 50, 69,49, 7.287,0.00000011, 0.067, 505.08,2875, 0.228, 4, COLOR_Silver,ELEM_Poor);
const Atom Antimony = new Atom("Antimony", "Sb", 15, 5, 51, 71,50, 6.685,0.0000004, 0.024, 903.78,1860, 0.207, 5, COLOR_Silver,ELEM_Metalloid);
const Atom Tellurium = new Atom("Tellurium", "Te", 16, 5, 52, 76,51, 6.232,0.0001, 0.003, 722.66,1261, 0.202, 6, COLOR_Silver,ELEM_Metalloid);
const Atom Iodine = new Atom("Iodine", "I", 17, 5, 53, 74,52, 4.93,10000000, 0.000449, 386.85,457.4, 0.214, 7, COLOR_SlateGray,ELEM_Halogen);
const Atom Xenon = new Atom("Xenon", "Xe", 18, 5, 54, 77,53, 0.005887,UNKNOWN, 0.00000565, 161.4,165.03, 0.158, 6, COLOR_None,ELEM_Noble);
const Atom Caesium = new Atom("Caesium", "Cs", 1, 6, 55, 81,54, 1.873,0.0000002, 0.036, 301.59,944, 0.242, 1, COLOR_Silver,ELEM_Alkali);
const Atom Barium = new Atom("Barium", "Ba", 2, 6, 56, 82,55, 3.594,0.00000035, 0.018, 1000,2170, 0.204, 2, COLOR_Silver,ELEM_Alkaline);
const Atom Lanthanum = new Atom("Lanthanum", "La", 0, 6, 57, 82,56, 6.145,0.00000061, 0.013, 1193,3737, 0.195, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Cerium = new Atom("Cerium", "Ce", 0, 6, 58, 82,57, 6.77,0.00000074, 0.011, 1068,3716, 0.192, 4, COLOR_Silver,ELEM_Lanthanide);
const Atom Praseodymium = new Atom("Praseodymium", "Pr", 0, 6, 59, 84,58, 6.773,0.0000007, 0.013, 1208,3793, 0.193, 4, COLOR_Silver,ELEM_Lanthanide);
const Atom Neodymium = new Atom("Neodymium", "Nd", 0, 6, 60, 84,59, 7.007,0.00000064, 0.017, 1297,3347, 0.19, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Promethium = new Atom("Promethium", "Pm", 0, 6, 61, 88,60, 7.26,0.00000075, 0.015, 1315,3273, UNKNOWN, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Samarium = new Atom("Samarium", "Sm", 0, 6, 62, 89,61, 7.52,0.00000094, 0.013, 1345,2067, 0.197, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Europium = new Atom("Europium", "Eu", 0, 6, 63, 93,62, 5.243,0.0000009, 0.014, 1099,1802, 0.182, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Gadolinium = new Atom("Gadolinium", "Gd", 0, 6, 64, 94,63, 7.895,0.0000013, 0.011, 1585,3546, 0.236, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Terbium = new Atom("Terbium", "Tb", 0, 6, 65, 97,64, 8.229,0.0000012, 0.011, 1629,3503, 0.182, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Dysprosium = new Atom("Dysprosium", "Dy", 0, 6, 66, 98,65, 8.55,0.00000091, 0.011, 1680,2840, 0.17, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Holmium = new Atom("Holmium", "Ho", 0, 6, 67, 99,66, 8.795,0.00000094, 0.016, 1734,2993, 0.165, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Erbium = new Atom("Erbium", "Er", 0, 6, 68, 100,67, 9.066,0.00000086, 0.015, 1802,3141, 0.168, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Thulmium = new Atom("Thulmium", "Tm", 0, 6, 69, 103,68, 9.321,0.0000007, 0.017, 1818,2223, 0.16, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Ytterbium = new Atom("Ytterbium", "Yb", 0, 6, 70, 104,69, 6.965,0.00000028, 0.039, 1097,1469, 0.155, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Lutetium = new Atom("Lutetium", "Lu", 3, 6, 71, 104,70, 9.84,0.00000056, 0.016, 1925,3675, 0.154, 3, COLOR_Silver,ELEM_Lanthanide);
const Atom Hafnium = new Atom("Hafnium", "Hf", 4, 6, 72, 106,71, 13.31,0.0000003, 0.023, 2506,4876, 0.144, 4, COLOR_Gray,ELEM_Transition);
const Atom Tantalium = new Atom("Tantalium", "Ta", 5, 6, 73, 108,72, 16.654,0.00000013, 0.057, 3290,5731, 0.14, 5, COLOR_Gray,ELEM_Transition);
const Atom Tungsten = new Atom("Tungsten", "W", 6, 6, 74, 110,73, 19.25,0.00000005, 0.17, 3695,5828, 0.132, 6, COLOR_Gray,ELEM_Transition);
const Atom Rhenium = new Atom("Rhenium", "Re", 7, 6, 75, 111,74, 21.02,0.00000018, 0.048, 3459,5869, 0.137, 7, COLOR_Gray,ELEM_Transition);
const Atom Osmium = new Atom("Osmium", "Os", 8, 6, 76, 114,75, 22.61,0.000000081, 0.088, 3306,5285, 0.13, 6, COLOR_SlateGray,ELEM_Transition);
const Atom Iridium = new Atom("Iridium", "Ir", 9, 6, 77, 115,76, 22.56,0.000000047, 0.15, 2719,4701, 0.131, 6, COLOR_Silver,ELEM_Transition);
const Atom Platinum = new Atom("Platinum", "Pt", 10, 6, 78, 117,77, 21.46,0.00000011, 0.072, 2041.4,4098, 0.133, 6, COLOR_Gray,ELEM_Transition);
const Atom Gold = new Atom("Gold", "Au", 11, 6, 79, 118,78, 19.282,0.000000022, 0.32, 1337.33,3129, 0.129, 5, COLOR_Gold,ELEM_Transition);
const Atom Mercury = new Atom("Mercury", "Hg", 12, 6, 80, 121,79, 13.5336,0.00000096, 0.0083, 234.43,629.88, 0.14, 2, COLOR_Silver,ELEM_Transition);
const Atom Thallium = new Atom("Thallium", "Tl", 13, 6, 81, 123,80, 11.85,0.00000015, 0.046, 577,1746, 0.129, 3, COLOR_Silver,ELEM_Poor);
const Atom Lead = new Atom("Lead", "Pb", 14, 6, 82, 126,81, 11.342,0.00000021, 0.035, 600.61,2022, 0.129, 4, COLOR_SlateGray,ELEM_Poor);
const Atom Bismuth = new Atom("Bismuth", "Bi", 15, 6, 83, 126,82, 9.807,0.0000013, 0.008, 544.7,1837, 0.122, 5, COLOR_Gray,ELEM_Poor);
const Atom Polonium = new Atom("Polonium", "Po", 16, 6, 84, 125,83, 9.32,0.00000043, UNKNOWN, 527,1235, UNKNOWN, 6, COLOR_Silver,ELEM_Metalloid);
const Atom Astanine = new Atom("Astanine", "At", 17, 6, 85, 125,84, 7,UNKNOWN, 0.002, 575,610, UNKNOWN, 7, COLOR_Silver,ELEM_Halogen);
const Atom Radon = new Atom("Radon", "Rn", 18, 6, 86, 136,85, 0.00973,UNKNOWN, 0.00000361, 202,211.3, 0.094, 6, COLOR_None,ELEM_Noble);
const Atom Francium = new Atom("Francium", "Fr", 1, 7, 87, 136,86, 1.87,UNKNOWN, UNKNOWN, 300,950, UNKNOWN, 3, COLOR_Silver,ELEM_Alkali);
const Atom Radium = new Atom("Radium", "Ra", 2, 7, 88, 138,87, 5.5,0.000001, 0.019, 973,2010, UNKNOWN, 2, COLOR_Silver,ELEM_Alkaline);
const Atom Actinium = new Atom("Actinium", "Ac", 0, 7, 89, 138,88, 10.07,UNKNOWN, 0.012, 1323,3471, 0.12, 3, COLOR_Silver,ELEM_Actinide);
const Atom Thorium = new Atom("Thorium", "Th", 0, 7, 90, 142,89, 11.72,0.00000015, 0.054, 2115,5061, 0.113, 4, COLOR_Silver,ELEM_Actinide);
const Atom Protactinium = new Atom("Protactinium", "Pa", 0, 7, 91, 140,90, 15.37,0.00000018, 0.047, 1841,4300, UNKNOWN, 5, COLOR_Silver,ELEM_Actinide);
const Atom Uranium = new Atom("Uranium", "U", 0, 7, 92, 146,91, 18.95,0.00000028, 0.027, 1405.3,4404, 0.116, 6, COLOR_Silver,ELEM_Actinide);
const Atom Neptunium = new Atom("Neptunium", "Np", 0, 7, 93, 144,92, 20.45,0.0000012, 0.006, 917,4273, UNKNOWN, 6, COLOR_Silver,ELEM_Actinide);
const Atom Plutonium = new Atom("Plutonium", "Pu", 0, 7, 94, 150,93, 19.84,0.0000015, 0.006, 912.5,3501, UNKNOWN, 6, COLOR_Silver,ELEM_Actinide);
const Atom Americium = new Atom("Americium", "Am", 0, 7, 95, 148,94, 13.69,UNKNOWN, 0.01, 1449,2880, UNKNOWN, 4, COLOR_Silver,ELEM_Actinide);
const Atom Curium = new Atom("Curium", "Cm", 0, 7, 96, 151,95, 13.51,UNKNOWN, UNKNOWN, 1613,3383, UNKNOWN, 4, COLOR_Silver,ELEM_Actinide);
const Atom Berkelium = new Atom("Berkelium", "Bk", 0, 7, 97, 150,96, 14.79,UNKNOWN, 0.01, 1259,UNKNOWN, UNKNOWN, 4, COLOR_SlateGray,ELEM_Actinide);
const Atom Californium = new Atom("Californium", "Cf", 0, 7, 98, 153,97, 15.1,UNKNOWN, UNKNOWN, 1173,UNKNOWN, UNKNOWN, 4, COLOR_SlateGray,ELEM_Actinide);
const Atom Einsteinium = new Atom("Einsteinium", "Es", 0, 7, 99, 153,98, 13.5,UNKNOWN, UNKNOWN, 1133,UNKNOWN, UNKNOWN, 4, COLOR_SlateGray,ELEM_Actinide);
const Atom Fermium = new Atom("Fermium", "Fm", 0, 7, 100, 157,99, UNKNOWN,UNKNOWN, UNKNOWN, 1800,UNKNOWN, UNKNOWN, 3, COLOR_SlateGray,ELEM_Actinide);
const Atom Mendelevium = new Atom("Mendelevium", "Md", 0, 7, 101, 157,100, UNKNOWN,UNKNOWN, UNKNOWN, 1100,UNKNOWN, UNKNOWN, 3, COLOR_SlateGray,ELEM_Actinide);
const Atom Nobelium = new Atom("Nobelium", "No", 0, 7, 102, 157,101, UNKNOWN,UNKNOWN, UNKNOWN, 1100,UNKNOWN, UNKNOWN, 3, COLOR_SlateGray,ELEM_Actinide);
const Atom Lawrencium = new Atom("Lawrencium", "Lr", 3, 7, 103, 159,102, UNKNOWN,UNKNOWN, UNKNOWN, 1900,UNKNOWN, UNKNOWN, 3, COLOR_SlateGray,ELEM_Actinide);
const Atom Rutherfordium = new Atom("Rutherfordium", "Rf", 4, 7, 104, 157,103, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, 4, COLOR_SlateGray,ELEM_Transition);
const Atom Dubnium = new Atom("Dubnium", "Db", 5, 7, 105, 157,104, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, 5, COLOR_SlateGray,ELEM_Transition);
const Atom Seaborgium = new Atom("Seaborgium", "Sg", 6, 7, 106, 157,105, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, 6, COLOR_SlateGray,ELEM_Transition);
const Atom Bohrium = new Atom("Bohrium", "Bh", 7, 7, 107, 155,106, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, 7, COLOR_SlateGray,ELEM_Transition);
const Atom Hassium = new Atom("Hassium", "Hs", 8, 7, 108, 157,107, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN, COLOR_SlateGray,ELEM_Transition);
const Atom Meitnerium = new Atom("Meitnerium", "Mt", 9, 7, 109, 159,108, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN, COLOR_SlateGray,ELEM_Transition);
const Atom Darmstadtium = new Atom("Darmstadtium", "Ds", 10, 7, 110, 161,109, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN, COLOR_SlateGray,ELEM_Transition);
const Atom Roentgenium = new Atom("Roentgenium", "Rg", 11, 7, 111, 165,110, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN, COLOR_SlateGray,ELEM_Transition);
const Atom Copernicium = new Atom("Copernicium", "Cn", 12, 7, 112,  ,111, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN, COLOR_SlateGray,ELEM_Transition);
const Atom Ununtrium = new Atom("Ununtrium", "Uut", 13, 7, 113,  ,112, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN, COLOR_SlateGray,ELEM_Poor);
const Atom Flerovium = new Atom("Flerovium", "Fl", 14, 7, 114,  ,113, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN, COLOR_SlateGray,ELEM_Poor);
const Atom Ununpentium = new Atom("Ununpentium", "Uup", 15, 7, 115,  ,114, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN, COLOR_SlateGray,ELEM_Poor);
const Atom Livermorium = new Atom("Livermorium", "Lv", 16, 7, 116,  ,115, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN, COLOR_SlateGray,ELEM_Poor);
const Atom Ununseptium = new Atom("Ununseptium", "Uup", 17, 7, 117,  ,116, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN,UNKNOWN, UNKNOWN, UNKNOWN, COLOR_SlateGray,ELEM_Halogen);
const Atom Ununoctium = new Atom("Ununoctium", "Uuo", 18, 7, 118,  ,117, UNKNOWN,UNKNOWN, UNKNOWN, 250,252, UNKNOWN, UNKNOWN, COLOR_None,ELEM_Noble);

// List of all of the elements by atomic number!
const Atom[118] atomList = {Hydrogen, Helium, Lithium, Beryllium, Boron, Carbon, Nitrogen, Oxygen, Fluorine, Neon, Sodium, Magnesium, Aluminum, Silicon, Phosphorus, Sulfur, Chlorine, Argon, Potassium, Calcium, Scandium, Titanium, Vanadium, Chromium, Manganese, Iron, Cobalt, Nickel, Copper, Zinc, Gallium, Germanium, Arsenic, Selenium, Bronium, Krypton, Rubidium, Strontium, Yttrium, Zirconium, Niobium, Molybdenum, Technetium, Ruthenium, Rhodium, Palladium, Silver, Cadmium, Indium, Tin, Antimony, Tellurium, Iodine, Xenon, Caesium, Barium, Lanthanum, Cerium, Praseodymium, Neodymium, Promethium, Samarium, Europium, Gadolinium, Terbium, Dysprosium, Holmium, Erbium, Thulmium, Ytterbium, Lutetium, Hafnium, Tantalium, Tungsten, Rhenium, Osmium, Iridium, Platinum, Gold, Mercury, Thallium, Lead, Bismuth, Polonium, Astanine, Radon, Francium, Radium, Actinium, Thorium, Protactinium, Uranium, Neptunium, Plutonium, Americium, Curium, Berkelium, Californium, Einsteinium, Fermium, Mendelevium, Nobelium, Lawrencium, Rutherfordium, Dubnium, Seaborgium, Bohrium, Hassium, Meitnerium, Darmstadtium, Roentgenium, Copernicium, Ununtrium, Flerovium, Ununpentium, Livermorium, Ununseptium, Ununoctium};

#endif