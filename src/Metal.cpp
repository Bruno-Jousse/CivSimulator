/**
 * Project Untitled
 */


#include "Metal.h"

/**
 * Metal implementation
 */

int const Metal::AMOUNT = 400;

Metal::Metal(QColor color, int x, int y) : Resource(color, x, y, AMOUNT){
    img.load(":/images/Metal_Ingot.png");
    img = img.scaled(getW(), getH(), Qt::KeepAspectRatio);
}

void Metal::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){

    painter->drawImage(QRectF(mapFromParent(pos()), size), img);
}
