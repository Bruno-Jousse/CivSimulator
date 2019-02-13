#include "Entity.h"

/**
 * Figure implementation
 */

namespace view{

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

int Entity::getX()
{
    return pos().x();
}

void Entity::setX(int value)
{
    cout << "x=" << value << endl;
    setPos(value, pos().y());
    cout << "pos().x()=" << getX()<<endl;
}

int Entity::getY()
{
    return pos().y();
}

void Entity::setY(int value)
{
    setPos(pos().x(), value);
    //scenePos().setY(value);
}

int Entity::getW()
{
    return (int) size.width();
}

void Entity::setW(int value)
{
    size.setWidth(value);
}

int Entity::getH()
{
    return size.height();
}

void Entity::setH(int value)
{
    size.setHeight(value);
}

QSizeF Entity::getSize(){
    return size;
}

void Entity::setSize(QSizeF r){
    size = r;
}

Entity::Entity(QColor color, int x, int y, int w, int h) : color(color){
    setX(x);
    setY(y);
    setH(h);
    setW(w);
}

QRectF Entity::boundingRect() const{
    return QRectF(mapFromParent(pos()), size);
}

QPainterPath Entity::shape() const{
    QPainterPath path;
    path.addRect(QRectF(mapFromParent(pos()), size));
    return path;
}

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawRect(QRectF(mapFromParent(pos()), size));
}

}
