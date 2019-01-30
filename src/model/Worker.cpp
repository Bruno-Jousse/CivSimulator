#include "Worker.h"

#include <cmath>

#include "../controller/RandomManager.h"

// init constant
const int Worker::STOCK_MAX = 5;
const int Worker::STARTING_HP = 5;
const int Worker::AVG_LIVING = 100;
const int Worker::STDDEV_LIVING = 10;

Worker::Worker(int x, int y, Headquarter* creator):
    Agent(x, y, (int)round(RandomManager::getInstance().getGaussian(Worker::AVG_LIVING,
    Worker::STDDEV_LIVING)), Worker::STARTING_HP, creator), stock(0)
{}

Worker::~Worker()
{}

void Worker::simulate(unsigned date)
{
    if(isDead(date)) // simulate only for living agents
        return;
    // TODO
}
