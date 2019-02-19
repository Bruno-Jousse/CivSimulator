#include "Agent.h"

/**
 * Agent implementation
 */

namespace view{

Agent::Agent(QColor color) : Entity (color){

}

Agent::Agent(QColor color) : Entity(color){

}

Agent::~Agent(){

}

//Method called every times the QGraphicsScene decide to advance by a frame
void Agent::advance(int phase){
    data->action(phase);
}

}

