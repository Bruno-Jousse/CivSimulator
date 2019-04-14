#include "Entity.h"

/**
 * Figure implementation
 */

const QSizeF Entity::SIZE(30, 30);
const int Entity::MODELTOVIEW = 30;

Entity::Entity(QColor color, int x, int y) : color(color){
    setXView(x);
    setYView(y);
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
    cout << "x=" << value << endl;
    setPos(value, pos().y());
    cout << "pos().x()=" << getX()<<endl;
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
    setPos(pos().y(), value);
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

QPoint Entity::searchAvailablePlaceAround(Entity &r){
    QPoint p, cmp(-1,-1);
    int tmp;
    if( (p=searchAvailableOnLine(pos().x()-r.getW(), pos().y()-r.getH()-1, pos().x()+getW()+r.getW(), r)) == cmp){
        if( (p=searchAvailableOnLine(pos().x()-r.getW(), pos().y()+getH()+1, pos().x()+getW()+r.getW(), r)) == cmp){
            if( (p=searchAvailableOnLine(pos().y()-r.getH(), pos().x()-r.getW()-1, pos().y()+getH()+r.getH(), r)) == cmp){

                p=searchAvailableOnLine(pos().y()-r.getH(), pos().x()+getW()+1, pos().y()+getH()+r.getH(), r);
                tmp = p.x();
                p.setX(p.y());
                p.setY(tmp);
            }
            else{
                tmp = p.x();
                p.setX(p.y());
                p.setY(tmp);
            }
        }
    }

    return p;
}

QPoint Entity::searchAvailableOnLine(int xSource, int y, int xDestination, Entity &r){
    QPoint pos(-1, -1);
    bool isPlaced=false;
    r.setYView(y);
    while(!isPlaced && xSource<=xDestination){
        r.setXView(xSource);
        if(scene()->collidingItems(&r).isEmpty()){
            pos.setX(xSource);
            pos.setY(y);
            isPlaced=true;
        }
        xSource+=1;
    }

    return pos;
}
