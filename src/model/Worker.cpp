#include "Worker.h"

// init constant
int Worker::STOCK_MAX = 5;
int Worker::STARTING_HP = 5;

Worker::Worker(int x, int y, unsigned date, Headquarter* creator):
    Agent(x, y, date, creator), hp(Worker::STARTING_HP), stock(0)
{
    // TODO : init deathDate with the PRNG following N(100, 10)
    deathDate = 100;
}

Worker::~Worker()
{}

void Worker::simulate(unsigned date)
{
    if(isDead(date)) // simulate only for living agents
        return;
    // TODO
}
