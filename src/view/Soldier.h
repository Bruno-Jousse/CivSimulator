/**
 * Project Untitled
 */


#ifndef _SOLDIER_H
#define _SOLDIER_H

#include "Machine.h"
#include "Building.h"
#include "../model/Soldier.h"

namespace view{

class Soldier: public Machine {
private: 
    int dmg;
    bool mustAttack;

public:
    Soldier(QColor color, int x=0, int y=0, int w=30, int h=30);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


};
}
#endif //_SOLDIER_H
