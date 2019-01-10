/**
 * Project Untitled
 */


#include "Machine.h"

/**
 * Machine implementation
 */

Machine::Machine(int hp, int ms, int wearMax, QColor color, int x, int y, int w, int h) : hp(hp), ms(ms), wearMax(wearMax), Agent(color, x, y, w, h){
    wear=0;
}

void Machine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(color);
    painter->drawEllipse(body);
}

/**
 * @param int
 * @param int
 * @return void
 */
void Machine::moveTo(int x, int y) {
    return;
}

int Machine::getHp(){
    return hp;
}
