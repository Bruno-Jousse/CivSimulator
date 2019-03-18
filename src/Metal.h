/**
 * Project Untitled
 */


#ifndef _METAL_H
#define _METAL_H

#include "Resource.h"

class Metal: public Resource {
public:
    Metal(QColor color=Qt::gray, int x=0, int y=0);

    static int const AMOUNT;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

};

#endif //_METAL_H
