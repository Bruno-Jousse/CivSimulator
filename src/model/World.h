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

    // global constants
    static const int NB_ROW;
    static const int NB_COL;
    void init();
    void action(int phase) override;

protected:

private:
    std::vector<Entity*> entities;

    int nbCivs;
    int width;
    int height;
    std::vector<Resource*> ressources;
    std::vector<Headquarter*> factions;

};
}
#endif // World_HPP
