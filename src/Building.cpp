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

Building::Building(int hpMax, QColor color, int x, int y) : Agent(color, x, y),  healthbar(Qt::green, 0, 0, getW(), 5, hpMax, true){
    healthbar.setParentItem(this);
}

Building::~Building(){

}
