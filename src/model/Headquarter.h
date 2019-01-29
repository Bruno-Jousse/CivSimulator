#ifndef Headquarter_HPP
#define Headquarter_HPP

#include "Entity.h"

class Headquarter
{
public:
    Headquarter();
    virtual ~Headquarter();

    // global constant
    static const int STARTING_HP;

protected:
    int hp;
    // the grids TODO
    // the state TODO

private:

};

#endif // Headquarter_HPP