/**
 * Project Untitled
 */


#include "Headquarter.h"

/**
 * Headquarter implementation
 */

namespace view{


Headquarter::Headquarter(QColor color, int x, int y, int w, int h, int metalAmount, int aggressivity, int hp) : Building(color, x, y, w, h, hp), metalAmount(metalAmount), aggressivity(aggressivity){
}

Headquarter::Headquarter(int metalAmount, int aggressivity, int hp) : Building(hp), metalAmount(metalAmount), aggressivity(aggressivity){
}


void Headquarter::action(){
    if(frame%60==0){
        spawnMachine();
    }
    while(metalAmount>=10){
        createAWorker();
    }
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
