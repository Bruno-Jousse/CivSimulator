/**
 * Project Untitled
 */


#include "Metal.h"

/**
 * Metal implementation
 */
namespace view{

Metal::Metal(int x, int y, int w, int h) : Resource(w, h, ":/images/Metal_Ingot.png"){

    data = new model::Metal(x, y, w, h);
}

void Metal::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){

    painter->drawImage(getQRectF()), img);
}
}
