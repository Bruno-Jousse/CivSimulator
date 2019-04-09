#ifndef _RESSOURCE_H
#define _RESSOURCE_H

#include "Entity.h"
#include "QImage"

class Resource: public Entity {
protected:
    int amount;
    QImage img;

public:
    Resource(QColor color, int x, int y, int amount);
    virtual ~Resource() = 0;
    int getAmount();
    int takeResources(int amount);
    bool isEmpty() { return amount <= 0; }

};

#endif //_RESSOURCE_H
