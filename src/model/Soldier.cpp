#include "Soldier.h"

#include <cmath>
#include "../controller/RandomManager.h"

// init constants
const int Soldier::STARTING_HP = 10;
const int Soldier::AVG_LIVING = 150;
const int Soldier::STDDEV_LIVING = 20;
const int Soldier::RANGE_SHOOT = 3;

Soldier::Soldier(int x, int y, Headquarter* creator):
    Agent(x, y, (int)round(RandomManager::getInstance().getGaussian(Soldier::AVG_LIVING,
        Soldier::STDDEV_LIVING)), Soldier::STARTING_HP, creator)
{} // TODO : how to initialize "strategy" (random, hq, self? => probably hq)

Soldier::~Soldier()
{}

void Soldier::simulate(unsigned date)
{
    if(isDead(date)) // simulate only for living agents
        return;
    strategy->simulate(date);
}

// Nested classes strategies
Soldier::StrategySoldier::~StrategySoldier() {}
Soldier::StrategyProtection::~StrategyProtection() {}
Soldier::StrategyAttack::~StrategyAttack() {}
Soldier::StrategyKamikaze::~StrategyKamikaze() {}

void Soldier::StrategyProtection::simulate(unsigned date)
{
    // TODO : check my notes
    // move or shoot at an enemy is close enough
}
void Soldier::StrategyAttack::simulate(unsigned date)
{
    // TODO : check my notes
    // move or shoot at an enemy is close enough
}
void Soldier::StrategyKamikaze::simulate(unsigned date)
{
    // TODO : check my notes
    // move or shoot at an enemy is close enough
}