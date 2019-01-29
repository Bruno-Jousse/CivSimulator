#ifndef Worker_HPP
#define Worker_HPP

#include "Agent.h"

class Worker: public Agent
{
public:
    Worker(int x, int y, unsigned date, Headquarter* creator);
    virtual ~Worker();

    void simulate(unsigned date) override;

    // global constants
    static const int STOCK_MAX;
    static const int STARTING_HP;

protected:
    int stock;

private:

};

#endif // Worker_HPP