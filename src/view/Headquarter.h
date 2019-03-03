/**
 * Project Untitled
 */


#ifndef _HEADQUARTER_H
#define _HEADQUARTER_H

#include "Building.h"
#include "Soldier.h"
#include "Worker.h"
#include <vector>
#include "../model/Headquarter.h"

namespace view{

class Headquarter: public Building {
private: 
/*
    QVector<Soldier*> soldiers;
    QVector<Worker*> workers;
*/
    model::Headquarter* data;
    Healthbar metalStockBar;

public:
    Headquarter(QColor color, int x=0, int y=0, int w=30, int h=30);
    void suppression() override{
        Entity::suppression();
        for(int i=0; i<soldiers.size(); i++){
            soldiers.at(i)->suppression();
        }
        for(int i=0; i<workers.size(); i++){
            workers.at(i)->suppression();
        }
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};
}
#endif //_HEADQUARTER_H
