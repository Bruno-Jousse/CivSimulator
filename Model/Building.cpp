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

Building::Building(QColor color, int x, int y, int w, int h, int hp) : Agent(color, x, y, w, h),  healthbar(Qt::green, x, y, w, 5, hp, true){
}

Building::Building(int hp) : Agent(),  healthbar(Qt::green, 0, 0, 30, 5, hp, true){

}


Building::~Building(){

}

void Building::setX(int x){
    Entity::setX(x);
    healthbar.setX(x);
}

void Building::setY(int y){
    Entity::setY(y);
    healthbar.setY(y);
}

void Building::setBody(QRect b){
    Entity::setSize(b.size());
    setPos(b.topLeft());
    healthbar.setX(b.x());
    healthbar.setY(b.y());
}
