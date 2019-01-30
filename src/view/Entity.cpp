#include "Entity.h"

/**
 * Figure implementation
 */

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

QPoint Entity::searchAvailablePlaceAround(Entity &r){
    QPoint pos, cmp(-1,-1);
    int tmp;
    if( (pos=searchAvailableOnLine(getX()-r.getW(), getY()-r.getH()-1, getX()+getW()+r.getW(), r)) == cmp){
        if( (pos=searchAvailableOnLine(getX()-r.getW(), getY()+getH()+1, getX()+getW()+r.getW(), r)) == cmp){
            if( (pos=searchAvailableOnLine(getY()-r.getH(), getX()-r.getW()-1, getY()+getH()+r.getH(), r)) == cmp){
                pos=searchAvailableOnLine(getY()-r.getH(), getX()+getW()+1, getY()+getH()+r.getH(), r);
                tmp = pos.x();
                pos.setX(pos.y());
                pos.setY(tmp);
            }
            else{
                tmp = pos.x();
                pos.setX(pos.y());
                pos.setY(tmp);
            }
        }
    }

    return pos;
}

QPoint Entity::searchAvailableOnLine(int xSource, int y, int xDestination, Entity &r){
    QPoint pos(-1, -1);
    bool isPlaced=false;
    r.setY(y);
    while(!isPlaced && xSource<=xDestination){
        r.setX(xSource);
        if(scene()->collidingItems(&r).isEmpty()){
            pos.setX(xSource);
            pos.setY(y);
            isPlaced=true;
        }
        xSource+=1;
    }

    return pos;
}
