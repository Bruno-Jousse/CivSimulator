#include "Agent.h"

/**
 * Agent implementation
 */

Agent::Agent(QColor color, int x, int y, int w, int h) : Figure(color, x, y, w, h){

}

Agent::~Agent(){

}


QRectF Agent::boundingRect() const{
    return QRectF();
}
QPainterPath Agent::shape() const{
    return QPainterPath();
}

void Agent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

}


/**
 * @return void
 */
void Agent::action() {
    return;
}
