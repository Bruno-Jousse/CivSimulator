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
    Building(QColor color, int x, int y, int w, int h, int hp=100);
    Building(int hp=100);

    virtual ~Building()=0;

    int getHp() const;
    void setHp(int value);
};

#endif //_BUILDING_H
