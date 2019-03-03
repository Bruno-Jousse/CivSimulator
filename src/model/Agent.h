#ifndef Agent_HPP
#define Agent_HPP

#include "Entity.h"
#include "Headquarter.h"
#include "Grid.h"

namespace model{


class Agent: public Entity
{
public:
    Agent() = delete;
    Agent(Agent const&) = delete;
    
    Agent(int x, int y, unsigned deathDate, int hp, Headquarter* creator);
    virtual ~Agent();

    virtual bool isDead(unsigned date);
    bool doesBelongTo(Headquarter* headquarter);

    // inline getters
    const int& getHp() const { return hp; }
    Headquarter* getHeadquarter() const { return hq; }

    //Our method called every frames to interact
    virtual void action(int phase) =0;

    static void chooseBestNeighbor(const Grid& decisionGrid, int x, int y, int& nextX, int& nextY);

protected:
    unsigned deathDate;
    int hp; // number of shot until it dies
    Headquarter* hq;

    // next coordinates
    int nextX;
    int nextY;

private:

};

}
#endif // Agent_HPP
