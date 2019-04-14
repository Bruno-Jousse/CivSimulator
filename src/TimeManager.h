#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "QGraphicsItem"
#include "QPainter"
#include <string>
#include <iostream>
#include <cmath>

class TimeManager : QGraphicsItem
{
private:
    float frame;
    TimeManager();

public:
    static TimeManager& getInstance();
    TimeManager(TimeManager const& r) = delete;

    void advance(int phase) override;
    float getFrame();
    int getMonth();
    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
    //Draw the object
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    bool isNewMonth();

};

#endif // TIMEMANAGER_H
