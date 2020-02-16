#!/bin/bash

cd ..

cmake .

while true 
do
	make -j 30
	sleep 10
done
