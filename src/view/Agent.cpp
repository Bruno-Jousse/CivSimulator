#include "Agent.h"

/**
 * Agent implementation
 */

Agent::Agent(QColor color, int x, int y, int w, int h) : Entity(color, x, y, w, h){

}

Agent::Agent() : Entity(){

}

Agent::~Agent(){

}

void Agent::advance(int phase){
    if(phase!=0){
        action();
    }
}
