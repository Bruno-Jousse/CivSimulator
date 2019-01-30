/**
 * Project Untitled
 */


#ifndef _RESSOURCE_H
#define _RESSOURCE_H

#include "Entity.h"
#include "QImage"

class Resource: public Entity {
protected:
    int amount;
    QImage img;

public:
    Resource(QColor color, int x, int y, int w, int h, int amount=10);
    Resource(int amount=10);
    virtual ~Resource() = 0;
    int getAmount();
    int takeRessources(int amount);
};

#endif //_RESSOURCE_H
