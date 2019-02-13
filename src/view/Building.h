/**
 * Project Untitled
 */


#ifndef _BUILDING_H
#define _BUILDING_H

#include "Agent.h"
#include "Healthbar.h"

namespace view{

class Building: public Agent {
protected:
    Healthbar healthbar;

public:
    Building(QColor color, int x, int y, int w, int h, int hp=100);
    Building(int hp=100);

    virtual ~Building()=0;

    int getHp();
    void setHp(int value);
};
}
#endif //_BUILDING_H
