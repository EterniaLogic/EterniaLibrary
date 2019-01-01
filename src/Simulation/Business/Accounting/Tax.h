#ifndef TAX_H_
#define TAX_H_

// Taxes are a percentage given to the government.

enum TAX_TYPE {SALES_TAX, INCOME_TAX, TARIFF_TAX, PROPERTY_TAX, SOCIALSEC_TAX, PAYROLL_TAX, TRANSFER_TAX};
enum TAX_LEVEL {TL_GOVERNMENT, TL_STATE, TL_CITY}

class Tax{
public:
    TAX_TYPE type;
    double tax; // tax multiplier
};

#endif
