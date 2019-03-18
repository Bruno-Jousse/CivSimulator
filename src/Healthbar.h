#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "QGraphicsItem"
#include "QPainter"
#include "Entity.h"

using namespace std;

class Healthbar: public Entity{
private:

    int hpMax;
    int hp;

public:
    Healthbar(QColor color = Qt::green, int x=0, int y=0, int w=30, int h=5, int hpMax=100);
    int getHp() const;
    void setHp(int);


    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

};

#endif // HEALTHBAR_H
