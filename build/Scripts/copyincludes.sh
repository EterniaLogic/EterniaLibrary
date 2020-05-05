#!/bin/bash

# cd ../   # isn't needed here

rm include -R
mkdir include
#cp Eternia.h include/
mkdir include/Eternia
cp src/* include/Eternia/ -R

# filter out tests and cpp files
rm $(find include -name "*.cpp") $(find include -name "*.c")
rm $(find include -name "test") -R
