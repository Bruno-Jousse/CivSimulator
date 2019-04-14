#ifndef _BUILDING_H
#define _BUILDING_H

#include "Agent.h"
#include "Healthbar.h"

class Building: public Agent {
protected:
    Healthbar healthbar;

public:
    Building(World* w, int hpMax, QColor color, int x=0, int y=0);

    virtual ~Building()=0;

    int getHp();
    void setHp(int value);

};

#endif //_BUILDING_H
