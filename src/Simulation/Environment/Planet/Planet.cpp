#include "Planet.h"

Planet::Planet(long long seedx, long long seed2x, double luminosity) {
    seed=seedx;
    seed2=seed2x;
    
    name=""; // NameGen.randomPhoneticName(seed)
    
    // init base variables
    haswater=hasoxygen=hasice=false;
    
    // abusing pseudo-random number generators!
    r = Math::Random(seedx);
    
    radius = r.nextDouble()*100000.0*km; // meters (0 to 100,000km in radius)
    
    // randomized conditionals for a newer radius
    if(r.nextInt(0,3)==1) radius = (radius > uranusmass) ? r.nextDouble()*15000.*km : radius; // giants
	if(r.nextInt(0,3)==1) radius = r.nextDouble()*1189.*km; // dwarfs
    
    // too small, reroll until it is works
	while(radius < 500.*km) radius = r.nextDouble()*100000*km;
	
	// Set other parameters relative to earth
	volume = (4./3.)*Math::PI*Math::pow(radius, 3.); // m3
	density = 3000.+r.nextDouble()*5000.; // kg/m3
	mass = volume * density; // kg
	daylen = r.nextDouble()*3.; // how fast is the planet spinning relevant to earth
		
    
    double surfacearea = 4.*Math::PI*Math::pow(radius, 2.)/2.; // (4*Pi*R)/2
	//solarIrradiance = luminosity/surfacearea; // W/m^2 (9000 is mercury, 1361 is earth)
	solarIrradiance = luminosity;
	waterheight = r.nextDouble(); // only used on planets with atmosphere
    
    
    // earth has a magnetosphere of 0.03 mT, prevents solar winds from removing the atmosphere
	magnetosphere = r.nextDouble()*0.06;
    
    classifyPlanet(); // determine initial planet type
    
    
    if(type == PlType::Gas && size == PlSize::Giant) {
		magnetosphere = (mass/jupitermass)*0.42; // mT (millitesla)
		atmosphere = (mass/jupitermass)*20;
		daylen = 0.01;
	}
	
	// add moons
	int nmoons = 2;
	if(size == PlSize::Giant) nmoons = r.nextInt(20);			
	else if(size == PlSize::Super) nmoons = r.nextInt(4);
	else if(size == PlSize::Normal) nmoons = r.nextInt(2);
	else if(size == PlSize::Dwarf) nmoons = 0;
	/*for(int i=0;i<nmoons;i++) {
		Moon m = new Moon(r.nextLong());
		m.location.systemobject = this;
		m.location.system = this.location.system;
		moons.add(m);
	}*/
	
    
    
    terrain = Terrain(seed,seed2);
    //atmosphere = Atmosphere(seed,seed2);
}

Planet::~Planet() {
}



void Planet::classifyPlanet(){
    // categorize by mass first.
	size = PlSize::Normal;
	if(mass >= uranusmass) {
		type = PlType::Gas;
		size = PlSize::Giant;
		return;
	}
	
	type = PlType::Barren;
	
	if(mass > earthmass*1.25 && mass < earthmass*2) size = PlSize::Super;
	if(mass < earthmass) size = PlSize::Normal;
	if(mass < plutomass) size = PlSize::Dwarf;
	
	// categorize planet type, includes estimations of magnetosphere, daylen and luminosity
	double theoreticalatmosphere = magnetosphere/0.03; // parts compared to earth (mars is 2%, but has nil magnetosphere)
	if(solarIrradiance < 1310) theoreticalatmosphere *= solarIrradiance/1361;
	else if(solarIrradiance > 1310) theoreticalatmosphere *= 1361/solarIrradiance;
	
	atmosphere = r.nextDouble()*theoreticalatmosphere;
	if(atmosphere > 0.1) hasoxygen = r.nextBoolean();
	if(hasoxygen) hasice = true;
	if(hasice && solarIrradiance > 600) haswater = true;
	
	// determine specific type between lava, ice, ocean or normal/superearth
	if(!hasice) {
		if(magnetosphere > 0.04 && (size == PlSize::Normal || size == PlSize::Super))
			type = PlType::Lava;
		else if(solarIrradiance < 100) { type = PlType::Ice; hasice=true; }
	}else if(haswater && hasoxygen) {
		if(waterheight > 0.8) type = PlType::Ocean;
		else type = PlType::Earth;
	}
}



bool Planet::canTerraform() {
	if(solarIrradiance < 1600 && solarIrradiance > 800)
		if(magnetosphere >= 0.01)
			if(size == PlSize::Normal || size == PlSize::Super)
				return true;
	
	return false;
}

bool Planet::canLive() {
	if(!canTerraform()) return false;
	
	if(atmosphere < 0.2) return false;
	if(getSurfaceGravity() > 14) return false;
	if(!(haswater || hasice) || !hasoxygen) return false;
	
	return true;
}

/*double Planet::getKmPerPixel(GenericMap map) {
	return getCircumference()/(map.getWidth()*1000);
}


public int[] Planet::convertLatLonToMeters(PointD latlong, GenericMap map) {
	int[] xy = new int[2];
	
	xy[0] = (int) (latlong.x*(double)map.getWidth()*this.getKmPerPixel(map));
	xy[1] = (int) (latlong.y*(double)map.getHeight()*this.getKmPerPixel(map));
	
	return xy;
}

public int[] Planet::convertLatLonToCartesian(PointD latlong, GenericMap map) {
	int[] xy = new int[2];
	
	xy[0] = (int) (latlong.x*(double)map.getWidth());
	xy[1] = (int) (latlong.y*(double)map.getHeight());
	
	return xy;
}

public PointD Planet::convertMetersToLanLon(double x, double y, GenericMap map) {
	PointD point = new PointD();
	
	point.x = x/((double)map.getWidth()*this.getKmPerPixel(map));
	point.y = y/((double)map.getHeight()*this.getKmPerPixel(map));
	
	return point;
}

public PointD Planet::convertCartesianToLanLon(double x, double y, GenericMap map) {
	PointD point = new PointD();
	
	point.x = x/((double)map.getWidth());
	point.y = y/((double)map.getHeight());
	
	return point;
}*/


// get the global Gross Domestic Product
/*public double Planet::getGlobalGDP() {
	// loop through countries
	double gdp = 0;
	
	for(Country c : countries) {
		gdp += c.getGDP();
	}
	
	for(Company c : internationalCompanies) {
		gdp += c.total;
	}
	
	return gdp;
}*/
