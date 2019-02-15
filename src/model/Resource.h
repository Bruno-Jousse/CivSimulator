#ifndef Resource_HPP
#define Resource_HPP

#include "Entity.h"

namespace model{

class Resource: public Entity
{
public:
    Resource() = delete;
    Resource(Resource const&) = delete;

    Resource(int x, int y, int quantity);
    virtual ~Resource();
    // simulate = 0;

    bool isEmpty() { return quantity<=0; }

    int takeRessources(int amount);

protected:
    int quantity;
    int amount;

private:

};
}
#endif // Resource_HPP
