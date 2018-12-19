/**
 * Project Untitled
 */


#include "Ressource.h"

/**
 * Ressource implementation
 */

Ressource::Ressource(int amount, QColor color, int x, int y, int w, int h) : amount(amount), Figure(color, x, y, w, h){

}

Ressource::~Ressource(){

}

QRectF Ressource::boundingRect() const{
    return QRectF(x, y, w, h);
}

QPainterPath Ressource::shape() const{
    QPainterPath qPP();
    qPP->addRect(x, y, w, h);
    return qPP;
}

void Ressource::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

}
