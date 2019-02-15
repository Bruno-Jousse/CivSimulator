/**
 * Project Untitled
 */


#include "Headquarter.h"

/**
 * Headquarter implementation
 */

namespace view{


Headquarter::Headquarter(QColor color, int x, int y, int w, int h) : Building(color){
    data = new model::Headquarter(x, y, w, h);
}

int Headquarter::getMetalAmount() const
{
    return metalAmount;
}

void Headquarter::setMetalAmount(int value)
{
    metalAmount = value;
}

QVector<Soldier*> Headquarter::getSoldiers() const
{
    return soldiers;
}

QVector<Worker*> Headquarter::getWorkers() const
{
    return workers;
}

QVector<pair<int, int> > Headquarter::getProductionLine() const
{
    return productionLine;
}

void Headquarter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Entity::paint(painter, option, widget);
    painter->setBrush(Qt::black);
    painter->drawText(QRectF(mapFromParent(pos()), size), Qt::AlignCenter, "HQ");
}
}
