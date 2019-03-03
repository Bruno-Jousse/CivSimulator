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
    
    void simulate(unsigned date, World& world) override;

    bool isEmpty() { return quantity<=0; }

    int takeRessources(int amount);

protected:
    int quantity;
    int amount;

private:

};
}
#endif // Resource_HPP
