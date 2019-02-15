/**
 * Project Untitled
 */


#include "Soldier.h"

/**
 * Soldier implementation
 */
namespace view{

Soldier::Soldier(QColor color, int x, int y, int w, int h) : Machine(color){
    data = new model::Soldier(x, y, w, h);
}

void Soldier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Machine::paint(painter, option, widget);

    painter->drawText(QRectF(mapFromParent(pos()), size), Qt::AlignHCenter, "S");
}

}
