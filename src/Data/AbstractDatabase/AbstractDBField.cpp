#include "AbstractDB.h"

AbstractDBField::AbstractDBField(ADBF_TYPE type){
	init(type, true);
}

AbstractDBField::AbstractDBField(ADBF_TYPE type, bool isKey = false){
	init(type, isKey);
}

AbstractDBField::~AbstractDBField(){
	
}

void AbstractDBField::init(ADBF_TYPE type, bool isKey){
	fieldtype = type;
	iskey = isKey;
}

int AbstractDBField::getSize(){
	switch (fieldtype){
	case DB_CHAR:
		return DB_CHAR_SIZE;
		break;
	case DB_INT:
		return DB_INT_SIZE;
		break;
	case DB_LONG:
		return DB_LONG_SIZE;
		break;
	case DB_STRING:
		return DB_STRING_SIZE;
		break;
	case DB_DATE:
		return DB_DATE_SIZE;
		break;
	case DB_REAL:
		return DB_REAL_SIZE;
		break;
	case DB_FLOAT:
		return DB_FLOAT_SIZE;
		break;
	case DB_DOUBLE:
		return DB_DOUBLE_SIZE;
		break;
	}
}

bool AbstractDBField::getIsKey(){
	return iskey;
}

ADBF_TYPE AbstractDBField::getType(){
	return fieldtype;
}