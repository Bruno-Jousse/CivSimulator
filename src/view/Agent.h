/**
 * Project Untitled
 */


#ifndef _AGENT_H
#define _AGENT_H

#include "Entity.h"
#include <QColor>
#include "../model/Agent.h"

namespace view{

class Agent: public Entity {

public:
    Agent(QColor color, int x, int y, int w, int h);
    Agent(QColor color = Qt::blue);
    virtual ~Agent()=0;

    //Method called every times the QGraphicsScene decide to advance by a frame
    void advance(int phase);

};
}
#endif //_AGENT_H
