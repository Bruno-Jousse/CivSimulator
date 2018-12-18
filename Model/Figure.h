/**
 * Project Untitled
 */


#ifndef _FIGURE_H
#define _FIGURE_H

#include "QGraphicsItem"

using namespace std;

class Figure : public QGraphicsItem {
protected:
    QColor color;
    int x;
    int y;
    int w;
    int h;

public:
    Figure(QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    ~Figure();
    /* To override
    virtual QRectF boundingRect() const;
    virtual QPainterPath shape() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    */
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
};

#endif //_FIGURE_H
