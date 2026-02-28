#!/bin/bash

# cd ../   # isn't needed here

rm build/include -R
mkdir build/include
#cp Eternia.h build/include/
mkdir build/include/Eternia
cp src/* build/include/Eternia/ -R

# filter out tests and cpp files
rm $(find build/include -name "*.cpp") $(find build/include -name "*.c")
rm $(find build/include -name "test") -R
