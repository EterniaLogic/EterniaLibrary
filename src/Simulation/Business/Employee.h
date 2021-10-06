#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_


#include "AssetHolder.h"
#include "Payroll/HourRate.h"



enum POSITION_ROLE {PR_FIRED, PR_UNKNOWN, PR_ACCOUNTING, PR_HR, PR_STAFF, PR_JANITOR, PT_PROGRAMMER, PR_IT, PR_MANAGER, PR_CUSTOMER_SERVICE, PR_REMOTE, PR_CEO, PR_BOARD};
enum PAYROLL_TYPE {PAY_UNKNOWN, PAY_HOURLY, PAY_PARTTIME, PAY_FULLTIME};

class Employee : public AssetHolder{
public:
    Employee(){
        classname="[Employee]";
    }
    
    AssetHolder *employer;
    CharString position_name;
    POSITION_ROLE role;
    PAYROLL_TYPE payrolltype;
    Employee *manager; // boss / handler
    // inherits 'Person* identity' from AssetHolder
    
    CharString hashed_password; // hashed form of an employee's password to use this backend.
    
    // Hours during current time period
    LinkedList<HourRate> phours;
    double minimum_hours; // minimum hours / week for hourly
    
    double salary; // yearly salary
    double wage_total; // total wage paid to employee for work over the years
    CharString hire_date; // date originally hired
    CharString fire_date; // date fired
};

#endif
