#ifndef _ENTITY_H
#define _ENTITY_H

#include "QGraphicsItem"
#include "QGraphicsScene"
#include "QPainter"
#include "QVector"
#include "QImage"
#include <iostream>
#include "TimeManager.h"
#include "RandomManager.h"

using namespace std;

class Entity : public QGraphicsItem {
protected:
    QColor color;
    QSizeF size;

public:
    Entity(QColor color, int x=0, int y=0);
    virtual ~Entity() override{
        suppression();
    }

    //Collider
    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
    //Draw the object
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

    virtual void suppression();

    bool searchAvailablePlaceAround(Entity &r);
    bool searchAvailableOnLineX(int xSource, int y, int xDestination, Entity &r);
    bool searchAvailableOnLineY(int ySource, int x, int yDestination, Entity &r);

    QColor getColor() ;
    void setColor(const QColor &value);
    int getX();
    void setX(int value);
    void setXView(int value);
    int getY() ;
    void setY(int value);
    void setYView(int value);
    int getW() ;
    void setW(int value);
    int getH() ;
    void setH(int value);
    QSizeF getSize() ;
    void setSize(QSizeF r);

    static const QSizeF SIZE;
    static const int MODELTOVIEW;

};
#endif //_FIGURE_H
