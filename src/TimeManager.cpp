#include "TimeManager.h"

TimeManager::TimeManager()
{
    frame=0.0;
}

TimeManager& TimeManager::getInstance()
{
    static TimeManager instance;
    return instance;
}

void TimeManager::advance(int phase){
    if(phase == 0){
        frame+=0.01;
    }

}

float TimeManager::getFrame(){
    return frame;
}

int TimeManager::getMonth(){
    return static_cast<int>(frame);
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

void TimeManager::isNewMonth(){
    if(fmod(frame, 1) == 0.0){
        std::cout << "One more month pasted. This is the " << getMonth() << "th month.\n";
    }
}
