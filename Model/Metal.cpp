/**
 * Project Untitled
 */


#include "Metal.h"

/**
 * Metal implementation
 */

Metal::Metal(int amount, QColor color, int x, int y, int w, int h) : Ressource(amount, color, x, y, w, h){
    img=loadFromData(":/images/Metal_Ingot.png", 1000000);
}

Metal::~Metal(){

}

void Metal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    painter->drawImage(body, img);
}
