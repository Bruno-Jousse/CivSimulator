#include "Healthbar.h"
namespace view{

Healthbar::Healthbar(QColor color, int hpMax, int x, int y, int w, int h) : Entity(color){
    data = new model::Healthbar(x, y, w, h, hpMax)
}

model::Healthbar* Healthbar::getData(){
    return data;
}

int Healthbar::getHp(){
    return hp;
}

void Healthbar::setHp(int hp){
    this->hp = hp;
}

bool Healthbar::getIsActive(){
    return isActive;
}
void Healthbar::setIsActive(bool a){
    isActive = a;
}
/*
QRectF Healthbar::boundingRect() const{
    return QRectF(QRectF(mapFromParent(pos()), size));
}

QPainterPath Healthbar::shape() const{
    return QPainterPath();
}

void Healthbar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    if(isActive){
        painter->setBrush(Qt::black);
        painter->drawRect(QRectF(mapFromParent(pos()), size));
        QRect r(QRectF(mapFromParent(pos()), size));
        r.setWidth(r.width()*hp/hpMax);
        painter->setBrush(color);
        painter->drawRect(r);
    }
}
*/
}
