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
    virtual ~Agent()=0;

    //Method called every times the QGraphicsScene decide to advance by a frame
    void advance(int phase) final;
    //Our method called every frames to interact
    virtual void action() =0;
};

#endif //_AGENT_H
