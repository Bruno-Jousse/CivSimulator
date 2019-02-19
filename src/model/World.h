#ifndef World_HPP
#define World_HPP

#include <vector>

#include "Entity.h"
#include "Resource.h"
#include "Headquarter.h"
#include "RandomManager.h"

namespace model{

class World final
{
public:
    World();
    World(const World& w) = delete;
    ~World();

    void simulateOneTurn(unsigned date);

    // Manhattan distance
    int distanceBetween(const Entity& a, const Entity& b);

    bool isNextToResource(const Entity& e);

    // global constants
    static const int NB_ROW;
    static const int NB_COL;
    void init();

protected:

private:
    std::vector<Entity*> entities;

    int nbCivs;
    std::vector<Resource*> resources;
    std::vector<Headquarter*> factions;

};
}
#endif // World_HPP
