#ifndef Worker_HPP
#define Worker_HPP

#include "Agent.h"

class Worker: public Agent
{
public:
    Worker() = delete;
    Worker(const Worker & copy) = delete;

    Worker(int x, int y, Headquarter* creator);
    virtual ~Worker();

    void simulate(unsigned date) override;

    // global constants
    static const int STOCK_MAX;
    static const int STARTING_HP;
    static const int AVG_LIVING;
    static const int STDDEV_LIVING;

protected:
    int stock;

private:

};

#endif // Worker_HPP