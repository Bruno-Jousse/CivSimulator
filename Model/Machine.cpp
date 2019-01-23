/**
 * Project Untitled
 */


#include "Machine.h"

/**
 * Machine implementation
 */

Machine::Machine(QColor color, int x, int y, int w, int h, int hp, int ms, int wearMax) : Agent(color, x, y, w, h), hp(hp), ms(ms), wearMax(wearMax){
    wear=0;
}

Machine::Machine(int hp, int ms, int wearMax) : Agent(), hp(hp), ms(ms), wearMax(wearMax){
    wear=0;
}


void Machine::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawEllipse(body);
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
    return hp;
}
/*
Machine::~Machine(){

}*/
