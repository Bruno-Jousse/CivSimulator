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
    painter->drawEllipse(getQRectF());
}

int Machine::getHp(){
    return healthbar.getHp();
}

void Machine::setHp(int hp){
    healthbar.setHp(hp);
}

}
