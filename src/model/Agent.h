#ifndef Agent_HPP
#define Agent_HPP

#include "Entity.h"
#include "Headquarter.h"
#include "Grid.h"
#include "../view/Healthbar.h"

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
    const int& getHp() const { return healthbar.getHp(); }
    Headquarter* getHeadquarter() const { return hq; }

    void setHealthbar(Healthbar a){ healthbar = a; }
    int getHp(){ return healthbar.getHp();}
    static void chooseBestNeighbor(const Grid& decisionGrid, int x, int y, int& nextX, int& nextY);

protected:
    unsigned deathDate;
    Headquarter* hq;
    Healthbar* healthbar;

    // next coordinates
    int nextX;
    int nextY;

private:

};

}
#endif // Agent_HPP
