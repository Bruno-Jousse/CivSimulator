/**
 * Project Untitled
 */


#include "Machine.h"

/**
 * Machine implementation
 */

Machine::Machine(QColor color, int x, int y, int w, int h, int hp, int ms, int wearMax) : Agent(color, x, y, w, h), healthbar(Qt::green, 0, 0, w, 5, hp, true), wearbar(Qt::gray, 0, h-5, w, 5, wearMax, true), ms(ms){
    healthbar.setParentItem(this);
    wearbar.setParentItem(this);
}

Machine::Machine(int hp, int ms, int wearMax) : Agent(), healthbar(Qt::green, 0, 0, 30, 5, hp, true), wearbar(Qt::gray, 0, 6, 30, 5, wearMax, true), ms(ms){
    healthbar.setParentItem(this);
    wearbar.setParentItem(this);
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
