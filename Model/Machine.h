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
    void moveTo(int, int);

public:
    Machine(QColor color, int x, int y, int w, int h, int hp=10, int ms=1, int wear=0);
    Machine(int hp=10, int ms=1, int wear=0);
    //virtual ~Machine() = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    int getHp();
};

#endif //_MACHINE_H
