/**
 * Project Untitled
 */


#ifndef _METAL_H
#define _METAL_H

#include "Resource.h"
#include "../model/Metal.h"

namespace view{

class Metal: public Resource {
public:
    Metal(int x=0, int y=0, int w=30, int h=30);
private:
    model::Metal data;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

};
}

#endif //_METAL_H
