#ifndef Headquarter_HPP
#define Headquarter_HPP

#include "Entity.h"

class Headquarter final: public Entity
{
public:
    Headquarter() = delete;
    Headquarter(Headquarter const&) = delete;
    
    Headquarter(int x, int y);
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