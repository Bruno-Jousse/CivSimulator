#ifndef _WORKER_H
#define _WORKER_H

#include "Machine.h"
#include "Resource.h"

class Worker: public Machine {
private:
    Healthbar metalStockBar;
    bool willHarvest;

public:

    Worker(World* w, Headquarter* hq, QColor color, int x=0, int y=0);
    void action() override;
    void mine(Resource&);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

	// global constants
	static const int STOCK_MAX;
	static const int STARTING_HP;
	static const int AVG_LIVING;
	static const int STDDEV_LIVING;

    int getMetalAmount(){
        return metalStockBar.getHp();
    }
    void setMetalAmount(int v){
        metalStockBar.setHp(v);
    }
};

#endif //_WORKER_H