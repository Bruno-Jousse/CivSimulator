/**
 * Project Untitled
 */


#include "Soldier.h"

/**
 * Soldier implementation
 */

Soldier::Soldier(int dmg, bool mustAttack, int hp, int ms, int wearMax, QColor color, int x, int y, int w, int h) : Machine(hp, ms, wearMax, color, x, y, w, h), dmg(dmg), mustAttack(mustAttack){

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

    painter->drawText(body, Qt::AlignHCenter, "S");
}
