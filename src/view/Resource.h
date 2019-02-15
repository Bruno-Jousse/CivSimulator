/**
 * Project Untitled
 */


#ifndef _RESSOURCE_H
#define _RESSOURCE_H

#include "Entity.h"
#include "QImage"

namespace view{

class Resource: public Entity {
protected:
    QImage img;

public:
    Resource(int x=0, int y=0, int w=30, int h=30);
    virtual ~Resource() = 0;
    int getAmount();
};
}
#endif //_RESSOURCE_H
