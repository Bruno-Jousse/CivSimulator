#include "Soldier.h"

#include <cmath>
#include "../controller/RandomManager.h"

namespace model{

// init constants
const int Soldier::STARTING_HP = 10;
const int Soldier::AVG_LIVING = 150;
const int Soldier::STDDEV_LIVING = 20;
const int Soldier::RANGE_SHOOT = 3;

Soldier::Soldier(int x, int y, Headquarter* creator, unsigned currentDate):
    Agent(x, y, currentDate + (int)round(RandomManager::getInstance().getGaussian(Soldier::AVG_LIVING,
        Soldier::STDDEV_LIVING)), Soldier::STARTING_HP, creator)
{
    strategy = new StrategyProtection();
}

Soldier::~Soldier()
{
    delete strategy;
}

void Soldier::defineStrategy(StrategyEnum type)
{
    delete strategy;
    switch (type)
    {
        case PROTECTION:
            strategy = new StrategyProtection();
            break;

        case ATTACK:
            strategy = new StrategyAttack();
            break;
    
        default:
            strategy = new StrategyKamikaze();
    }
}

void Soldier::simulate(unsigned date, World& world)
{
    if(isDead(date)) // simulate only for living agents
        return;
    
    attackTarget = nullptr;
    vector<Agent*> enemies = world.getAgentsTargetableBy(*this);
    if(vector.isEmpty()) // move
        strategy->simulate(date, world);
    else // shoot
    {
        Agent* weakest = enemies[0];
        for(Agent* a: enemies)
        {
            if(a->getHp() < weakest->getHp())
                weakest = a;
        }
        attackTarget = weakest;
    }
}

// Nested classes strategies
Soldier::StrategySoldier::~StrategySoldier() {}
Soldier::StrategyProtection::~StrategyProtection() {}
Soldier::StrategyAttack::~StrategyAttack() {}
Soldier::StrategyKamikaze::~StrategyKamikaze() {}

void Soldier::StrategyProtection::simulate(unsigned date, World& world)
{
    Grid decisionGrid = 0.6*hq->getGridAllyAgents() + 0.4*hq->getGridAllyHeadquarter();
    Agent::chooseBestNeighbor(decisionGrid, x, y, nextX, nextY);
}
void Soldier::StrategyAttack::simulate(unsigned date, World& world)
{
    Agent::chooseBestNeighbor(hq->getGridEnemies(), x, y, nextX, nextY);
}
void Soldier::StrategyKamikaze::simulate(unsigned date, World& world)
{
    Agent::chooseBestNeighbor(hq->getGridEnemies(), x, y, nextX, nextY);
}

void Soldier::action() 
{
}