/**
 * Project Untitled
 */


#include "Metal.h"

/**
 * Metal implementation
 */

Metal::Metal(QColor color, int x, int y, int w, int h, int amount) : Ressource(color, x, y, w, h, amount){
    img.load(":/images/Metal_Ingot.png");
}

void Metal::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){

    painter->drawImage(body, img);
}
