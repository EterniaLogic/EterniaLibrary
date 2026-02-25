#ifndef PERSON_H_
#define PERSON_H_

#include "../../Data/includes.h"
#include "ALocation.h"

// Personal information for an employee or shareholder
class Person{
private:

public:
    CharString first_name;
    CharString middle_name;
    CharString last_name;
    CharString DOB;
    ALocation address;

};

#endif
