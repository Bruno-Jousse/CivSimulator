#include "Simulator.h"
#include <algorithm>

using namespace std;

namespace controller{


Simulator::Simulator(): world(), date(0)
{}

Simulator::~Simulator()
{}

void Simulator::simulateOneTurn()
{
    world.simulateOneTurn(date);
    date++;
}

void Simulator::display()
{
    // TODO : call the DisplayManager
}
}
