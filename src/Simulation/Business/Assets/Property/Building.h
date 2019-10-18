#ifndef BUILDING_H_
#define BUILDING_H_

#include "../../../Data/includes.h"
#include "../../ALocation.h"
#include "../../AssetHolder.h"
#include "Land.h"
#include "../Item.h"

// 
class Building : public Land{
public:
    // inherits location, dimensions from Land
   LinkedList<Employee> location_employees; // employees on site
   LinkedList<Item> equipment; // equipment that can be serial IDed. (not for sale)
   LinkedList<Item> inventory; // inventory of items for sale or storage.
   
   vertex building_dimensions; // total dimensions of building itself. XY horizontal, Z - height in meters
   
   // total capacity by floorplans
   int floors;
   int rooms;
   int office_rooms; // large open areas with cublicles only count as 1.
   int janitorial_rooms;
   int bathrooms;
   double inventory_space; // estimated space in meters cubed.
   
   double land; // landscape space in meters^2 (Or sq. feet in US)
   double floorspace; // floorspace in meters^2
};

#endif
