/**
 * Project Untitled
 */


#ifndef _SOLDIER_H
#define _SOLDIER_H

#include "Machine.h"
#include "Building.h"


class Soldier: public Machine {
private: 
    int dmg;
    bool mustAttack;
    void attack(Machine&);
    void attack(Building&);

public:
    Soldier(int dmg=1, bool mustAttack=false, int hp=10, int ms=1, int wearMax=10, QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    void action() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


};

#endif //_SOLDIER_H
