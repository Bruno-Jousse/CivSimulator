#include "Entity.h"

/**
 * Figure implementation
 */

void Entity::suppression(){
    if(scene()){
        scene()->removeItem(this);
     }
}

QColor Entity::getColor() const
{
    return color;
}

void Entity::setColor(const QColor &value)
{
    color = value;
}

int Entity::getX() const
{
    return scenePos().x();
}

void Entity::setX(int value)
{
    pos().setX(value);
}

int Entity::getY() const
{
    return scenePos().y();
}

void Entity::setY(int value)
{
    pos().setY(value);
    //scenePos().setY(value);
}

int Entity::getW() const
{
    return (int) size.width();
}

void Entity::setW(int value)
{
    size.setWidth(value);
}

int Entity::getH() const
{
    return size.height();
}

void Entity::setH(int value)
{
    size.setHeight(value);
}

QSizeF Entity::getSize() const{
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

pair<int, int> Entity::searchAvailablePlaceAround(Entity &r){
    pair<int, int> pos;
    int tmp;
    if( (pos=searchAvailableOnLine(getX()-r.getW(), getY()-r.getH()-1, getX()+getW()+r.getW(), r)) == make_pair(-1, -1)){
        if( (pos=searchAvailableOnLine(getX()-r.getW(), getY()+getH()+1, getX()+getW()+r.getW(), r)) == make_pair(-1, -1)){
            if( (pos=searchAvailableOnLine(getY()-r.getH(), getX()-r.getW()-1, getY()+getH()+r.getH(), r)) == make_pair(-1, -1)){
                pos=searchAvailableOnLine(getY()-r.getH(), getX()+getW()+1, getY()+getH()+r.getH(), r);
                tmp = pos.first;
                pos.first = pos.second;
                pos.second = tmp;
            }
            else{
                tmp = pos.first;
                pos.first = pos.second;
                pos.second = tmp;
            }
        }
    }

    return pos;
}

pair<int, int> Entity::searchAvailableOnLine(int xSource, int y, int xDestination, Entity &r){
    pair<int, int> pos(make_pair(-1, -1));
    bool isPlaced=false;
    r.setY(y);
    while(!isPlaced && xSource<=xDestination){
        r.setX(xSource);
        if(scene()->collidingItems(&r).isEmpty()){
            pos.first=xSource;
            pos.second=y;
            isPlaced=true;
        }
        xSource+=1;
    }

    return pos;
}
