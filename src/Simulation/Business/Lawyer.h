#ifndef LAWYER_H_
#define LAWYER_H_

#include "../../Data/includes.h"

#include "Employee.h"
#include "Report/Case.h"

class Lawyer : public Employee{
public:
    LinkedList<Case> cases;
};

#endif
