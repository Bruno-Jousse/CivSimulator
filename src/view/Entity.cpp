#include "Entity.h"

/**
 * Figure implementation
 */

namespace view{

Entity::Entity(QColor color) : color(color){
    //data = new model::Entity(x, y, w, h);
    /*setX(x);
    setY(y);
    setH(h);
    setW(w);*/
}

model::Entity* Entity::getData(){
    return data;
}

void Entity::suppression(){
    if(scene()){
        scene()->removeItem(this);
     }
}

QColor Entity::getColor()
{
    return color;
}

void Entity::setColor(const QColor &value)
{
    color = value;
}

QRectF Entity::boundingRect() const{
    return getQRectF();
}

QPainterPath Entity::shape() const{
    QPainterPath path;
    path.addRect(getQRectF());
    return path;
}

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawRect(getQRectF());
}

}
