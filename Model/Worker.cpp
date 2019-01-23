/**
 * Project Untitled
 */


#include "Worker.h"

/**
 * Worker implementation
 */

Worker::Worker(QColor color, int x, int y, int w, int h, int metalStockMax, bool mustMine, int hp, int ms, int wearMax) : Machine(color, x, y, w, h, hp, ms, wearMax), metalStockMax(metalStockMax), mustMine(mustMine) {

}

Worker::Worker(int metalStockMax, bool mustMine, int hp, int ms, int wearMax) : Machine(hp, ms, wearMax), metalStockMax(metalStockMax), mustMine(mustMine) {

}

void Worker::mine(Ressource&) {
}

void Worker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Machine::paint(painter, option, widget);

    painter->drawText(body, Qt::AlignHCenter,"W");
}

void Worker::action(){

}
