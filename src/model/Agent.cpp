#include "Agent.h"

namespace model{

Agent::Agent(int x, int y, unsigned deathDate, int hp, Headquarter* creator):
 Entity(x, y), deathDate(deathDate), hq(creator)
{
    healthbar.setHp(hp);
}

Agent::~Agent()
{}

bool Agent::isDead(unsigned date)
{
    return (date>=deathDate) || (getHp()<=0);
}

bool Agent::doesBelongTo(Headquarter* headquarter)
{
    return headquarter == hq;
}

void Agent::chooseBestNeighbor(const Grid& decisionGrid, int x, int y, int& nextX, int& nextY)
{
    double maxValue = -1000000;
    nextX = x;
    nextY = y;

    if(decisionGrid.isInGrid(x-1, y) && decisionGrid(x-1, y) > maxValue)
    {
        maxValue = decisionGrid(x-1, y);
        nextX = x-1;
    }
    if(decisionGrid.isInGrid(x+1, y) && decisionGrid(x+1, y) > maxValue)
    {
        maxValue = decisionGrid(x+1, y);
        nextX = x+1;
    }
    if(decisionGrid.isInGrid(x, y-1) && decisionGrid(x, y-1) > maxValue)
    {
        maxValue = decisionGrid(x, y-1);
        nextX = x;
        nextY = y-1;
    }
    if(decisionGrid.isInGrid(x, y+1) && decisionGrid(x, y+1) > maxValue)
    {
        maxValue = decisionGrid(x, y+1);
        nextX = x;
        nextY = y+1;
    }
}


}
