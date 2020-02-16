#ifndef ACCOUNTING_H_
#define ACCOUNTING_H_

#ifndef COMPANY_H_
#include "../../Company.h"
#else
class Company;
#endif

// perform standard acconting operations

class Accounting{
public:
    Company *company;
    
    
    // tax settings for country
    double income_tax;
    
    
    
    // Liquidated Totals
    double getNetTotal(); // 
    double getGrandTotal(); // Grand total from everything. Assets, equity, payroll, taxes, etc.
    double getAssetTotal(); // Total of Liabilities + Owner's Equity
    
    // Taxes
    double getPrepaidIncomeTax(); // income tax that is prepaid for employees in payroll
    
    
    // Standard income/outgoing
    double getNetIncome();
    double getTotalExpenses();
    double getTotalYearlyWages(); // get estimated salaries of all employees
    
    
    // Liabilities
    double getLiabilities(); // count up all the debt in liabilities.
    double getDebt(); // Get all debt that was borrowed through loans, bonds or mortgages.
    
    
    // Equities & Assets
    double getEquity(); // liquid assets + stock + reserve + prepaid expenses + reserve + surplus + share capital
    double getShareholderEquity(); // Beginning of year EQ + net income - dividends +/- gain/loss from shares outstanding => end of year equity
    double getCurrentAssets(); // Liquid + Stocks + Prepaid expenses
    double getLiquidAssets(); // (Absolute liquid + Bills receivable)
    double getAbsoluteLiquidAssets(); // Cash in hand + cash in bank + accrued incomes + loans and advances + trade investments
    
    // Taxation
    double getTax(); // get estimated tax from all recent transactions
};

#endif
