#include "Healthbar.h"
namespace view{

Healthbar::Healthbar(QColor color, int hpMax, int x, int y, int w, int h) : Entity(color){
    data = new model::Healthbar(x, y, w, h, hpMax)
}

model::Healthbar* Healthbar::getData(){
    return data;
}

int Healthbar::getHp(){
    return data->getHp();
}

void Healthbar::setHp(int hp){
    data->setHp(hp);
}

bool Healthbar::getIsActive(){
    return isActive;
}
void Healthbar::setIsActive(bool a){
    isActive = a;
}

QRectF Healthbar::boundingRect() const{
    return getQRectF();
}

QPainterPath Healthbar::shape() const{
    return QPainterPath();
}

void Healthbar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    if(isActive){
        painter->setBrush(Qt::black);
        painter->drawRect(getQRectF());
        QRectF r = getQRectF();
        r.setWidth(r.width()*getHp()/data->getHpMax()));
        painter->setBrush(color);
        painter->drawRect(r);
    }
}

}
