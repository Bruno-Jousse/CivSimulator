#include "Building.h"

/**
 * Building implementation
 */

int Building::getHp() const
{
    return hp;
}

void Building::setHp(int value)
{
    hp = value;
}

Building::Building(int hp, QColor color, int x, int y, int w, int h) : Agent(color, x, y, w, h),  hp(hp){
    hpMax=hp;
}

Building::~Building(){

}
