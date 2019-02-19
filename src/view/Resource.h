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
    Resource(int w, int h, QString path);
    virtual ~Resource() = 0;
    int getAmount();
};
}
#endif //_RESSOURCE_H
