/**
 * Project Untitled
 */


#include "Soldier.h"

/**
 * Soldier implementation
 */

Soldier::Soldier(QColor color, int x, int y, int w, int h, int dmg, bool mustAttack, int hp, int ms, int wearMax) : Machine(color, x, y, w, h, hp, ms, wearMax), dmg(dmg), mustAttack(mustAttack){

}

Soldier::Soldier(int dmg, bool mustAttack, int hp, int ms, int wearMax) : Machine(hp, ms, wearMax), dmg(dmg), mustAttack(mustAttack){

}

void Soldier::attack(Machine&){
    return;
}

void Soldier::attack(Building&){

}

void Soldier::action(){

}


void Soldier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Machine::paint(painter, option, widget);

    painter->drawText(QRectF(mapFromParent(pos()), size), Qt::AlignHCenter, "S");
}
