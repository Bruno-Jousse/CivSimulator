/**
 * Project Untitled
 */


#ifndef _METAL_H
#define _METAL_H

#include "Ressource.h"

class Metal: public Ressource {
public:
    Metal(int amount=50, QColor color=Qt::gray, int x=0, int y=0, int w=0, int h=0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

};

#endif //_METAL_H
