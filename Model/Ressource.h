/**
 * Project Untitled
 */


#ifndef _RESSOURCE_H
#define _RESSOURCE_H

#include "Figure.h"
#include "QImage"

class Ressource: public Figure {
protected:
    int amount;
    QImage img;

public:
    Ressource(int amount=10, QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    virtual ~Ressource() = 0;
    int getAmount();
    int takeRessources(int amount);
};

#endif //_RESSOURCE_H
