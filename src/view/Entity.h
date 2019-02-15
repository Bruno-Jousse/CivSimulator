/**
 * Project Untitled
 */


#ifndef _FIGURE_H
#define _FIGURE_H

#include "QGraphicsItem"
#include "QGraphicsScene"
#include "QPainter"
#include "QVector"
#include "QImage"
#include <iostream>
#include "../model/Entity.h"

using namespace std;

namespace view{


class Entity : public QGraphicsItem {
protected:
    QColor color;
    model::Entity *data;
    //QSizeF size;

public:
    Entity(QColor color=QColor(0,0,0,255));
    virtual ~Entity() override{
        suppression();
    }

    //Collider
    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
    //Draw the object
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

    virtual void suppression();

    QColor getColor() ;
    void setColor(const QColor &value);
    int getX();
    void setX(int value);
    int getY() ;
    void setY(int value);
    int getW() ;
    void setW(int value);
    int getH() ;
    void setH(int value);
    QSizeF getSize() ;
    void setSize(QSizeF r);

};
}
#endif //_FIGURE_H
