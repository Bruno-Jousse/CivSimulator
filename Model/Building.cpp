#include "Building.h"

/**
 * Building implementation
 */

int Building::getHp() const
{
    return hp;
}

void Building::setHp(int value)
{
    hp = value;
}

Building::Building(int hp, QColor color, int x, int y, int w, int h) : hp(hp), Agent(color, x, y, w, h){
    hpMax=hp;
}

Building::~Building(){

}

QRectF Building::boundingRect() const{
    return QRectF(x, y, w, h);
}

QPainterPath Building::shape() const{
    QPainterPath qPP();
    qPP->addRect(x, y, w, h);
    return qPP;
}

void Building::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(color);
    painter->drawRect(x, y, w, h);
}
