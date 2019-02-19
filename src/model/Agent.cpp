#include "Agent.h"

namespace model{

Agent::Agent(int x, int y, unsigned deathDate, int hp, Headquarter* creator):
 Entity(x, y), deathDate(deathDate), hp(hp), hq(creator)
{}

Agent::~Agent()
{}

bool Agent::isDead(unsigned date)
{
    return (date>=deathDate) || (hp<=0);
}

}
