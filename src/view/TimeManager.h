#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "QGraphicsItem"
#include "QPainter"
#include <string>

namespace view{

class TimeManager : QGraphicsItem
{
private:
    int frame;
    TimeManager();

public:
    static TimeManager& getInstance();
    TimeManager(TimeManager const& r) = delete;

    void advance(int phase) override;
    int getFrame();
    int getMonth();
    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
    //Draw the object
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

}
#endif // TIMEMANAGER_H
