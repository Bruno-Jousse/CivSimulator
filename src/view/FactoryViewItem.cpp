#include "FactoryViewItem.h"

namespace view{

/*
Entity* FactoryViewItem::create(string name, QColor color, int x, int y, int w, int h){
    Entity *e;
    switch(stoi(boost::algorithm::to_lower_copy(name))){
    case stoi("worker"):
        e = new Worker(color, x, y, w, h);
        break;
    case stoi("soldier"):
        e = new Soldier(color, x, y, w, h);
        break;
    case stoi("headquarter"):
        e = new Headquarter(color, x, y, w, h);
        break;
    case stoi("metal"):
        e = new Metal(x, y, w, h);
        break;
    default:
        e = nullptr;
    }
}*/

Worker* FactoryViewItem::createWorker(QColor color, int x, int y, int w, int h){
    Worker *a = new Worker(color, x, y ,w , h);
    scene->addItem(a);
    return a;
}

Headquarter* FactoryViewItem::createHeadquarter(QColor color, int x, int y, int w, int h){
    Headquarter *a = new Headquarter(color, x, y ,w , h);
    scene->addItem(a);
    return a;
}

Metal* FactoryViewItem::createMetal(int x, int y, int w, int h){
    Metal *a = new Metal(x, y ,w , h);
    scene->addItem(a);
    return a;
}

Soldier* FactoryViewItem::createSoldier(QColor color, int x, int y, int w, int h){
    Soldier *a = new Soldier(color, x, y ,w , h);
    scene->addItem(a);
    return a;
}

Healthbar* FactoryViewItem::createHealthbar(QColor color, int hpMax, int x, int y, int w, int h){
    Healthbar *a = new Healthbar(color, hpMax, x, y ,w , h);
    //father->childItems().append(a);
    scene->addItem(a);
    return a;
}

FactoryViewItem& FactoryViewItem::getInstance(QGraphicsScene* scene)
{
    static FactoryViewItem instance(scene);
    return instance;
}


FactoryViewItem::FactoryViewItem(QGraphicsScene* scene) : scene(scene){

}



}
