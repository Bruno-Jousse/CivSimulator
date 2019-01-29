/**
 * Project Untitled
 */


#include "Machine.h"

/**
 * Machine implementation
 */

Machine::Machine(QColor color, int x, int y, int w, int h, int hp, int ms, int wearMax) : Agent(color, x, y, w, h), healthbar(Qt::green, x, y, w, 5, hp, true), wearbar(Qt::gray, x, y+h-5, w, h, wearMax, true), ms(ms){
}

Machine::Machine(int hp, int ms, int wearMax) : Agent(), healthbar(Qt::green, 0, 0, 30, 5, hp, true), wearbar(Qt::gray, 0, 0, 30, 5, wearMax, true), ms(ms){

}


void Machine::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawEllipse(QRectF(mapFromParent(pos()), size));
}

/**
 * @param int
 * @param int
 * @return void
 */
void Machine::moveTo(int, int) {
    return;
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


void Machine::setX(int x){
    Entity::setX(x);
    healthbar.setX(x);
    wearbar.setX(x);
}

void Machine::setY(int y){
    Entity::setY(y);
    healthbar.setY(y);
    wearbar.setY(y-getH()+wearbar.getW());
}

void Machine::setBody(QRect b){
    Entity::setSize(b.size());
    setPos(b.topLeft());
    healthbar.setX(b.x());
    wearbar.setX(b.x());

    healthbar.setY(b.y());
    wearbar.setY(b.y()-getH()+wearbar.getW());
}
/*
Machine::~Machine(){

}*/
