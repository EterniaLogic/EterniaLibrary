#!/bin/bash
# make a include directory
rm include -R
mkdir include
mkdir include/Eternia
cp src/* include/Eternia/ -R

# filter out tests and cpp files
rm $(find include/Eternia -name "*.cpp") $(find include -name "*.c") > /dev/null
rm $(find include/Eternia -name "test") -R > /dev/null
