/**
 * Project Untitled
 */


#include "Machine.h"

/**
 * Machine implementation
 */
namespace view{

Machine::Machine(QColor color) : Agent(color){
    /*healthbar.setParentItem(this);
    wearbar.setParentItem(this);
    */
}


void Machine::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawEllipse(QRectF(mapFromParent(pos()), size));
}

int Machine::getHp(){
    return healthbar.getHp();
}

void Machine::setHp(int hp){
    healthbar.setHp(hp);
}

int Machine::getWear(){
    return wearbar.getHp();
}

void Machine::setWear(int hp){
    wearbar.setHp(hp);
}
}
