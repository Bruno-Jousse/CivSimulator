#include "Building.h"

/**
 * Building implementation
 */
namespace view{

int Building::getHp()
{
    return healthbar.getHp();
}

void Building::setHp(int value)
{
    healthbar.setHp(value);
}

Building::Building(QColor color, int x, int y, int w, int h, int hp) : Agent(color, x, y, w, h),  healthbar(Qt::green, 0, 0, w, 5, hp, true){
    healthbar.setParentItem(this);
}

Building::Building(int hp) : Agent(),  healthbar(Qt::green, 0, 0, 30, 5, hp, true){
    healthbar.setParentItem(this);
}


Building::~Building(){

}
}
