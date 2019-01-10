/**
 * Project Untitled
 */


#include "Worker.h"

/**
 * Worker implementation
 */

Worker::Worker(int metalStockMax, bool mustMine, int hp, int ms, int wearMax, QColor color, int x, int y, int w, int h) : metalStockMax(metalStockMax), mustMine(mustMine), Machine(hp, ms, wearMax, color, x, y, w, h) {

}

void Worker::mine(Ressource& rs) {
}

void Worker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Machine::paint(painter, option, widget);

    painter->drawText(body, Qt::AlignHCenter,"W");
}
