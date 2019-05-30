#ifndef CSV_FILE_H_
#define CSV_FILE_H_

#include "../CharString.h"
#include "../LinkedList.hpp"
#include <stdlib.h>
#include <fstream>
#include "../../Parsing/SimpleParser.h"
// https://tools.ietf.org/html/rfc4180  for 'official' CSV file format


// outputs table that does not follow width/height.
// List of Rows.
LinkedList<LinkedList<CharString>> getTableFromCSV(CharString csvFile);
void toCSVFromTable(CharString csvFile, LinkedList<LinkedList<CharString>> tablerows);

#endif
