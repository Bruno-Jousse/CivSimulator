#include "Agent.h"

/**
 * Agent implementation
 */

Agent::Agent(QColor color, int x, int y) : Entity(color, x, y){

}

Agent::~Agent(){

}

void Agent::advance(int phase){
    if(phase!=0){
        action();
    }
}
