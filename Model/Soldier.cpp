/**
 * Project Untitled
 */


#include "Soldier.h"

/**
 * Soldier implementation
 */

Soldier::Soldier(int dmg, bool mustAttack, int hp, int ms, int wearMax, QColor color, int x, int y, int w, int h) : dmg(dmg), mustAttack(mustAttack), Machine(hp, ms, wearMax, color, x, y, w, h){

}

void Soldier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Machine::paint(painter, option, widget);

    painter->drawText(x, y, w, h, Qt::AlignHCenter, tr("S"));
}


void Soldier::attack(Agent){
    return;
}
