/**
 * Project Untitled
 */


#ifndef _MACHINE_H
#define _MACHINE_H

#include "Agent.h"


class Machine: public Agent {
protected:
    int hp;
    int hpMax;
    int ms;
    //Usure
    int wear;
    //Usure maximale avant destruction
    int wearMax;

public:
    Machine(int hp=10, int ms=1, int wear=0, QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    ~Machine();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
void moveTo(int, int);
};

#endif //_MACHINE_H
