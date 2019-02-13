/**
 * Project Untitled
 */


#ifndef _METAL_H
#define _METAL_H

#include "Resource.h"

namespace view{

class Metal: public Resource {
public:
    Metal(QColor color=Qt::gray, int x=0, int y=0, int w=30, int h=30, int amount=50);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

};
}

#endif //_METAL_H
