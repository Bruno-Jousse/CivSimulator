#include "FactoryViewItem.h"

namespace view{

Entity* create(string name, QColor color, int x, int y, int w, int h){
    Entity *e;
    switch(stoi(boost::algorithm::to_lower(name))){
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
        e = new Metal(color, x, y, w, h);
        break;
    default:
        e = nullptr;
    }
}

FactoryViewItem& FactoryViewItem::getInstance(QGraphicsScene* scene)
{
    static FactoryViewItem instance(scene);
    return instance;
}


FactoryViewItem::FactoryViewItem(QGraphicsScene* scene) : scene(scene){

}



}
