#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "QGraphicsItem"

namespace model{

class TimeManager
{
private:
    int frame;
public:
    TimeManager();
    //One month = 60 frames
    static int getFrame();
    static int getMonth();
};
}
#endif // TIMEMANAGER_H
