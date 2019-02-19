#include "TimeManager.h"

namespace model{

TimeManager::TimeManager()
{
    frame = 0;
}

int TimeManager::getFrame(){
    return frame;
}
int TimeManager::getMonth(){
    return static_cast<int>(frame/60);
}
}

void TimeManager::advance(int phase){
    if(phase==0){
        frame++;
    }
}
