#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "QGraphicsItem"

namespace view{

class TimeManager : QGraphicsItem
{
private:
    model::TimeManager* tm;
    TimeManager();

public:
    static TimeManager& getInstance();
    TimeManager(TimeManager const& r) = delete;

    void advance(int phase) override;

};

}
#endif // TIMEMANAGER_H
