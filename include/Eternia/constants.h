#ifndef CONSTANTS_H_
#define CONSTANTS_H_
// copyright reserved.
#include <cstring>
#include "Data/CharString.h"

// Unknown constant used to define unknown doubles
#define UNKNOWN 1.111e-11

namespace physical {
    namespace unit { // conversion factor
        const double radian = 1.0;
        const double radians = radian;
        const double rad = radian;
        const double steradian = 1.0;
        const double steradians = steradian;
        const double sr = steradian;
        const double dollar = 1.0;
        const double dollars = dollar;
        const double cent = dollar/100.0;
        const double cents = cent;
        const double dozen = 12.0;
        const double doz = dozen;
        const double dz = dozen;
        namespace bakers {
            const double dozen = 13.0;
            const double doz = dozen;
            const double dz = dozen;
        }
        const double gross = 12.0*dozen;
        const double gro = gross;
        const double quire = 25.0;
        const double quires = quire;
        const double ream = 500.0;
        const double reams = ream;
        const double percent = 1.0/100.0;
        const double proof = percent/2.0;
        const double karat = 1.0/24.0;
        const double karats = karat;
        const double mole = 6.0221367e+23;
        const double moles = mole;
        const double mol = mole;
        const double pi = 3.14159265358979323846*radians;
        namespace arc {
            const double degree = pi/180.0;
            const double degrees = degree;
            const double minute = degree/60.0;
            const double minutes = minute;
            const double min = minute;
            const double second = minute/60.0;
            const double seconds = second;
            const double sec = second;
            const double grade = 0.9*degrees;
            const double grades = grade;
            namespace centesimal {
                const double minute = grade/100.0;
                const double minutes = minute;
                const double min = minute;
                const double second = grade/10000.0;
                const double seconds = second;
                const double sec = second;
            }
        }

