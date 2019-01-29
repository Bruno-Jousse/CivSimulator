#ifndef Resource_HPP
#define Resource_HPP

#include "Entity.h"

class Resource: public Entity
{
public:
    Resource() = delete;
    Resource(Resource const&) = delete;

    Resource(int x, int y, int quantity);
    virtual ~Resource();
    // simulate = 0;

    bool isEmpty() { return quantity<=0; }

protected:
    int quantity;
private:

};

#endif // Resource_HPP