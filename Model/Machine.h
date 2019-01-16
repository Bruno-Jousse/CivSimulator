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
    Machine(int hp=10, int ms=1, int wear=0, QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    virtual ~Machine() = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    int getHp();
};

#endif //_MACHINE_H
