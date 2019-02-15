#include "Building.h"

/**
 * Building implementation
 */
namespace view{

Building::Building(QColor color, int x, int y, int w, int h) : Agent(color, x, y, w, h),  healthbar(Qt::green, 0, 0, w, 5, hp, true){
    healthbar.setParentItem(this);
}

int Building::getHp()
{
    return healthbar.getHp();
}

void Building::setHp(int value)
{
    healthbar.setHp(value);
}

Building::~Building(){

}
}
