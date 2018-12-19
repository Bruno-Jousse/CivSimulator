/**
 * Project Untitled
 */


#ifndef _HEADQUARTER_H
#define _HEADQUARTER_H

#include "Building.h"
#include "Soldier.h"
#include "Worker.h"
#include <vector>

class Headquarter: public Building {
private: 
    int MetalAmount;
    int aggressivity;
    vector<Soldier> soldiers;
    vector<Worker> workers;
    vector<Machine> productionLine;
    
    void workerProduction();
    void soldierProduction();
    void sendOrder(Machine);

public:
    Headquarter(int aggressivity=1, int hp=100, QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    ~Headquarter();
    int getMetalAmount() const;
    void setMetalAmount(int value);
    vector<Soldier> getSoldiers() const;
    vector<Worker> getWorkers() const;
    vector<Machine> getProductionLine() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};

#endif //_HEADQUARTER_H
