/**
 * Project Untitled
 */


#ifndef _AGENT_H
#define _AGENT_H

#include "Figure.h"
#include <QColor>

class Agent: public Figure {
public:
    Agent(QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    ~Agent();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void action();
};

#endif //_AGENT_H
