#ifndef COMPANY_H_
#define COMPANY_H_
#include "../../Data/includes.h"

class Company;

#include "AssetHolder.h"
#include "Employee.h"
#include "Lawyer.h"
#include "Accounting/Liability.h"
#include "Accounting/Equity.h"



class Company : public AssetHolder{
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
    
    
    // Shares
    int totalShares; // total Stock Shares
    LinkedList<AssetHolder> stock_owners;
    
    
    // Standard lists for accounting
    LinkedList<Liability> liabilities; // Debts, obligations, issued payments, etc.
    LinkedList<Equity> equities; // owned equities (Capital, surplus, stock, earnings, reserve, assets, cash)
};


#else
class Company;
#endif
