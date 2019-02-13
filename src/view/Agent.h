/**
 * Project Untitled
 */


#ifndef _AGENT_H
#define _AGENT_H

#include "Entity.h"
#include <QColor>
#include "model.Agent.h"

namespace view{

class Agent: public Entity {
private:
    model::Agent data;

public:
    Agent(QColor color, int x, int y, int w, int h);
    Agent();
    virtual ~Agent()=0;

    //Method called every times the QGraphicsScene decide to advance by a frame
    void advance(int phase);

};
}
#endif //_AGENT_H
