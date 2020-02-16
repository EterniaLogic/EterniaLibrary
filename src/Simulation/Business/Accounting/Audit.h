#ifndef AUDIT_H_
#define AUDIT_H_
#include "../../Data/includes.h"
#include "../Employee.h"

// FROM wikipedia
// An audit is a systematic and independent examination of books, accounts, 
//  statutory records, documents and vouchers of an organization to ascertain 
//  how far the financial statements as well as non-financial disclosures present 
//  a true and fair view of the concern. It also attempts to ensure that the books 
//  of accounts are properly maintained by the concern as required by law.


// This is mostly used just for simulation, as auditing software is probably much better.

enum AUDIT_TYPE {PERFORMANCE_AUDIT, QUALITY_AUDIT, ENERGY_AUDIT, FORENSIC_AUDIT, OPERATIONS_AUDIT, PROJECT_AUDIT};
enum ASSESSMENT_METHOD {AM_ANY, AM_ONSITE, AM_REMOTE};

class Audit{
public:
    AUDIT_TYPE type;
    ASSESSMENT_METHOD method;
    CharString auditor_name; // external auditor
    Employee* auditor; // internal auditor
    
    CharString result; // single-word result for audit satisfactory, suggestions, problems, criminal, etc.
    CharString report; // plain-text report from the audit.
};

#endif
