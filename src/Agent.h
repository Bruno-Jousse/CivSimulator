/**
 * Project Untitled
 */


#ifndef _AGENT_H
#define _AGENT_H

#include "Entity.h"
#include <QColor>

class Agent: public Entity {
public:

    Agent(QColor color, int x=0, int y=0);
    Agent();
    virtual ~Agent()=0;

    //Method called every times the QGraphicsScene decide to advance by a frame
    void advance(int phase) final;
    //Our method called every frames to interact
    virtual void action() =0;
};

#endif //_AGENT_H
