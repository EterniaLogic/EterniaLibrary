#include "testAbstractDB.h"


void testAbstractDB(){
    AbstractDBTable* table = new AbstractDBTable("test.dat", ADB_BASE_2_WIDE, ADBT_NONE);
	AbstractDBField* f1_key = new AbstractDBField(DB_INT, true);
	AbstractDBField* f2_name = new AbstractDBField(DB_STRING);
	table->addField(f1_key);
	table->addField(f2_name);
}
