/**
 * Project Untitled
 */


#include "Worker.h"

/**
 * Worker implementation
 */

Worker::Worker(QColor color, int x, int y, int w, int h, int metalStockMax, bool mustMine, int hp, int ms, int wearMax) : Machine(color, x, y, w, h, hp, ms, wearMax), metalStockMax(metalStockMax), mustMine(mustMine) {
    metalStock = 0;
}

Worker::Worker(int metalStockMax, bool mustMine, int hp, int ms, int wearMax) : Machine(hp, ms, wearMax), metalStockMax(metalStockMax), mustMine(mustMine) {
    metalStock = 0;
}

void Worker::mine(Ressource&) {
}

void Worker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Machine::paint(painter, option, widget);

    painter->drawText(QRectF(mapFromParent(pos()), size), Qt::AlignHCenter,"W");
}

void Worker::action(){

}
