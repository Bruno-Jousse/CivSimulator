#ifndef Worker_HPP
#define Worker_HPP

#include "Agent.h"

namespace model{

class Worker: public Agent
{
public:
    Worker() = delete;
    Worker(const Worker & copy) = delete;

    Worker(int x, int y, Headquarter* creator, unsigned currentDate);
    virtual ~Worker();

    void simulate(unsigned date, World& world) override;

    // global constants
    static const int STOCK_MAX;
    static const int STARTING_HP;
    static const int AVG_LIVING;
    static const int STDDEV_LIVING;

    void action();
protected:
    int stock;
    bool willHarvest;

private:


};
}
#endif // Worker_HPP
