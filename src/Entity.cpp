#include "Entity.h"

/**
 * Figure implementation
 */

const QSizeF Entity::SIZE(30, 30);
const int Entity::MODELTOVIEW = 30;

Entity::Entity(QColor color, int x, int y) : color(color){
    setXView(x);
    setYView(y);
    setSize(SIZE);
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

int Entity::getX()
{
    return pos().x() / MODELTOVIEW;
}

void Entity::setX(int value){
    setPos(value*MODELTOVIEW, pos().y());
}

void Entity::setXView(int value)
{
    setPos(value, pos().y());
    cout << "x=" << getX() << "pos().x()=" << pos().x() <<endl;
}

int Entity::getY()
{
    return pos().y() / MODELTOVIEW;
}

void Entity::setY(int value){
    setPos(pos().y(), value * MODELTOVIEW);
}

void Entity::setYView(int value)
{
    setPos(pos().x(), value);
    cout << "y=" << getY() << "pos().y()=" << pos().y() <<endl;

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
    return (int) size.height();
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

bool Entity::searchAvailablePlaceAround(Entity &r){
    bool positioned = true;

    if(!searchAvailableOnLineX(pos().x()-r.getW(), pos().y()-r.getH()-1, pos().x()+getW()+r.getW(), r)){
        if(!searchAvailableOnLineX(pos().x()-r.getW(), pos().y()+getH()+1, pos().x()+getW()+r.getW(), r)){
            if(!searchAvailableOnLineY(pos().y()-r.getH(), pos().x()-r.getW()-1, pos().y()+getH()+r.getH(), r)){
                if(!searchAvailableOnLineY(pos().y()-r.getH(), pos().x()+getW()+1, pos().y()+getH()+r.getH(), r)){
                    positioned = false;
                }
            }
        }
    }

    return positioned;
}

bool Entity::searchAvailableOnLineX(int xSource, int y, int xDestination, Entity &r){
    bool isPlaced=false;
    r.setYView(y);
    while(!isPlaced && xSource<=xDestination){
        r.setXView(xSource);
        if(scene()->collidingItems(&r).isEmpty()){
            isPlaced=true;
        }
        xSource+=30;
    }

    return isPlaced;
}

bool Entity::searchAvailableOnLineY(int ySource, int x, int yDestination, Entity &r){
    bool isPlaced=false;
    r.setXView(x);
    while(!isPlaced && ySource<=yDestination){
        r.setYView(ySource);
        if(scene()->collidingItems(&r).isEmpty()){
            isPlaced=true;
        }
        ySource+=30;
    }

    return isPlaced;
}
