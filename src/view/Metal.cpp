/**
 * Project Untitled
 */


#include "Metal.h"

/**
 * Metal implementation
 */
namespace view{

Metal::Metal(int x, int y, int w, int h) {
    img.load(":/images/Metal_Ingot.png");
    img = img.scaled(w, h, Qt::KeepAspectRatio);
    data = new model::Metal(x, y, w, h);
}

void Metal::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){

    painter->drawImage(QRectF(mapFromParent(pos()), size), img);
}
}
