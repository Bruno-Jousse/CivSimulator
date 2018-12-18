#ifndef WORLD_H
#define WORLD_H

#include <random>
#include "Ressource.h"
#include "Headquarter.h"
#include <vector>

using namespace std;

mt19937 generator (123);
uniform_real_distribution<double> distribReal(0.0, 1.0);
uniform_int_distribution<int> distribInt(0, RAND_MAX);
//double randomRealBetweenZeroAndOne = distrib(generator);

class World
{
protected:
    int width;
    int length;
    vector<Ressource> ressources;
    vector<Headquarter> factions;

public:
    World(int nbCivs=0, int width=20, int length=20);
    void simulate();

private:
    void init(int nbCivs);
};

#endif // WORLD_H
