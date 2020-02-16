#ifndef OILDISTILLERY_H_
#define OILDISTILLERY_H_


#include "Workshop.h"
class OilDistillery : public Workshop{
public:
    OilDistillery(){
        classname="OilDistillery";

        // Approximate average listing of crude oil fractioning products (1L becomes 1.065L due to some gasses being distilled out)
        recipes.add(WorkshopRecipe("1L Crude Oil","465ml Gasoline 370C, 290ml Diesel 300C, 90ml Jet Fuel 200C, 53ml Petroleum Coke 400C, 40ml Still Gas 85C, 36ml HGL 85C, 25ml Residual Fuel Oil 250C, 19ml Liquid Asphalt 400C, 10ml Feedstock Napthas 177C, 10ml Lubricant 400C, 7ml Feedstock Oils, 6ml Miscellaneous Petroleum Products, 2ml Special Napthas, 0.95ml Aviation Gasoline 170C, 0.24ml Kerosene 250C, 0.24ml Parrafin Wax 99C", 2400)); // Generic Distillery function
    }
};

#endif
