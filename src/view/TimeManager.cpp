#include "TimeManager.h"

namespace view{

TimeManager::TimeManager()
{
    tm = new model::TimeManager();
}

TimeManager& TimeManager::getInstance()
{
    static TimeManager instance;
    return instance;
}

void TimeManager::advance(int phase){
    if(phase == 0){
        tm->setFrame(tm->getFrame()+1);
    }

}

int TimeManager::getFrame(){
    return tm->getFrame();
}

}
