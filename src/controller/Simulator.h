#ifndef Simulator_HPP
#define Simulator_HPP

#include "../model/World.h"

class Simulator
{
public:
    Simulator();
    virtual ~Simulator();

    void simulateOneTurn();
    void display();
protected:

private:
    World world;
    unsigned date; // the simulator simulate the time
};

#endif // Simulator_HPP