        // SI units (mks)
        // Prefixes
        const double kilo = 1e3;
        const double mega = 1e6;
        const double tera = 1e9;
        const double giga = 1e12;
        const double peta = 1e15;
        const double exa = 1e18;
        const double zetta = 1e21;
        const double yotta = 1e24;
        // length
        const double meter = 1.0;
        const double meters = meter;
        const double m = meter;
        const double kilometer = 1000.0*meters;
        const double kilometers = kilometer;
        const double km = kilometer;
        const double decimeter = meters/10.0;
        const double decimeters = decimeter;
        const double dm = decimeter;
        const double centimeter = meters/100.0;
        const double centimeters = centimeter;
        const double cm = centimeter;
        const double millimeter = meters/1000.0;
        const double millimeters = millimeter;
        const double mm = millimeter;
        const double micron = meter/1000000.0;
        const double microns = micron;
        const double nanometer = meter/1000000000.0;
        const double nanometers = nanometer;
        const double nm = nanometer;
        const double decinanometer = meter/10000000000.0;
        const double decinanometers = decinanometer;
        const double Angstrom = decinanometer;
        const double Angstroms = Angstrom;
        const double Xunit = 1.00202e-13*meters;
        const double Xunits = Xunit;
        const double Fermi = meter/1000000000000000.0;
        const double Fermis = Fermi;
        // area
        const double hectare = 10000.0*meter*meter;
        const double hectares = hectare;
        const double ha = hectare;
        // volume
        const double stere = meter*meter*meter;
        const double steres = stere;
        const double liter = stere/1000.0;
        const double liters = liter;
        const double l = liter;
        const double milliliter = stere/1000000.0;
        const double milliliters = milliliter;
        const double ml = milliliter;
        const double cc = milliliter;
        namespace displacement {
            const double ton = stere;
            const double tons = ton;
            const double t = ton;
        }
        // mass
        const double kilogram = 1.0;
        const double kilograms = kilogram;
        const double kg = kilogram;
        const double quintal = 100.0*kilograms;
        const double quintals = quintal;
        const double doppelzentner = quintal;
        const double doppelzentners = doppelzentner;
        const double gram = kilograms/1000.0;
        const double grams = gram;
        const double g = gram;
        const double milligram = kilogram/1000000.0;
        const double milligrams = milligram;
        const double mg = milligram;
        namespace metric { // weight
            const double carat = gram/5.0;
            const double carats = carat;
            const double ton = 1000.0*kilograms;
            const double tons = ton;
            const double t = ton;
        }
        // time
        const double second = 1.0;
        const double seconds = second;
        const double sec = second;
        const double s = second;
        const double millisecond = second/1000.0;
        const double milliseconds = millisecond;
        const double ms = millisecond;
        const double microsecond = second/1000000.0;
        const double microseconds = microsecond;
        const double us = microsecond;
        const double nanosecond = second/1000000000.0;
        const double nanoseconds = nanosecond;
        const double picosecond = second/1000000000000.0;
        const double picoseconds = picosecond;
        const double minute = 60.0*seconds;
        const double minutes = minute;
        const double min = minute;
        const double hour = 60.0*minutes;
        const double hours = hour;
        const double hr = hour;
        const double day = 24.0*hours;
        const double days = day;
        const double da = day;
        const double week = 7.0*days;
        const double weeks = week;
        const double fortnight = 2.0*weeks;
        const double fortnights = fortnight;
        const double year = 365.2421896698*days;
        const double years = year;
        const double yr = year;
        const double month = year/12.0;
        const double months = month;
        const double mo = month;
        const double decade = 10.0*years;
        const double decades = decade;
        const double century = 100.0*years;
        const double centuries = century;
        const double millenium = 1000.0*years;
        const double millenia = millenium;
        // temporal frequency
        const double Hertz = 1.0/second;
        const double Hz = Hertz;
        const double kiloHertz = kilo*Hertz;
        const double kHz = kiloHertz;
        const double megaHertz = mega*Hertz;
        const double MHz = megaHertz;
        const double gigaHertz = giga*Hertz;
        const double GHz = gigaHertz;
        const double teraHertz = tera*Hertz;
        const double THz = teraHertz;
        const double petaHertz = peta*Hertz;
        const double PHz = petaHertz;
        const double exaHertz = exa*Hertz;
        const double EHz = exaHertz;
        const double zettaHertz = zetta*Hertz;
        const double ZHz = zettaHertz;
        const double yottaHertz = yotta*Hertz;
        const double YHz = yottaHertz;
        // spacial frequency
        const double diopter = 1.0/meter;
        const double diopters = diopter;
        // speed
        const double kph = kilometers/hour;
        // radioactivity
        const double Becquerel = 1.0/second;
        const double Becquerels = Becquerel;
        const double Bq = Becquerel;
        const double Rutherford = 1000000.0*Becquerels;
        const double Rutherfords = Rutherford;
        const double Curie = 3.7e+10*Becquerels;
        const double Curies = Curie;
        const double Ci = Curie;
        // force
        const double Newton = kilogram*meter/(second*second);
        const double Newtons = Newton;
        const double N = Newton;
        const double dyne = Newton/100000.0;
        const double dynes = dyne;
        const double dyn = dyne;
        // pressure
        const double Pascal = Newton/(meter*meter);
        const double Pascals = Pascal;
        const double Pa = Pascal;
        const double Barie = Pascal/10.0;
        const double Baries = Barie;
        const double Barye = Barie;
        const double Baryes = Barye;
        const double pieze = 1000.0*Pascals;
        const double piezes = pieze;
        const double pz = pieze;
        const double bar = 10000.0*Pascals;
        const double bars = bar;
        const double Torr = 133.3224*Pascals;
        const double atmosphere = 760.0*Torr;
        const double atmospheres = atmosphere;
        const double atm = atmosphere;
        // energy
        const double Joule = Newton*meter;
        const double Joules = Joule;
        const double J = Joule;
        const double erg = Joule/10000000.0;
        const double ergs = erg;
        const double kiloWatthour = 3600000.0*Joules;
        const double kiloWatthours = kiloWatthour;
        const double kWh = kiloWatthour;
        // power
        const double Watt = Joule/second;
        const double Watts = Watt;
        const double W = Watt;
        const double kiloWatt = 1000.0*Watts;
        const double kiloWatts = kiloWatt;
        const double kW = kiloWatt;
        const double megaWatt = 1000000.0*Watts;
        const double megaWatts = megaWatt;
        const double MW = megaWatt;
        const double milliWatt = Watt/1000.0;
        const double milliWatts = milliWatt;
        const double mW = milliWatt;
        namespace dose { // energy
            const double Gray = Joule/kilogram;
            const double Grays = Gray;
            const double Gy = Gray;
            const double Sievert = Gray;
            const double Sieverts = Sieverts;
            const double rad = Gray/100.0;
            const double rads = rad;
            const double rd = rad;
        }
        // electrical current
        const double Ampere = 1.0;
        const double Amperes = Ampere;
        const double A = Ampere;
        const double Biot = 10.0*Amperes;
        const double Biots = Biot;
        // electrical potential
        const double Volt = Watt/Ampere;
        const double Volts = Volt;
        const double V = Volt;
        // electrical resistance
        const double Ohm = Volt/Ampere;
        const double Ohms = Ohm;
        // electrical conductance
        const double mho = 1.0/Ohm;
        const double mhos = mho;
        const double Siemens = mho;
        const double S = Siemens;
        // elsectrical charge
        const double Coulomb = Ampere*second;
        const double Coulombs = Coulomb;
        const double C = Coulomb;
        const double Franklin = 3.33564e-10*Coulombs;
        const double Franklins = Franklin;
        // electrical capacity
        const double Farad = Coulomb/Volt;
        const double Farads = Farad;
        const double F = Farad;
        // magnetic flux
        const double Weber = Volt*second;
        const double Webers = Weber;
        const double Wb = Weber;
        const double Maxwell = Weber/100000000.0;
        const double Maxwells = Maxwell;
        const double M = Maxwell;
        // magnetic field B
        const double Tesla = Weber/(meter*meter);
        const double Teslas = Tesla;
        const double T = Tesla;
        const double Gauss = Tesla/10000.0;
        const double gamma = Tesla/1000000000.0;
        // magnetic field H
        const double Oerstedt = 79.57747*Ampere/meter;
        const double Oerstedts = Oerstedt;
        const double Oe = Oerstedt;
        // magnetic inductivity
        const double Henry = Weber/Ampere;
        const double Henrys = Henry;
        const double H = Henry;
        const double milliHenry = Henry/1000.0;
        const double milliHenrys = milliHenry;
        const double mH = milliHenry;
        // temperature
        const double Kelvin = 1.0;
        const double Kelvins = Kelvin;
        const double K = Kelvin;
        // luminous intensity
        const double candela = 1.0;
        const double candelas = candela;
        const double cd = candela;
        const double apostilb = candelas/meter/meter;
        const double apostilbs = apostilb;
        const double nit = apostilb;
        const double nits = nit;
        const double skot = apostilb/1000.0;
        const double skots = skot;
        const double stilb = 10000.0*apostilbs;
        const double stilbs = stilb;
        const double Blondel = apostilb/pi;
        const double Blondels = Blondel;
        const double Lambert = 10000.0*Blondels;
        const double Lamberts = Lambert;
        // light flux
        const double lumen = candela*steradian;
        const double lumens = lumen;
        const double lm = lumen;
        // light intensity
        const double lux = lumens/meter/meter;
        const double luxes = lux;
        const double luces = lux;
        const double lx = lux;
        const double nox = lux/1000.0;
        const double phot = lumens/centimeter/centimeter;
        const double phots = phot;
        namespace equivalent {
            const double lux = unit::lux/pi;
            const double luxes = lux;
            const double luces = lux;
            const double lx = lux;
            const double lumen = unit::lumen/pi;
            const double lumens = lumen;
            const double lm = lumen;
            const double phot = apostilb/pi;
            const double phots = phot;
        }
        // acceleration
        const double Galileo = centimeters/second/second;
        const double Galileos = Galileo;
        // standard gavitational acceleration at sea level
        const double gravity = 9.80665*meters/second/second;
        // mass
        const double kilohyl = kilogram*gravity*second*second/meter;
        const double kilohyls = kilohyl;
        const double hyl = kilohyl/1000.0;
        const double hyls = hyl;

