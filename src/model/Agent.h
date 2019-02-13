#ifndef Agent_HPP
#define Agent_HPP

#include "Entity.h"
#include "Headquarter.h"

namespace model{


class Agent: public Entity
{
public:
    Agent() = delete;
    Agent(Agent const&) = delete;
    
    Agent(int x, int y, unsigned deathDate, int hp, Headquarter* creator);
    virtual ~Agent();

    // virtual void simulate(unsigned date) = 0;

    virtual bool isDead(unsigned date);

    //Method called every times the QGraphicsScene decide to advance by a frame
    void advance(int phase);
    //Our method called every frames to interact
    virtual void action() =0;

protected:
    unsigned deathDate;
    int hp; // number of shot until it dies
    Headquarter* hq;

private:

};

}
#endif // Agent_HPP
