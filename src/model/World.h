#ifndef World_HPP
#define World_HPP

#include <vector>

#include "Entity.h"

namespace model{

class World final
{
public:
    World();
    World(const World& w) = delete;
    ~World();

    void simulateOneTurn(unsigned date);

    // global constants
    static const int NB_ROW;
    static const int NB_COL;
    void init();

protected:

private:
    std::vector<Entity*> entities;

};
}
#endif // World_HPP
