#include "Building.h"

/**
 * Building implementation
 */
namespace view{

Building::Building(QColor color) : Agent(color){
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
