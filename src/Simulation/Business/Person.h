#ifndef PERSON_H_
#define PERSON_H_

#include "../../Data/includes.h"
#include "ALocation.h"

// Personal information for an employee or shareholder
class Person{
public:
    CharString first_name;
    CharString middle_name;
    CharString last_name;
    CharString DOB;
    ALocation address;
    
    
private:
    // Sensitive information (EterniaLib not liable if data is sniffed)
    CharString SSN;
    CharString CreditCard_Type; // MasterCard / Visa, etc.
    CharString CreditCard; // CCN\nDATE\nNAME\nSECCODE (\n is newline)
};

#endif
