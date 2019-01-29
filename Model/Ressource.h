/**
 * Project Untitled
 */


#ifndef _RESSOURCE_H
#define _RESSOURCE_H

#include "Entity.h"
#include "QImage"

class Ressource: public Entity {
protected:
    int amount;
    QImage img;

public:
    Ressource(QColor color, int x, int y, int w, int h, int amount=10);
    Ressource(int amount=10);
    virtual ~Ressource() = 0;
    int getAmount();
    int takeRessources(int amount);
};

#endif //_RESSOURCE_H
