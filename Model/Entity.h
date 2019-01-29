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

using namespace std;

/****** Portée globale ******/
//One month = 60 frames
static int frame=0;

static int getMonth(){
    return static_cast<int>(frame/60);
}

/****************************/

class Entity : public QGraphicsItem {
protected:
    QColor color;
    QSizeF size;

public:
    Entity(QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=30, int h=30);
    virtual ~Entity() override{
        suppression();
    }

    //Collider
    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
    //Draw the object
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

    virtual void suppression();

    pair<int, int> searchAvailablePlaceAround(Entity &r);
    pair<int, int> searchAvailableOnLine(int xSource, int y, int xDestination, Entity &r);


    QColor getColor() const;
    void setColor(const QColor &value);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getW() const;
    void setW(int value);
    int getH() const;
    void setH(int value);
    QSizeF getSize() const;
    void setSize(QSizeF r);

};
#endif //_FIGURE_H
