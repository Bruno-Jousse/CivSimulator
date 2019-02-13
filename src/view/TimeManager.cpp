#include "TimeManager.h"

namespace view{

TimeManager::TimeManager()
{

}

TimeManager& TimeManager::getInstance()
{
    static TimeManager instance;
    return instance;
}

}
