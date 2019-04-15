#include "Machine.h"

Machine::Machine(World* w,Headquarter* creator, QColor color, int x, int y, int hp) : Agent(w, color, x, y), healthbar(Qt::green, 0, 0, getW(), 5, hp){
    hq = creator;
    healthbar.setParentItem(this);
}

void Machine::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawEllipse(QRectF(mapFromParent(pos()), size));
}

int Machine::getHp(){
    return healthbar.getHp();
}

void Machine::setHp(int hp){
    healthbar.setHp(hp);
}

bool Machine::isDead()
{
    return (TimeManager::getInstance().getFrame()>=deathDate) || (getHp()<=0);
}

bool Machine::doesBelongTo(Headquarter* headquarter)
{
    return headquarter == hq;
}

void Machine::chooseBestNeighbor(Grid& decisionGrid, int x, int y, int& nextX, int& nextY)
{
    double maxValue = -1000000;
    nextX = x;
    nextY = y;

    if(decisionGrid.isInGrid(x-1, y) && decisionGrid(x-1, y) > maxValue)
    {
        maxValue = decisionGrid(x-1, y);
        nextX = x-1;
    }
    if(decisionGrid.isInGrid(x+1, y) && decisionGrid(x+1, y) > maxValue)
    {
        maxValue = decisionGrid(x+1, y);
        nextX = x+1;
    }
    if(decisionGrid.isInGrid(x, y-1) && decisionGrid(x, y-1) > maxValue)
    {
        maxValue = decisionGrid(x, y-1);
        nextX = x;
        nextY = y-1;
    }
    if(decisionGrid.isInGrid(x, y+1) && decisionGrid(x, y+1) > maxValue)
    {
        maxValue = decisionGrid(x, y+1);
        nextX = x;
        nextY = y+1;
    }
}