#include "Worker.h"
#include "Grid.h"

#include <cmath>

#include "../controller/RandomManager.h"
namespace model{

// init constant
const int Worker::STOCK_MAX = 5;
const int Worker::STARTING_HP = 5;
const int Worker::AVG_LIVING = 100;
const int Worker::STDDEV_LIVING = 10;

Worker::Worker(int x, int y, Headquarter* creator, unsigned currentDate):
    Agent(x, y, currentDate + (int)round(RandomManager::getInstance().getGaussian(Worker::AVG_LIVING,
    Worker::STDDEV_LIVING)), Worker::STARTING_HP, creator)
{
    health = view::FactoryViewItem::getInstance().createHealthbar(Qt::green, STARTING_HP);
}

Worker::~Worker()
{}

void Worker::simulate(unsigned date, World& world)
{
    if(isDead(date)) // simulate only for living agents
        return;

    // the AI of the worker
    willHarvest = false;
    Grid decisionGrid;
    if(stock >= STOCK_MAX)
    {
        decisionGrid =  hq->getGridAllyHeadquarter() - hq->getGridEnemies();
    }
    else if(deathDate - date == world.distanceBetween(*this, *hq) && stock!=0)
    {
        decisionGrid = hq->getGridAllyHeadquarter();
    }
    else if(world.isNextToResource(*this))
    {
        willHarvest = true;
    }
    else
    {
        double ratio = 1.0*stock/STOCK_MAX;
        decisionGrid = ratio*hq->getGridAllyHeadquarter() + (1-ratio)*hq->getGridResources()
            - hq->getGridEnemies();
    }

    if(!willHarvest)
        Agent::chooseBestNeighbor(decisionGrid, x, y, nextX, nextY);
}

void Worker::action(){

}
}
