/**
 * Project Untitled
 */


#ifndef _SOLDIER_H
#define _SOLDIER_H

#include "Machine.h"


class Soldier: public Machine {
private: 
    int dmg;
    bool mustAttack;
    void attack(Agent a);

public:
    Soldier(int dmg=1, bool mustAttack=false, int hp=10, int ms=1, int wearMax=10, QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    ~Soldier();
};

#endif //_SOLDIER_H
