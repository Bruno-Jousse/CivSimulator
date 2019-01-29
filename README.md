# CivSimulator

In a distant future, Skynet eradicated the human specie.
John Connor and the other rebels failed their mission.
The world is now dominated by the machines.
However, Skynet has trouble maintaining his authority and
dissolved in factions autonomous and independent. This factions
are leaded by artificial intelligences less evolved than Skynet,
but they have their own free will. They are fighting merciless
against each other for the domination of the world. 

## Build notes

While not fixed, in order to compile the project you must use the building fonction of QT Creator, there will be an error. Then you must compute in the terminal under the directory build-CivSimulation-Desktop-Debug the following command line:
g++  -o CivSimulation main.o World.o  Agent.o Building.o  Figure.o  Headquarter.o  Machine.o  Metal.o  Ressource.o  Soldier.o  Worker.o qrc_images.o   -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread

Now, use cmake
```sh
$ cmake -G "Unix Makefiles"
$ cmake --build .
```
