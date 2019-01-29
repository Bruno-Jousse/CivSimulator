#ifndef Agent_HPP
#define Agent_HPP

#include "Entity.h"
#include "Headquarter.h"

class Agent: public Entity
{
public:
    Agent(int x, int y, unsigned deathDate, int hp, Headquarter* creator);
    virtual ~Agent();

    // virtual void simulate(unsigned date) = 0;

    virtual bool isDead(unsigned date);

protected:
    unsigned deathDate;
    int hp; // number of shot until it dies
    Headquarter* hq;

private:

};

#endif // Agent_HPP