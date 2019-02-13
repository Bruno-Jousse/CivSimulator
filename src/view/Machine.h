/**
 * Project Untitled
 */


#ifndef _MACHINE_H
#define _MACHINE_H

#include "Agent.h"
#include "Healthbar.h"

namespace view{

class Machine: public Agent {
protected:
    Healthbar healthbar;
    //Usure de la machine
    Healthbar wearbar;
    int ms;

    void moveTo(int, int);

public:
    Machine(QColor color, int x, int y, int w, int h, int hp=10, int ms=1, int wear=0);
    Machine(int hp=10, int ms=1, int wear=0);
    //virtual ~Machine() = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    int getHp();
    void setHp(int hp);
    int getWear();
    void setWear(int hp);

};
}

#endif //_MACHINE_H
