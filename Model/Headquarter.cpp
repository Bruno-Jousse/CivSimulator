/**
 * Project Untitled
 */


#include "Headquarter.h"

/**
 * Headquarter implementation
 */

Headquarter::Headquarter(int aggressivity, int hp, QColor color, int x, int y, int w, int h) : aggressivity(aggressivity), Building(hp, color, x, y, w, h){

}

Headquarter::~Headquarter(){

}


/**
 * @return void
 */
int Headquarter::getMetalAmount() const
{
    return MetalAmount;
}

void Headquarter::setMetalAmount(int value)
{
    MetalAmount = value;
}

vector<Soldier> Headquarter::getSoldiers() const
{
    return soldiers;
}

vector<Worker> Headquarter::getWorkers() const
{
    return workers;
}

vector<Machine> Headquarter::getProductionLine() const
{
    return productionLine;
}

void Headquarter::workerProduction() {
    return;
}

/**
 * @return void
 */
void Headquarter::soldierProduction() {
    return;
}

/**
 * @param Machine
 * @return void
 */
void Headquarter::sendOrder(Machine m) {
    return;
}
