#ifndef Simulator_HPP
#define Simulator_HPP

#include "../model/World.h"

namespace controller{

class Simulator
{
public:
    Simulator();
    virtual ~Simulator();

    void simulateOneTurn();
    void display();
protected:

private:
    model::World world;
    unsigned date; // the simulator simulate the time
};

}
#endif // Simulator_HPP
