#include "Figure.h"

/**
 * Figure implementation
 */

void Figure::suppression(){
    if(scene()){
        scene()->removeItem(this);
     }
}

QColor Figure::getColor() const
{
    return color;
}

void Figure::setColor(const QColor &value)
{
    color = value;
}

int Figure::getX() const
{
    return body.x();
}

void Figure::setX(int value)
{
    body.setX(value);
}

int Figure::getY() const
{
    return body.y();
}

void Figure::setY(int value)
{
    body.setY(value);
}

int Figure::getW() const
{
    return body.width();
}

void Figure::setW(int value)
{
    body.setWidth(value);
}

int Figure::getH() const
{
    return body.height();
}

void Figure::setH(int value)
{
    body.setHeight(value);
}

QRect Figure::getBody() const{
    return body;
}

void Figure::setBody(QRect r){
    body = r;
}

Figure::Figure(QColor color, int x, int y, int w, int h) : color(color){
    body.setX(x);
    body.setY(y);
    body.setWidth(w);
    body.setHeight(h);
}

QRectF Figure::boundingRect() const{
    return QRectF(body);
}

QPainterPath Figure::shape() const{
    QPainterPath path;
    path.addRect(body);
    return path;
}

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawRect(body);
}

pair<int, int> Figure::searchAvailablePlaceAround(Figure &r){
    pair<int, int> pos;

    if( (pos=searchAvailableOnLine(getX()-1, getY()-r.getH(), getX()+getW()+1, r)) == make_pair(-1, -1)){
        if( (pos=searchAvailableOnLine(getX()-1, getY()+getH()+1, getX()+getW()+1, r)) == make_pair(-1, -1)){
            if( (pos=searchAvailableOnLine(getY()-1, getX()-r.getW(), getY()+getH()+1, r)) == make_pair(-1, -1)){
                pos=searchAvailableOnLine(getY()-1, getX()+getW()+1, getY()+getH()+1, r);
            }
        }
    }

    return pos;
}

pair<int, int> Figure::searchAvailableOnLine(int xSource, int y, int xDestination, Figure &r){
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
