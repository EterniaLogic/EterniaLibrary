#ifndef CASE_H_
#define CASE_H_

#include "../../Data/includes.h"

// Lawyer or Audit case
class Case{
public:
    CharString name;
    CharString description;
    CharString result;
    
    double litigation_value; // value of litigations if perused (Like $10,000 for injury or sued)
    double spent; // total value of litigation + laywer + audit costs after case was closed
};

#endif
