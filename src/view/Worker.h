/**
 * Project Untitled
 */


#ifndef _WORKER_H
#define _WORKER_H

#include "Machine.h"
#include "Resource.h"
#include "../model/Worker.h"

namespace view{

class Worker: public Machine {
private:
    model::Worker* data;
    Healthbar metalStockBar;
public:
    Worker(QColor color, int x=0, int y=0, int w=30, int h=30);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    model::Worker getData();
};
}
#endif //_WORKER_H
