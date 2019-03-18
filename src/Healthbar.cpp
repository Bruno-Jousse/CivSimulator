#include "Healthbar.h"

Healthbar::Healthbar(QColor color, int x, int y, int w, int h, int hpMax) : Entity (color, x, y), hpMax(hpMax), hp(hpMax){
    setW(w);
    setH(h);
}


int Healthbar::getHp() const{
    return hp;
}

void Healthbar::setHp(int hp){
    this->hp = hp;
}


QRectF Healthbar::boundingRect() const{
    return QRectF(QRectF(mapFromParent(pos()), size));
}

QPainterPath Healthbar::shape() const{
    return QPainterPath();
}

void Healthbar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
     painter->setBrush(Qt::black);
        painter->drawRect(QRectF(mapFromParent(pos()), size));
        QRectF r(QRectF(mapFromParent(pos()), size));
        r.setWidth(r.width()*hp/hpMax);
        painter->setBrush(color);
        painter->drawRect(r);
}

