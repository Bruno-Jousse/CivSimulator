/**
 * Project Untitled
 */


#ifndef _FIGURE_H
#define _FIGURE_H

#include "QGraphicsItem"
#include "QGraphicsScene"
#include "QPainter"
#include "QVector"
using namespace std;

/****** Portée globale ******/
//One month = 60 frames
static int frame=0;

int getMonth(){
    return static_cast<int>(frame/60);
}

/****************************/

class Figure : public QGraphicsItem {
protected:
    QColor color;
    QRect body;

public:
    Figure(QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    ~Figure() override;

    //Collider
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    //Draw the object
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual void suppression();
    pair<int, int> searchAvailablePlaceAround(Figure &r);
    pair<int, int> searchAvailableOnLine(int xSource, int y, int xDestination, Figure &r);


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
    QRect getBody() const;
    void setBody(QRect r);

};
#endif //_FIGURE_H