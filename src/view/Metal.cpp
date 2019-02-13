/**
 * Project Untitled
 */


#include "Metal.h"

/**
 * Metal implementation
 */
namespace view{

Metal::Metal(QColor color, int x, int y, int w, int h, int amount) : Resource(color, x, y, w, h, amount){
    img.load(":/images/Metal_Ingot.png");
    img = img.scaled(w, h, Qt::KeepAspectRatio);
}

void Metal::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){

    painter->drawImage(QRectF(mapFromParent(pos()), size), img);
}
}
