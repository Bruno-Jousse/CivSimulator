#include "Agent.h"

Agent::Agent(int x, int y, unsigned date, Headquarter* creator): Entity(x, y), hq(creator)
{}

Agent::~Agent()
{}

bool Agent::isDead(unsigned date)
{
    return (date>=deathDate) || (hp<=0);
}