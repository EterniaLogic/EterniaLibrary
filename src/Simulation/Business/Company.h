#ifndef COMPANY_H_
#define COMPANY_H_
#include "../../Data/includes.h"

class Company;

#include "MarginHolder.h"
#include "Employee.h"
#include "Lawyer.h"
#include "Accounting/Liability.h"
#include "Accounting/Equity.h"

enum CompanyType {CT_Defunct, CT_Sole, CT_LLC, CT_Corporation, CT_Joint, CT_Nonprofit, CT_Partnership, CT_Cooperative,
                CT_Shell};

class Company : public MarginHolder{
public:
    // inherits assets, accounts, transactions, name from AssetHolder
    LinkedList<Employee> employees; // full list of employees
    
    // separated lists for employees
    LinkedList<Employee> janitors;
    LinkedList<Employee> managers;
    LinkedList<Employee> accountants;
    LinkedList<Employee> human_resources;
    LinkedList<Employee> loose; // employees that service computers or networks between buildings or act as a consultant
    LinkedList<Employee> consultant; // external-hired consultor for a project or auditing
    LinkedList<Employee> board; // board of directors
    Employee CEO;
    
    LinkedList<Lawyer> lawyers; // lawyers and related transactions for law-related consultations.
    
    
    // standard parameters
    CompanyType companytype; // LLC, Corporation, etc.
    
    // Material
    
    // Shares
    long totalShares; // total Stock Shares
    LinkedList<AssetHolder> stock_owners;
    
    
    // Assets and liabilities are defined in MarginHolder
    
    Company(){
        classname="[Company]";
    }
};


#else
class Company;
#endif
