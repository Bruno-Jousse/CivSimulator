#ifndef WORLD_H
#define WORLD_H

#include <random>

class World
{
protected:
    int width;
    int length;
    vector<Ressource> ressources;
    vector<Headquater> civilisations;

public:
    World();
    World(int nbCivs=0, int width=20, int length=20);

private:
    void init(int nbCivs);
};

#endif // WORLD_H
