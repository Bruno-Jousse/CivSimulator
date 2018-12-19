/**
 * Project Untitled
 */


#ifndef _METAL_H
#define _METAL_H

#include "Ressource.h"


class Metal: public Ressource {
public:
    Metal(int amount=50, QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    ~Metal();

private:
    QImage img;
};

#endif //_METAL_H
