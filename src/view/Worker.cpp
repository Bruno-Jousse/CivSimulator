/**
 * Project Untitled
 */


#include "Worker.h"

/**
 * Worker implementation
 */
namespace view{

Worker::Worker(QColor color, int x, int y, int w, int h) : Machine(color) {
    data = new model::Worker(x, y, w, h);

    healthbar.getData()->setHp(data->STARTING_HP);
    healthbar.getData()->setW(w);
    data->setHealthbar(healthbar.getData());
    healthbar.setParentItem(this);

    metalStockBar = Healthbar(Qt::gray, data->STOCK_MAX, 0, h-10, w);
    data->setMetalStockBar(metalStockBar.getData());
    metalStockBar.setParentItem(this);
}


void Worker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Machine::paint(painter, option, widget);

    painter->drawText(QRectF(mapFromParent(pos()), size), Qt::AlignHCenter,"W");
}


}
