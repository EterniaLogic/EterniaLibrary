#include "AbstractDB.h"


AbstractDBCacheMap::AbstractDBCacheMap(ADB_STOREBASE Base, ADBT_SECURITY Security){
	base = Base;
	security = Security;

	// init Wide Range Cache Map
	switch (base){
	case ADB_BASE_2:
		mapArray = (void**)calloc(32,sizeof(void*));
		break;
	case ADB_BASE_2_EXTENDED:
		mapArray = (void**)calloc(2*32, sizeof(void*));
		break;
	case ADB_BASE_2_WIDE:
		mapArray = (void**)calloc(2 * 32 * 32, sizeof(void*));
		break;
	case ADB_BASE_3:
		mapArray = (void**)calloc(32, sizeof(void*));
		break;
	case ADB_BASE_3_EXTENDED:
		mapArray = (void**)calloc(3*32, sizeof(void*));
		break;
	case ADB_BASE_3_WIDE:
		mapArray = (void**)calloc(3 * 32 * 32, sizeof(void*));
		break;
	case ADB_BASE_5:
		mapArray = (void**)calloc(32, sizeof(void*));
		break;
	case ADB_BASE_5_EXTENDED:
		mapArray = (void**)calloc(5*32, sizeof(void*));
		break;
	case ADB_BASE_5_WIDE:
		mapArray = (void**)calloc(5 * 32 * 32, sizeof(void*));
		break;
	case ADB_BASE_7:
		mapArray = (void**)calloc(32, sizeof(void*));
		break;
	case ADB_BASE_7_EXTENDED:
		mapArray = (void**)calloc(7*32, sizeof(void*));
		break;
	case ADB_BASE_7_WIDE:
		mapArray = (void**)calloc(7 * 32 * 32, sizeof(void*));
		break;
	case ADB_BASE_MAXV_1000:
		mapArray = (void**)calloc(1000, sizeof(void*));
		break;
	case ADB_BASE_MAXV_10000:
		mapArray = (void**)calloc(10000, sizeof(void*));
		break;
	case ADB_BASE_MAXV_100000:
		mapArray = (void**)calloc(100000, sizeof(void*));
		break;
	case ADB_BASE_MAXV_1000000:
		mapArray = (void**)calloc(1000000, sizeof(void*));
		break;
	case ADB_BASE_MAXV_10000000:
		mapArray = (void**)calloc(10000000, sizeof(void*));
		break;
	case ADB_BASE_MAXV_100000000:
		mapArray = (void**)calloc(100000000, sizeof(void*));
		break;
	}

	rowList = new AbstractDBLinkedDataset();
}

AbstractDBCacheMap::~AbstractDBCacheMap(){
	clearCache();
}

void AbstractDBCacheMap::clearCache(){
	bool base_constant = (base == ADB_BASE_MAXV_1000 || base == ADB_BASE_MAXV_10000 || base == ADB_BASE_MAXV_100000 || base == ADB_BASE_MAXV_1000000 || base == ADB_BASE_MAXV_10000000 || base == ADB_BASE_MAXV_100000000);
	AbstractDBCacheMap* submap;
	AbstractDBPriorityQueue* subheap;

	// loop through rows
	for (int i = 0; i < rowList->getSize(); i++){
		AbstractDBRow* row = (AbstractDBRow*)rowList->frozen_get(i);
		row->clearRow();
		if (mapArray[row->mapindex] != NULL){
			if (base_constant){
				mapArray[row->mapindex] == NULL;
			}
			else{
				// Priority queue more efficient for smaller regions
				if (row->mapindex < 8){
					subheap = (AbstractDBPriorityQueue*)mapArray[row->mapindex];
					subheap->clearQueue();
				}else{
					submap = (AbstractDBCacheMap*)mapArray[row->mapindex];
					submap->clearCache();
				}
			}
		}
		delete(row);
	}

	
}

int AbstractDBCacheMap::getKey(double index){
	if (index == 0) return 0;
	double b = 0;

	switch (base){
	case ADB_BASE_2:
		return (int)log2(index);
		break;
	case ADB_BASE_2_EXTENDED: // base 4 achieves 2*32 extension
		return (int)(log(index) / log(4));
		break;
	case ADB_BASE_2_WIDE: // base 2^(1/64) achieves 2*32*32 extension
		b = pow(2.0, 1.0/64.0);
		return (int)(log(index) / log(b));
		break;
	case ADB_BASE_3:
		return (int)(log(index) / log(3));
		break;
	case ADB_BASE_3_EXTENDED: // base 9 achieves 3*32 extension
		return (int)(log(index) / log(9));
		break;
	case ADB_BASE_3_WIDE: // base 3^(1/96) achieves 3*32*32 extension
		b = pow(3.0, 1.0/96.0);
		return (int)(log(index) / log(b));
		break; 
	case ADB_BASE_5:
		return (int)(log(index) / log(5));
		break;
	case ADB_BASE_5_EXTENDED: // base 25 achieves 5*32 extension
		return (int)(log(index) / log(25));
		break;
	case ADB_BASE_5_WIDE: // base 5^(1/160) achieves 5*32*32 extension
		b = pow(5.0, 1.0/160.0);
		return (int)(log(index) / log(b));
		break;
	case ADB_BASE_7:
		return (int)(log(index) / log(7));
		break;
	case ADB_BASE_7_EXTENDED: // base 49 achieves 7*32 extension
		return (int)(log(index) / log(49));
		break;
	case ADB_BASE_7_WIDE: // base 7^(1/160) achieves 7*32*32 extension
		b = pow(7.0, 1.0/224.0);
		return (int)(log(index) / log(b));
		break;
	case ADB_BASE_MAXV_1000: // raw indexers
		return index;
		break;
	case ADB_BASE_MAXV_10000: // raw indexers
		return index;
		break;
	case ADB_BASE_MAXV_100000: // raw indexers
		return index;
		break;
	case ADB_BASE_MAXV_1000000: // raw indexers
		return index;
		break;
	case ADB_BASE_MAXV_10000000: // raw indexers
		return index;
		break;
	case ADB_BASE_MAXV_100000000: // raw indexers
		return index;
		break;
	}
}

AbstractDBRow* AbstractDBCacheMap::getRow(double index){
	return (AbstractDBRow*)rowList->frozen_get(index);
}

AbstractDBLinkedDataset* AbstractDBCacheMap::getAllRows(){
	return rowList;
}