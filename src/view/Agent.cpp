#include "Agent.h"

/**
 * Agent implementation
 */

namespace view{

Agent::Agent(QColor color, int x, int y, int w, int h) : Entity(color, x, y, w, h){

}

Agent::Agent() : Entity(){

}

Agent::~Agent(){

}

//Method called every times the QGraphicsScene decide to advance by a frame
void Agent::advance(int phase){
    data.action(phase);
}

}

