#include "Building.h"

/**
 * Building implementation
 */

int Building::getHp()
{
    return healthbar.getHp();
}

void Building::setHp(int value)
{
    healthbar.setHp(value);
}

Building::Building(World* w, int hpMax, QColor color, int x, int y) : Agent(w, color, x, y),  healthbar(Qt::green, 0, 0, getW(), 5, hpMax){
    healthbar.setParentItem(this);
}

Building::~Building(){

}
