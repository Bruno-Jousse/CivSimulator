/**
 * Project Untitled
 */


#ifndef _RESSOURCE_H
#define _RESSOURCE_H

#include "Figure.h"


class Ressource: public Figure {
protected:
    int amount;

public:
    Ressource(int amount=10, QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int getAmount();
    int takeRessources(int amount);
};

#endif //_RESSOURCE_H