        // English Units
        // length
        const double inch = 0.0254*meters;
        const double inches = inch;
        const double in = inch;
        const double mil = inch/1000.0;
        const double mils = mil;
        const double point = inch/72.27;
        const double points = point;
        const double pt = point;
        const double bottommeasure = inch/40.0;
        const double bottommeasures = bottommeasure;
        const double line = inch/12.0;
        const double lines = line;
        const double pica = 12.0*points;
        const double picas = pica;
        const double barleycorn = inch/3.0;
        const double barleycorns = barleycorn;
        const double finger = 7.0*inches/8.0;
        const double fingers = finger;
        const double palm = 3.0*inches;
        const double palms = palm;
        const double hand = 4.0*inches;
        const double hands = hand;
        const double link = 7.92*inches;
        const double links = link;
        const double li = link;
        const double span = 9.0*inches;
        const double spans = span;
        const double foot = 12.0*inches;
        const double feet = foot;
        const double ft = foot;
        const double cubit = 18.0*inches;
        const double cubits = cubit;
        const double yard = 3.0*feet;
        const double yards = yard;
        const double yd = yard;
        const double nail = yard/16.0;
        const double nails = nail;
        const double ell = 45.0*inches;
        const double ells = ell;
        const double pace = 5.0*feet;
        const double paces = pace;
        const double fathom = 6.0*feet;
        const double fathoms = fathom;
        const double fm = fathom;
        const double rod = 198.0*inches;
        const double rods = rod;
        const double rd = rod;
        const double pole = rod;
        const double poles = pole;
        const double p = pole;
        const double perch = rod;
        const double perches = perch;
        const double rope = 20.0*feet;
        const double ropes = rope;
        const double bolt = 40.0*yards;
        const double bolts = bolt;
        const double chain = 4.0*rods;
        const double chains = chain;
        const double ch = chain;
        namespace Gunters {
            const double chain = unit::chain;
            const double chains = chain;
        }
        namespace engineers {
            const double link = foot;
            const double links = link;
            const double chain = 100.0*feet;
            const double chains = chain;
        }
        const double skein = 120*yards;
        const double skeins = skein;
        const double furlong = 220*yards;
        const double furlongs = furlong;
        const double spindle = 14400*yards;
        const double spindles = spindle;
        namespace US {
            const double cable_length = 120.0*fathoms;
            const double cable_lengths = cable_length;
        }
        namespace British {
            const double cable_length = 100.0*fathoms;
            const double cable_lengths = cable_length;
        }
        namespace statute {
            const double mile = 5280.0*feet;
            const double miles = mile;
            const double mi = mile;
            const double league = 3.0*miles;
            const double leagues = league;
        }
        namespace nautical {
            const double mile = 1852*meters;
            const double miles = mile;
            const double nm = mile;
            const double league = 3.0*miles;
            const double leagues = league;
        }
        namespace marine = nautical;
        namespace geodetic {
            const double foot = (1200.0/3937.0)*meters;
            const double feet = foot;
            const double ft = foot;
        }
        namespace geographical {
            const double mile = nautical::mile;
            const double miles = mile;
            const double mi = mile;
        }
        const double parasang = 3.5*statute::miles;
        const double parasangs = parasang;
        const double arpentcan = 27.52*statute::miles;
        const double arpentcans = arpentcan;
        const double arpentlin = 191.835*feet;
        const double arpentlins = arpentlin;
        const double astronomical_unit = 1.49597871e11*meters;
        const double astronomical_units = astronomical_unit;
        const double AU = astronomical_unit;
        const double lightyear = 9.4605e15*meters;
        const double lightyears = lightyear;
        const double ly = lightyear;
        const double parsec = AU*radians/arc::second;
        const double parsecs = parsec;
        const double pc = parsec;
        // area
        const double barn = 1.0e-28*meter*meter;
        const double barns = barn;
        const double b = barn;
        const double circular_inch = 0.25*pi*inch*inch;
        const double circular_inches = circular_inch;
        const double circular_mil = 0.25*pi*mil*mil;
        const double circular_mils = circular_mil;
        const double sabin = foot*foot;
        const double sabins = sabin;
        const double square = 100.0*sabin;
        const double squares = square;
        const double are = 100.0*meter*meter;
        const double ares = are;
        const double a = are;
        const double rood = 40.0*rod*rod;
        const double roods = rood;
        const double ro = rood;
        const double acre = 4.0*roods;
        const double acres = acre;
        const double section = statute::mile*statute::mile;
        const double sections = section;
        const double homestead = section/4.0;
        const double homesteads = homestead;
        const double township = 36.0*sections;
        const double townships = township;
        // volume
        const double minim = 6.161152e-8*(m*m*m);
        const double minims = minim;
        const double drop = 0.03*cc;
        const double drops = drop;
        const double teaspoon = 4.928922*cc;
        const double teaspoons = teaspoon;
        const double tablespoon = 3.0*teaspoons;
        const double tablespoons = tablespoon;
        namespace US {
            namespace liquid {
                const double dram = 60.0*minims;
                const double drams = dram;
                const double dr = dram;
                const double ounce = 8.0*drams;
                const double ounces = ounce;
                const double oz = ounce;
                const double gill = 4.0*ounces;
                const double gills = gill;
                const double gl = gill;
                const double pint = 4.0*gills;
                const double pints = pint;
                const double pt = pint;
                const double quart = 2.0*pints;
                const double quarts = quart;
                const double qt = quart;
                const double magnum = 2.0*quarts;
                const double magnums = magnum;
                const double gallon = 4.0*quarts;
                const double gallons = gallon;
                const double gal = gallon;
            }
            namespace dry {
                const double pint = 550.61047*cc;
                const double pints = pint;
                const double pt = pint;
                const double quart = 2.0*pints;
                const double quarts = quart;
                const double qt = quart;
            }
            const double peck = 8.0*dry::quarts;
            const double pecks = peck;
            const double pk = peck;
            const double bushel = 4.0*pecks;
            const double bushels = bushel;
            const double bu = bushel;
            const double barrel = 31.5*liquid::gallons;
            const double barrels = barrel;
            const double bbl = barrel;
            const double bl = barrel;
        }
        namespace British {
            namespace fluid {
                const double drachm = 60.0*minims;
                const double drachms = drachm;
                const double dr = drachm;
                const double ounce = 8.0*drachms;
                const double ounces = ounce;
                const double oz = ounce;
                const double gill = 5.0*ounces;
                const double gills = gill;
                const double gi = gill;
                const double pint = 4.0*gills;
                const double pints = pint;
                const double pt = pint;
                const double quart = 2.0*pints;
                const double quarts = quart;
                const double qt = quart;
                const double gallon = 4.0*quarts;
                const double gallons = gallon;
                const double gal = gallon;
            }
            const double peck = 2.0*fluid::gallons;
            const double pecks = peck;
            const double pk = peck;
            const double bushel = 4.0*pecks;
            const double bushels = bushel;
            const double bu = bushel;
            const double barrel = 36.0*fluid::gallons;
            const double barrels = barrel;
            const double bbl = barrel;
            const double bl = barrel;
        }
        const double noggin = 2.0*US::liquid::ounces;
        const double noggins = noggin;
        const double cup = 8.0*US::liquid::ounces;
        const double cups = cup;
        const double fifth = US::liquid::gallon/5.0;
        const double fifths = fifth;
        const double jeroboam = 4.0*fifths;
        const double jeroboams = jeroboam;
        const double firkin = 9.0*US::liquid::gallons;
        const double firkins = firkin;
        const double kilderkin = 18.0*US::liquid::gallons;
        const double kilderkins = kilderkin;
        const double strike = 2.0*US::bushels;
        const double strikes = strike;
        const double sack = 3.0*US::bushels;
        const double sacks = sack;
        const double coomb = 4.0*US::bushels;
        const double coombs = coomb;
        const double seam = 8.0*US::bushels;
        const double seams = seam;
        const double wey = 40.0*US::bushels;
        const double weys = wey;
        const double last = 80.0*US::bushels;
        const double lasts = last;
        const double register_ton = 100.0*(ft*ft*ft);
        const double register_tons = register_ton;
        const double register_tn = register_ton;
        const double cord = 128.0*(ft*ft*ft);
        const double cords = cord;
        const double cordfoot = cord;
        const double cordfeet = cordfoot;
        const double boardfoot = 144.0*inch*inch*inch;
        const double boardfeet = boardfoot;
        const double timberfoot = foot*foot*foot;
        const double timberfeet = timberfoot;
        const double hogshead = 2.0*US::barrels;
        const double hogsheads = hogshead;
        const double pipe = 4.0*US::barrels;
        const double pipes = pipe;
        const double tun = 8.0*US::barrels;
        const double tuns = tun;
        // mass
        const double grain = 0.06479891*grams;
        const double grains = grain;
        const double gr = grain;
        const double pennyweight = 24.0*grains;
        const double dwt = pennyweight;
        namespace apothecary { // weight
            const double scruple = 20.0*grains;
            const double scruples = scruple;
            const double s = scruple;
            const double dram = 3.0*scruples;
            const double drams = dram;
            const double dr = dram;
            const double ounce = 8.0*drams;
            const double ounces = ounce;
            const double oz = ounce;
            const double pound = 12.0*ounces;
            const double pounds = pound;
            const double lb = pound;
        }
        namespace troy = apothecary;
        namespace ap = apothecary;
        namespace t = apothecary;
        namespace avoirdupois { // weight
            const double pound = 7000.0*grains;
            const double pounds = pound;
            const double lb = pound;
            const double ounce = pound/16.0;
            const double ounces = ounce;
            const double oz = ounce;
            const double dram = ounce/16.0;
            const double drams = dram;
            const double dr = dram;
        }
        namespace avdp = avoirdupois;
        namespace av = avoirdupois;
        const double stone = 14.0*avoirdupois::pounds;
        const double stones = stone;
        const double st = stone;
        namespace US { // short
            const double hundredweight = 100.0*avoirdupois::pounds;
            const double cwt = hundredweight;
            const double quarter = hundredweight/4.0;
            const double quarters = quarter;
            const double qr = quarter;
            const double ton = 20.0*hundredweight;
            const double tons = ton;
            const double tn = ton;
            const double deadweight = ton;
        }
        namespace British { // long
            const double hundredweight = 112.0*avoirdupois::pounds;
            const double cwt = hundredweight;
            const double quarter = hundredweight/4.0;
            const double quarters = quarter;
            const double qr = quarter;
            const double ton = 20.0*hundredweight;
            const double tons = ton;
            const double tn = ton;
        }
        namespace English = British;
        namespace Imperial = British;
        const double crith = 0.0906*grams;
        const double criths = crith;
        const double bag = 94.0*avoirdupois::pounds;
        const double bags = bag;
        const double cental = 100.0*avoirdupois::pounds;
        const double centals = cental;
        const double weymass = 252.0*avoirdupois::pounds;
        // rate
        const double mgd = 1000000.0*US::liquid::gallons/day;
        const double cfs = foot*foot*foot/second;
        const double minersinch = 1.5*foot*foot*foot/minute;
        const double mpg = statute::miles/US::liquid::gallon;
        // speed
        const double mph = statute::miles/hour;
        const double knot = nautical::miles/hour;
        const double knots = knot;
        namespace admiralty {
            const double knot = 6980.0*feet/hour;
            const double knots = knot;
        }
        // force
        const double poundal = avdp::pound*foot/(second*second);
        const double poundals = poundal;
        const double pdl = poundal;
        const double lbf = avoirdupois::pound*gravity;
        // pressure
        const double psi = lbf/(inch*inch);
        // energy
        const double calorie = 4.1868*Joules;
        const double calories = calorie;
        const double cal = calorie;
        const double kilocalorie = 1000.0*calories;
        const double kilocalories = kilocalorie;
        const double kcal = kilocalorie;
        const double Frigorie = kilocalorie;
        const double Frigories = Frigorie;
        const double Btu = 1055.06*Joules;
        const double therm = 10000.0*Btu;
        const double therms = therm;
        const double thermie = 1000000.0*calories;
        const double thermies = thermie;
        // power
        const double horsepower = 735.49875*Watts;
        const double HP = horsepower;
        // electrical current
        const double Gilbert = 0.795775*Amperes;
        const double Gilberts = Gilbert;
        // temperature
        const double Rankin = 1.8*Kelvins;
        const double Rankins = Rankin;
        const double R = Rankin;
        // luminous intensity
        const double candle = 1.02*candelas;
        const double candles = candle;
        namespace Hefner {
            const double candle = 0.9*unit::candles;
            const double candles = candle;
        }
        // light intensity
        const double foot_candle = lumens/foot/foot;
        const double foot_candles = foot_candle;
        const double fc = foot_candle;
        const double foot_Lambert = candelas/foot/foot/pi;
        const double foot_Lamberts = foot_Lambert;
        namespace equivalent {
            const double foot_candle = unit::foot_candle/pi;
            const double foot_candles = foot_candle;
            const double fc = foot_candle;
        }
    }
    namespace units = unit;

