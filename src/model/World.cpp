#include "World.h"

#include <algorithm>

using namespace std;

const int World::NB_ROW = 20;
const int World::NB_COL = 20;

World::World(): entities()
{
    // TODO : (Bruno) paste your code of random initialisation here
}

World::~World()
{}

void World::simulateOneTurn(unsigned date)
{
    // TODO : construct a grid (2D array) of the unit to have acces to them quicker
    random_shuffle(entities.begin(), entities.end()); // TODO : if we still use the PRNG from std use it as third argument
    for(auto & entity: entities)
    {
        entity->simulate(date);
    }
    // TODO : if there is new entities add them here and remove the dead ones
}