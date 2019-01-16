/**
 * Project Untitled
 */


#include "Worker.h"

/**
 * Worker implementation
 */

Worker::Worker(int metalStockMax, bool mustMine, int hp, int ms, int wearMax, QColor color, int x, int y, int w, int h) : Machine(hp, ms, wearMax, color, x, y, w, h), metalStockMax(metalStockMax), mustMine(mustMine) {

}

void Worker::mine(Ressource&) {
}

void Worker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Machine::paint(painter, option, widget);

    painter->drawText(body, Qt::AlignHCenter,"W");
}

void Worker::action(){

}
