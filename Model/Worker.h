/**
 * Project Untitled
 */


#ifndef _WORKER_H
#define _WORKER_H

#include "Machine.h"
#include "Ressource.h"

class Worker: public Machine {
private:
    int metalStock;
    int metalStockMax;
    bool mustMine;


public:
    Worker(QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0, int metalStockMax=5, bool mustMine=false, int hp=5, int ms=1, int wearMax=10);
    Worker(int metalStockMax=5, bool mustMine=false, int hp=5, int ms=1, int wearMax=10);
    void action() override;
    void mine(Ressource&);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};

#endif //_WORKER_H
