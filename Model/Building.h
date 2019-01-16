/**
 * Project Untitled
 */


#ifndef _BUILDING_H
#define _BUILDING_H

#include "Agent.h"


class Building: public Agent {
protected:
    int hp;
    int hpMax;

public:
    Building(int hp=100, QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    virtual ~Building()=0;

    int getHp() const;
    void setHp(int value);
};

#endif //_BUILDING_H
