#ifndef FACTORYVIEWITEM_H
#define FACTORYVIEWITEM_H

#include "Entity.h"
#include "Soldier.h"
#include "Worker.h"
#include "Metal.h"
#include "Headquarter.h"
#include <boost/algorithm/string.hpp>
#include "QGraphicsScene"
#include <string>

namespace view{

class FactoryViewItem
{
public:
    static FactoryViewItem& getInstance(QGraphicsScene* scene = nullptr);
    // do not use default constructors
    FactoryViewItem(FactoryViewItem const& r) = delete;

    //Entity* create(string name, QColor color, int x=0, int y=0, int w=30, int h=30);
    Worker* createWorker(QColor color, int x=0, int y=0, int w=30, int h=30);
    Headquarter* createHeadquarter(QColor color, int x=0, int y=0, int w=30, int h=30);
    Metal* createMetal(int x=0, int y=0, int w=30, int h=30);
    Soldier* createSoldier(QColor color, int x=0, int y=0, int w=30, int h=30);
    Healthbar* createHealthbar(QColor color, int hpMax, int x=0, int y=0, int w=30, int h=30);

private:
    FactoryViewItem(QGraphicsScene* scene);
    QGraphicsScene * scene;
};

}
#endif // FACTORYVIEWITEM_H
