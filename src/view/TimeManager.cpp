#include "TimeManager.h"

namespace view{

TimeManager::TimeManager()
{
    frame=0;
}

TimeManager& TimeManager::getInstance()
{
    static TimeManager instance;
    return instance;
}

void TimeManager::advance(int phase){
    if(phase == 0){
        frame++;
    }

}

int TimeManager::getFrame(){
    return frame;
}

int TimeManager::getMonth(){
    return frame/60;
}

QRectF TimeManager::boundingRect() const{
    return QRectF();
}

QPainterPath TimeManager::shape() const{
    return QPainterPath();
}

void TimeManager::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::black);
    painter->drawText(QRectF(0, 0, 20, 10), Qt::AlignHCenter, QString::fromStdString("Month " + std::to_string(getMonth())) );
}

}
