#include "Worker.h"

#include <cmath>

#include "../controller/RandomManager.h"

// init constant
const int Worker::STOCK_MAX = 5;
const int Worker::STARTING_HP = 5;

Worker::Worker(int x, int y, unsigned date, Headquarter* creator):
    Agent(x, y, (int)round(RandomManager::getInstance().getGaussian(100, 10)), Worker::STARTING_HP, creator), stock(0)
{}

Worker::~Worker()
{}

void Worker::simulate(unsigned date)
{
    if(isDead(date)) // simulate only for living agents
        return;
    // TODO
}
