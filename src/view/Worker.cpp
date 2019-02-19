/**
 * Project Untitled
 */


#include "Worker.h"

/**
 * Worker implementation
 */
namespace view{

Worker::Worker(QColor color, int x, int y, int w, int h) : Machine(color) {
    data = new model::Worker();
}


void Worker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Machine::paint(painter, option, widget);

    painter->drawText(QRectF(mapFromParent(pos()), size), Qt::AlignHCenter,"W");
}

model::Worker Worker::getData(){
    return data;
}


}
