#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "QGraphicsItem"
#include "QPainter"
#include "Entity.h"

using namespace std;

namespace view{

class Healthbar: public Entity{
private:
    bool isActive;

public:
    Healthbar(QColor color = Qt::green, int x=0, int y=0, int w=30, int h=5, int hpMax=100, bool isActive = true);
    int getHp();
    void setHp(int);
    bool getIsActive();
    void setIsActive(bool);
/*
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
*/
};
}

#endif // HEALTHBAR_H