    namespace constant {
        using namespace units;
        // speed of light
        const double c = 2.99792458e8*meters/second;
        // speed of sound
        const double Mach = 331.46*meters/second;
        // Planck constant
        const double h = 6.6260755e-34*Joule*seconds;
        const double h_bar = h/(2.0*pi);
        // standard gavitational acceleration at sea level
        const double g = units::gravity;
        // electron charge
        const double e = 1.60217733e-19*Coulombs;
        // elevtron Volt
        const double eV = e*V;
        const double keV = 1000.0*eV;
        const double MeV = 1000000.0*eV;
        const double GeV = 1000000000.0*eV;
        const double Rydberg = 13.6054*eV;
        const double Rydbergs = Rydberg;
        // electron mass
        const double m_e = 9.1093897e-31*kilograms;
        // proton mass
        const double m_P = 1.6726231e-27*kilograms;
        // deuteron mass
        const double m_D = 1875.61339*MeV/(c*c);
        // unified atomic mass unit
        const double atomic_mass_unit = 1.6605402e-27*kilograms;
        const double atomic_mass_units = atomic_mass_unit;
        const double amu = atomic_mass_unit;
        const double Dalton = atomic_mass_unit;
        const double Daltons = Dalton;
        // permittivity of free space
        const double epsilon = 8.854187817e-12*Farads/meter;
        // permeability of free space
        const double mu = 12.566370614e-7*Newtons/(A*A);
        // fine-structure constant
        const double alpha = 1.0/137.0359895;
        // classical electron radius
        const double r_e = 2.81794092e-15*meters;
        // electron Compton wavelength
        const double lambda_bar = 3.86159323e-13*meters;
        // Bohr radius
        const double a_0 = 0.529177249e-10*meters;
        // wavelength of 1 eV/c particle
        const double lambda_1eV = 1.23984244e-6*meters;
        // Thomson cross section
        const double sigma_0 = 0.66524616*barns;
        // Bohr magneton
        const double mu_B = 5.78838263e-11*MeV/Tesla;
        // nuclear magneton
        const double mu_N = 3.15245166e-14*MeV/Tesla;
        // electron cyclotron frequency/field
        const double E_M_e = 1.75881962e11*C/kg*(rad/(s*T));
        // proton cyclotron frequency/field
        const double E_M_P = 9.5788309e7*C/kg*(rad/(s*T));
        // gravitational constant
        const double G = 6.67259e-11*m*m*m/(kg*s*s);
        // Avogadro's constant
        const double N_A = 6.0221367e23;
        // Boltzmann constant
        const double K_B = 1.380658e-23*Joules/Kelvin;
        // molar volume, ideal gas at standard temperature and pressure
        const double V_molar = 2.897756e-3*meter*Kelvins;
        // Stefan-Boltzmann constant
        const double sigma_SB = 5.67051e-8*W/(m*m*K*K*K*K);
    }
    namespace constants = constant;


