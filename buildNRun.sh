#!/bin/bash

nbCivs=2
long=1000
larg=1000
buildPath="build-CivSimulation-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug"

if [ $# -eq 3 ] 
   	then
	nbCivs=$1
    	long=$2
	larg=$3
fi

g++  -o CivSimulation $buildPath/main.o $buildPath/World.o  $buildPath/Agent.o $buildPath/Building.o  $buildPath/Figure.o  $buildPath/Headquarter.o  $buildPath/Machine.o  $buildPath/Metal.o  $buildPath/Ressource.o  $buildPath/Soldier.o  $buildPath/Worker.o $buildPath/qrc_images.o   -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread -g
$buildPath/CivSimulation $nbCivs $long $larg
