#ifndef World_HPP
#define World_HPP

#include <vector>

#include "Entity.h"
#include "Resource.h"
#include "Headquarter.h"
#include "RandomManager.h"
#include "../view/FactoryViewItem.h"

namespace model{

class World final
{
public:
    World(int nbCiv, int length, int width);
    World(const World& w) = delete;
    ~World();

    void simulateOneTurn(unsigned date);

    // Manhattan distance
    int distanceBetween(const Entity& a, const Entity& b);

    bool isNextToResource(const Entity& e);

    std::vector<Agent*> getAgentOf(Headquarter* hq);
    int distanceMin(Entity* e, std::vector<Agent*>& vect);
    std::vector<Agent*> getEnemiesVisibleBy(Headquarter* hq);
    std::vector<Headquarter*> getHeadquartersVisibleBy(Headquarter* hq);
    std::vector<Resource*> getResourcesVisibleBy(Headquarter* hq);
    std::vector<Agent*> getAgentsTargetableBy(const Soldier& soldier);

    // global constants
    static const int NB_ROW;
    static const int NB_COL;
    static const int VISIBILITY_RANGE;

    void init();
    void action(int phase);
    int getWidth(){ return NB_COL*30; }
    int getHeight(){ return NB_ROW*30;}

protected:

private:
    std::vector<Agent*> agents;
    std::vector<Headquarter*> headquarters;

    int nbCivs;
    std::vector<Resource*> resources;
    std::vector<Headquarter*> factions;

};
}
#endif // World_HPP