    // enumerators for Physics, ect.
    enum KItem {KNormal, KDistance, KNewton, KGravity, KFriction,
                KCentripetal, KMu, KVelocity, KVelocityFinal, KAcceleration,
                KTime, KTension, Kxi, Kxf,
                KMass
               };

    // direction (Axis) on which this is directed to.
    enum KDirection {Kx, Ky, Kz};

    enum KEnergyType {PotentialGravEnergy, PotentialSpringEnergy, KineticTEnergy, KineticREnergy};

    CharString* getVariableFromKItem(KItem *item);
}


/*
 * Author: Brent clancy (EterniaLogic)
 * Desc: Provides constants and functions for both EE and CE concepts.
 *
 */



namespace chemistry {
    namespace mass {
        const double proton = 1.672621777e-27;
        const double neutron = 1.672621777e-27;
        const double electron = 9.10938188e-31;
    }
}

namespace electrical {
    double getWatts(double volts, double amps);
    double getAmps(double volts, double watts);
    double getVolts(double amps, double watts);
    double getOhms(double volts, double amps);

    double Capacitance(double coulomb, double volt);
    double SeriesSum(double* C, int Clen);
    double ParallelSum(double* C, int Clen);
}

// Advanced electromagnetic frequencies (EterniaLogic)
namespace electromagnetic {
    using namespace physical::unit;
    namespace sound {
        using namespace physical::unit;
        const double octave = 2; // Frequency doubles every octave
        // note: AB = A#/Bb
        const double C = 16.35;
        const double CD = 17.32;
        const double D = 18.35;
        const double DE = 19.45;
        const double E = 20.60;
        const double F = 21.83;
        const double FG = 23.12;
        const double G = 24.50;
        const double GA = 25.96;
        const double A = 27.50;
        const double BA = 29.14;
        const double B = 30.87;

        double getNote(double Letter, double Octave);
    }
    const double radio = 50*megaHertz;//6
    const double microwave = 3*gigaHertz; //9
    const double infared = 300*gigaHertz; //9
    const double light = 400*teraHertz;//12
    const double ultraviolet = 750*petaHertz;//15
    const double xray = 3*exaHertz; //18
    const double gamma = 30*exaHertz; //19
}

namespace PlanetaryConstants {
    enum TerrainTypes {TTOcean, TTGrassland, TTMarsh, TTForest, TTBurning};
}

#endif /*CONSTANTS_H_*/
