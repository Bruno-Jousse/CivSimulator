#ifndef Resource_HPP
#define Resource_HPP

#include "Entity.h"

class Resource: public Entity
{
public:
    Resource(int quantity);
    virtual ~Resource();

protected:
    int quantity;
private:

};

#endif // Resource_HPP