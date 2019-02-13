/**
 * Project Untitled
 */


#ifndef _SOLDIER_H
#define _SOLDIER_H

#include "Machine.h"
#include "Building.h"

namespace view{

class Soldier: public Machine {
private: 
    int dmg;
    bool mustAttack;

public:
    Soldier(QColor color, int x, int y, int w, int h, int dmg=1, bool mustAttack=false, int hp=10, int ms=1, int wearMax=10);
    Soldier(int dmg=1, bool mustAttack=false, int hp=10, int ms=1, int wearMax=10);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


};
}
#endif //_SOLDIER_H
