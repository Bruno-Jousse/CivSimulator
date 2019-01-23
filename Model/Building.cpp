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

Building::Building(QColor color, int x, int y, int w, int h, int hp) : Agent(color, x, y, w, h),  hp(hp){
    hpMax=hp;
}

Building::Building(int hp) : Agent(),  hp(hp){
    hpMax=hp;
}


Building::~Building(){

}
