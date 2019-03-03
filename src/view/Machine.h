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

public:
    Machine(QColor color);
    //virtual ~Machine() = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    int getHp();
    void setHp(int hp);
    int getWear();
    void setWear(int hp);

};
}

#endif //_MACHINE_H
