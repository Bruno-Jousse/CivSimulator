#include "Agent.h"

/**
 * Agent implementation
 */

Agent::Agent(World* w, QColor color, int x, int y) : Entity(color, x, y), world(w){

}

Agent::~Agent(){

}

void Agent::advance(int phase){
    if(phase!=0){
        action();
    }
}
