#include "AbstractDB.h"

AbstractDBRow::AbstractDBRow(){
	mapindex = 0;
}

void AbstractDBRow::addField(AbstractDBField* field){
	fieldList->push_back(field);
}

void AbstractDBRow::clearRow(){
	// loop through and remove fields then dispose of values
	fieldList->clearAll();
	valueList->clearAll();
}