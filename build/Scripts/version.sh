#/bin/bash

# takes in version.txt, increments it, then outputs new to both 

export v=$(cat ./version.txt | awk -F. -v OFS=. 'NF==1{print ++$NF}; NF>1{if(length($NF+1)>length($NF))$(NF-1)++; $NF=sprintf("%0*d", length($NF), ($NF+1)%(10^length($NF))); print}')
echo $v > version.txt

echo version $v

echo "#ifndef VER_H" > src/version.h
echo "#define VER_H" >> src/version.h
echo "#define FULLVERSION_STRING \"$v\"" >> src/version.h
echo "#endif" >> src/version.h
