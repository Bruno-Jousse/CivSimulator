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

    int metalAmount;
    int aggressivity;
    QVector<Soldier*> soldiers;
    QVector<Worker*> workers;
    //1st int is number of month to wait, 2nd int represent: 0=worker, 1=soldier
    QVector< pair<int, int> > productionLine;
    
    void createAWorker();
    void createASoldier();

public:
    Headquarter(int metalAmount=100, int aggressivity=1, int hp=100, QColor color=QColor(0,0,0,255), int x=0, int y=0, int w=0, int h=0);
    int getMetalAmount() const;
    void setMetalAmount(int value);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QVector<Soldier*> getSoldiers() const;
    QVector<Worker*> getWorkers() const;
    QVector< pair<int, int> > getProductionLine() const;

    void spawnMachine();
    void action() override;

};

#endif //_HEADQUARTER_H
